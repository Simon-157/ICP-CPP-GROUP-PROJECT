#include <iostream>
#include "helpers/helper.h"
#include <algorithm>
// using namespace std;

FlightRoutes::FlightRoutes()
{
}

FlightRouteSearcher FlightRoutes::getRouteSearcher()
{
	return this->routeSearcher;
}

/**
 * This function is the constructor for the FlightRoutes class
 * @param inputFileName The name of the file that contains the flight routes.
 */
FlightRoutes::FlightRoutes(string inputFileName)
{
	this->inputFileName = inputFileName;
	this->routeSearcher;
}

/**
 * It reads the first two lines of the input file and sets the start and end cities and countries
 */
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
		item.erase(remove(item.begin(), item.end(), ' '), item.end());
		result.push_back(item);
	}

	this->routeSearcher.setStartCity(result[0]);
	this->routeSearcher.setStartCountry(result[1]);
	this->routeSearcher.setDestinationCity(result[2]);
	this->routeSearcher.setDestinationCountry(result[3]);
}

/**
 * It reads the airports.csv file and returns a map of source and destination airports
 * @return A map of source and destination airports
 */
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
			line.erase(remove(line.begin(), line.end(), ' '), line.end());
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

/**
 * It takes in a string airportCode and string airportId and returns an Airport object
 * @param airportCode The IATA code of the airport.
 * @param airportId The unique identifier of the airport.
 * @return A pointer to an Airport object.
 */
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
				try
				{

					return new Airport(stoi(currentAirportId), currentAirportName, currentAirportCity, currentAirportCountry, iataCode, icaoCode, stod(latitude), stod(longitude));
				}
				catch (const std::exception &e)
				{
					cout << "Sorry Integer Conversion error" << endl;
					std::cerr << e.what() << '\n';
				}
			}
		}
	}

	return NULL;
}

/**
 * It takes in a string airlineCode and string airlineId and returns an Airline object
 *
 * @param airlineCode The IATA code of the airline.
 * @param airlineId The airline's unique OpenFlights identifier.
 *
 * @return A pointer to an Airline object.
 */
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
			line.erase(remove(line.begin(), line.end(), ' '), line.end());
			stringstream ss(line);
			getline(ss, currentAirlineId, ',');
			getline(ss, dummy, ',');
			getline(ss, dummy, ',');
			getline(ss, currentIataCode, ',');
			getline(ss, iacacode, ',');

			code = currentIataCode != " " ? currentIataCode : iacacode;

			if (currentIataCode == airlineCode || currentAirlineId == airlineId)
			{
				try
				{
					return new Airline(stoi(currentAirlineId), currentIataCode);
				}
				catch (const std::exception &e)
				{
					cout << e.what() << endl;
					std::cerr << e.what() << '\n';
				}
			}
		}
	}

	return NULL;
}

/**
 * It takes an airport as a parameter and returns a list of routes that are connected to that airport
 * @param airport The airport object that we want to find the neighbors of.
 * @return A list of routes that are connected to the airport
 */
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
				try
				{
					Route *route = new Route(Route(currentAirlineId, currentAirlineCode, currentSourceCode, currentDestinationCode, currentDestinationId, stoi(currentStops)));
					neighborRoutes.push_back(route);
				}
				catch (const std::exception &e)
				{
					cout << "invalid conversion to int: " << currentStops << endl;
					std::cerr << e.what() << '\n';
				}
			}
		}
	}
	return neighborRoutes;
}

/**
 * The function takes in a source and destination airport and returns a vertex that contains the path
 * from the source to the destination
 * @param source The starting airport
 * @param destination The destination airport
 * @return A Vertex object
 */
Vertex *FlightRoutes::getFlightRoutesByBFS(Airport *source, Airport *destination)
{
	string filen = this->getRouteSearcher().getStartCity() + "-" + this->getRouteSearcher().getDestinationCity();
	cout << "destination code: " << destination->getIataCode() << endl;
	deque<Vertex *> frontier;
	frontier.push_back(new Vertex(source));
	unordered_set<string> nullRoutes;
	unordered_set<string> explored;
	while (!frontier.empty())
	{
		Vertex *current = frontier.front();
		frontier.pop_front();
		if (current->getAirport()->getIataCode() == destination->getIataCode())
		{
			cout << "Found solution ! " << endl;
			cout << current->getAirport()->getName() << endl;
			transform(filen.begin(), filen.end(), filen.begin(), ::tolower);
			current->writeToFile(filen);
			return current;
		}
		if (!frontier.empty() && current->getAirport() == nullptr)
		{
			cout << "A node is null" << endl;
			return NULL;
		}

		cout << "popped  node " << current->getAirport()->getName() << endl;
		explored.insert(current->getAirport()->getIataCode());
		for (Route *route : getNeighborPaths(current->getAirport()))
		{
			try
			{
				// if (route != NULL)
				// {
				Airport *neighborFlight = getAirportByIataCode(route->getdestinationAirportCode(),
																			  route->getdestinationAirportId());
				Airline *neighborAirline = getAirlineByIataCode(route->getAirlineCode(), route->getAirlineId());
				Vertex *child = new Vertex(current, neighborFlight, neighborAirline, route->getStops());
				if (route->getdestinationAirportCode() == destination->getIataCode())
				{

					cout << "Found solution ! " << endl;
					cout << child->getAirport()->getName() << endl;
					transform(filen.begin(), filen.end(), filen.begin(), ::tolower);
					child->writeToFile(filen);

					return child;
				}

				if (!contains(child, frontier) || explored.find(child->getAirport()->getIataCode()) == explored.end())
				{
					frontier.push_back(child);
				}
			}
			catch (const exception &e)
			{
				cout << "error finding path to destination" << endl;
				cerr << e.what() << '\n';
			}
		}
		cout << "a cycle ends" << endl;
	}

	cout << "Sorry no solution was found" << endl;
	return NULL;
}