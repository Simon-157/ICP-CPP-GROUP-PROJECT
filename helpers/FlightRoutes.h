#ifndef FLIGHTROUTES_H
#define FLIGHTROUTES_H
#include <iostream>
#include <fstream>
#include <list>
#include <unordered_map>
#include <stack>
#include "Airline.h"
#include "Airport.h"
#include "Vertex.h"
#include "Route.h"
#include "FlightRouteSearcher.h"
using namespace std;

class FlightRoutes
{
public:
    FlightRoutes();
    FlightRoutes(string inputFileName);
    void getStartAndEndDetails();
    unordered_map<string, Airport *> getSourceAndDestinationAirportDetails();
    void getStartAndEndAirport();
    Airport *getAirportByIataCode(string airportCode, string airportId);
    Airline *getAirlineByIataCode(string airlineCode, string airlineId);
    list<Route *> getNeighborPaths(Airport *airport);
    Vertex *getFlightRoutesByBFS(Airport *source, Airport *destination);
    FlightRouteSearcher getRouteSearcher();
    ~FlightRoutes()
    {
        cout << "Flight routes was destructed" << endl;
    }

private:
    string inputFileName;
    string outputFileName;
    ifstream inputStream;
    ofstream outputStream;
    FlightRouteSearcher routeSearcher;
};

#endif