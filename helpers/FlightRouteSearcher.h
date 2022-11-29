#ifndef FLIGHTROUTESEARCHER_H
#define FLIGHTROUTESEARCHER_H
#include <iostream>
#include "Airport.h"
using namespace std;

class FlightRouteSearcher
{
public:
    FlightRouteSearcher();
    void setStartCity(string city);
    void setStartCountry(string country);
    void setDestinationCity(string city);
    void setDestinationCountry(string country);
    void setStartAirport(Airport airport);
    void setDestinationAirport(Airport airport);

    string getStartCity();
    string getStartCountry();
    string getDestinationCity();
    string getDestinationCountry();
    Airport getStartAirport();
    Airport getDestinationAirport();

private:
    string startCity;
    string startCountry;
    string destinationCity;
    string destinationCountry;
    Airport startAirport;
    Airport destinationAirport;
};

#endif