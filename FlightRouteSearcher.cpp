#include "helpers/FlightRouteSearcher.h"

FlightRouteSearcher::FlightRouteSearcher()
{

  this->startCity = "";
  this->destinationCity = "";
  this->destinationCountry = "";
  this->startCountry = "";
}

void FlightRouteSearcher::setStartCity(string city)
{
  this->startCity = city;
}

void FlightRouteSearcher::setStartCountry(string country)
{
  this->startCountry = country;
}

void FlightRouteSearcher::setDestinationCity(string city)
{
  this->destinationCity = city;
}

void FlightRouteSearcher::setDestinationCountry(string country)
{
  this->destinationCountry = country;
}

void FlightRouteSearcher::setStartAirport(Airport airport)
{
  this->startAirport = airport;
}

void FlightRouteSearcher::setDestinationAirport(Airport airport)
{
  this->destinationAirport = airport;
}

string FlightRouteSearcher::getStartCity()
{
  return this->startCity;
}

string FlightRouteSearcher::getStartCountry()
{
  return this->startCountry;
}

string FlightRouteSearcher::getDestinationCity()
{
  return this->destinationCity;
}

string FlightRouteSearcher::getDestinationCountry()
{
  return this->destinationCountry;
}

Airport FlightRouteSearcher::getStartAirport()
{
  return this->startAirport;
}

Airport FlightRouteSearcher::getDestinationAirport()
{
  return this->destinationAirport;
}
