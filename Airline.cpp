#include "helpers/Airline.h"

Airline::Airline()
{
}

Airline::Airline(int airlineId, string iataCode)
{
  this->airlineId = airlineId;
  this->iataCode = iataCode;
}

Airline::Airline(int airlineId, string airlineName, string airlineAlias, string iataCode, string icaoCode, string callsign, string country, bool isActive)
{
  this->airlineId = airlineId;
  this->airlineName = airlineName;
  this->airlineAlias = airlineAlias;
  this->iataCode = iataCode;
  this->icaoCode = icaoCode;
  this->callsign = callsign;
  this->country = country;
  this->isActive = isActive;
}

int Airline::getAirlineId()
{
  return this->airlineId;
}

void Airline::setAirlineId(int airlineId)
{
  this->airlineId = airlineId;
}

string Airline::getAirlineName()
{
  return this->airlineName;
}

void Airline::setAirlineName(string airlineName)
{
  this->airlineName = airlineName;
}

string Airline::getAirlineAlias()
{
  return this->airlineAlias;
}

void Airline::setAirlineAlias(string airlineAlias)
{
  this->airlineAlias = airlineAlias;
}

string Airline::getIataCode()
{
  return this->iataCode;
}

void Airline::setIataCode(string iataCode)
{
  this->iataCode = iataCode;
}

void Airline::setIcaoCode(string iataCode)
{
  this->iataCode = iataCode;
}

string Airline::getIcaoCode()
{
  return this->icaoCode;
}

void Airline::setCallsign(string callsign)
{
  this->callsign = callsign;
}

string Airline::getCallsign()
{
  return this->callsign;
}

void Airline::setCountry(string country)
{
  this->country = country;
}

string Airline::getCountry()
{
  return this->country;
}

bool Airline::getIsActive()
{
  return this->isActive;
}

void Airline::setIsActive(bool isActive)
{
  this->isActive = isActive;
}
