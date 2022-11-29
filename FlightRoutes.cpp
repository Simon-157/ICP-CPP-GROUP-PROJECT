#include <iostream>
#include "helpers/helper.h"
// using namespace std;

FlightRoutes::FlightRoutes()
{
}

FlightRouteSearcher FlightRoutes::getRouteSearcher()
{
	return this->routeSearcher;
}

FlightRoutes::FlightRoutes(string inputFileName)
{
	this->inputFileName = inputFileName;
	this->routeSearcher;
}

void FlightRoutes::getStartAndEndDetails()
{

	this->inputStream.open(this->inputFileName.c_str(), ios::in);
	string sourceData;
	string destinationData;
	if (inputStream.is_open())
	{
		getline(inputStream, sourceData);
		getline(inputStream, destinationData);
		inputStream.close();
	}
	else
		cout << "Couldn't open the file\n";

	vector<string> result;
	stringstream ss(sourceData + "," + destinationData);
	string item;

	while (getline(ss, item, ','))
	{
		result.push_back(item);
	}
	this->routeSearcher.setStartCity(result[0]);
	this->routeSearcher.setStartCountry(result[1]);
	this->routeSearcher.setDestinationCity(result[2]);
	this->routeSearcher.setDestinationCountry(result[3]);
}

unordered_map<string, Airport *> FlightRoutes::getSourceAndDestinationAirportDetails()
{
	unordered_map<string, Airport *> SourceEndAirports;
	ifstream airportsData;
	airportsData.open("utils/airports.csv", ios::in);
	regex reg(",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)");
	string line, currentAirportId, currentAirportName, currentAirportCity, currentAirportCountry, iataCode, icaoCode, latitude, longitude;
	if (airportsData.is_open())
	{
		// cout << "file is opened" << endl;
		while (getline(airportsData, line))
		{
			stringstream ss(line);
			getline(ss, currentAirportId, ',');
			getline(ss, currentAirportName, ',');
			getline(ss, currentAirportCity, ',');
			getline(ss, currentAirportCountry, ',');
			getline(ss, iataCode, ',');
			getline(ss, icaoCode, ',');
			getline(ss, latitude, ',');
			getline(ss, longitude, ',');

			if (currentAirportCountry == this->routeSearcher.getStartCountry() && currentAirportCity == this->routeSearcher.getStartCity())
			{
				SourceEndAirports["source"] = new Airport(stoi(currentAirportId), currentAirportName, currentAirportCity, currentAirportCountry, iataCode, icaoCode, stod(latitude), stod(longitude));
			}

			if (currentAirportCountry == this->routeSearcher.getDestinationCountry() && currentAirportCity == this->routeSearcher.getDestinationCity())
			{
				SourceEndAirports["destination"] = new Airport(stoi(currentAirportId), currentAirportName, currentAirportCity, currentAirportCountry, iataCode, icaoCode, stod(latitude), stod(longitude));
			}
		}
		airportsData.close();
	}
	else
		cout << "Couldn't open the file\n";

	return SourceEndAirports;
}

Airport *FlightRoutes::getAirportByIataCode(string airportCode, string airportId)
{

	ifstream airportsData;
	airportsData.open("utils/airports.csv", ios::in);
	regex reg(",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)");
	string line, currentAirportId, dummy, currentAirportName, currentAirportCity, currentAirportCountry, iataCode, icaoCode, latitude, longitude;
	if (airportsData.is_open())
	{
		while (getline(airportsData, line))
		{
			stringstream ss(line);
			getline(ss, currentAirportId, ',');
			getline(ss, currentAirportName, ',');
			getline(ss, currentAirportCity, ',');
			getline(ss, currentAirportCountry, ',');
			getline(ss, iataCode, ',');
			getline(ss, icaoCode, ',');
			getline(ss, latitude, ',');
			getline(ss, longitude, ',');

			if (iataCode == airportCode || currentAirportId == airportId)
			{
				return new Airport(stoi(currentAirportId), currentAirportName, currentAirportCity, currentAirportCountry, iataCode, icaoCode, stod(latitude), stod(longitude));
			}
		}
	}

	return nullptr;
}

Airline *FlightRoutes::getAirlineByIataCode(string airlineCode, string airlineId)
{

	ifstream airlineData;
	airlineData.open("utils/airlines.csv", ios::in);
	regex reg(",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)");
	string line, currentAirlineId, currentIataCode, dummy, code, iacacode;
	if (airlineData.is_open())
	{
		while (getline(airlineData, line))
		{
			stringstream ss(line);
			getline(ss, currentAirlineId, ',');
			getline(ss, dummy, ',');
			getline(ss, dummy, ',');
			getline(ss, currentIataCode, ',');
			getline(ss, iacacode, ',');

			code = currentIataCode != " " ? currentIataCode : iacacode;

			if (code == airlineCode || currentAirlineId == airlineId)
			{
				return new Airline(stoi(currentAirlineId), code);
			}
		}
	}

	return nullptr;
}

list<Route *> FlightRoutes::getNeighborPaths(Airport *airport)
{
	list<Route *> neighborRoutes;
	ifstream routesData;
	routesData.open("utils/routes.csv", ios::in);
	regex reg(",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)");
	string line, currentAirlineCode, currentAirlineId, Equipment, currentSourceId, currentSourceCode, currentDestinationCode, currentDestinationId, codeshare, currentStops;
	if (routesData.is_open())
	{
		while (getline(routesData, line))
		{
			stringstream ss(line);
			getline(ss, currentAirlineCode, ',');
			getline(ss, currentAirlineId, ',');
			getline(ss, currentSourceCode, ',');
			getline(ss, currentSourceId, ',');
			getline(ss, currentDestinationCode, ',');
			getline(ss, currentDestinationId, ',');
			getline(ss, codeshare, ',');
			getline(ss, currentStops, ',');
			getline(ss, Equipment, ',');

			if (airport->getIataCode() == currentSourceCode || airport->getIataCode() == currentSourceId)
			{
				neighborRoutes.push_back(new Route(currentAirlineId, currentAirlineCode, currentSourceCode, currentDestinationCode, currentDestinationId, stoi(currentStops)));
			}
		}
	}
	return neighborRoutes;
}

Vertex *FlightRoutes::getFlightRoutesByBFS(Airport *source, Airport *destination)
{
	cout << "destination code: " << destination->getIataCode() << endl;
	deque<Vertex *> frontier;
	frontier.push_back(new Vertex(source));
	unordered_set<string> nullRoutes;
	unordered_set<string> explored;
	while (!frontier.empty())
	{
		Vertex *current = frontier.front();
		frontier.pop_front();
		explored.insert(current->getAirport()->getIataCode());
		cout << "popped  node " << current->getAirport()->getName() << endl;
		for (Route *route : getNeighborPaths(current->getAirport()))
		{
			try
			{
				if (route != NULL)
				{
					Airport *neighborFlight = getAirportByIataCode(route->getdestinationAirportCode(),
																				  route->getdestinationAirportId());
					Airline *neighborAirline = getAirlineByIataCode(route->getAirlineCode(), route->getAirlineId());
					Vertex *child = new Vertex(current, neighborFlight, neighborAirline, route->getStops());
					if (route->getdestinationAirportCode() == destination->getIataCode())
					{

						cout << "Found solution ! " << endl;
						cout << child->getAirport()->getName() << endl;
						string filen = this->getRouteSearcher().getStartCity() + "-" + this->getRouteSearcher().getDestinationCity();
						transform(filen.begin(), filen.end(), filen.begin(), ::tolower);
						child->writeToFile(filen);

						return child;
					}

					if (explored.find(child->getAirport()->getIataCode()) == explored.end() && !isContains(frontier, child))
					{
						cout << "Here ended" << endl;
						frontier.push_back(child);
					}
				}
			}
			catch (const exception &e)
			{
				
				cerr << e.what() << '\n';
			}
		}
		cout << "a cycle ends" << endl;
	}

	cout << "Sorry no solution was found" << endl;
	return nullptr;
}
