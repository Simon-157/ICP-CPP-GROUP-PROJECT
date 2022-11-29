#include "helpers/Airport.h"

Airport::Airport()
{
  this->airportId;
  this->name;
  this->city;
  this->country;
  this->iataCode;
  this->icaoCode;
  this->latitude;
  this->longitude;
}

Airport::Airport(int airportId, string name, string city, string country, string iataCode, string icaoCode)
{
  this->airportId = airportId;
  this->name = name;
  this->city = city;
  this->country = country;
  this->iataCode = iataCode;
  this->icaoCode = iataCode;
}

Airport::Airport(int airportId, string name, string city, string country, string iataCode, string icaoCode, double latitude, double longitude)
{
  this->airportId = airportId;
  this->name = name;
  this->city = city;
  this->country = country;
  this->iataCode = iataCode;
  this->icaoCode = iataCode;
  this->latitude = latitude;
  this->longitude = longitude;
}

void Airport::setAirport(int airportId)
{
  this->airportId = airportId;
}

void Airport::setName(string name)
{
  this->name = name;
}

void Airport::setCity(string city)
{
  this->city = city;
}

void Airport::setCountry(string country)
{
  this->country = country;
}

void Airport::setIataCode(string iataCode)
{
  this->iataCode = iataCode;
}

void Airport::seticaoCode(string icao)
{
  this->icaoCode = icao;
}

void Airport::setLatitude(double latitude)
{
  this->latitude = latitude;
}

void Airport::setLongitude(double longitude)
{
  this->longitude = longitude;
}

int Airport::getAirportId()
{
  return this->airportId;
}

string Airport::getName()
{
  return this->name;
}

string Airport::getCity()
{
  return this->city;
}

string Airport::getCountry()
{
  return this->country;
}

string Airport::getIataCode()
{
  return this->iataCode;
}

string Airport::geticaoCode()
{
  return this->icaoCode;
}

double Airport::getLatitude()
{
  return this->latitude;
}

double Airport::getLongitude()
{
  return this->longitude;
}
