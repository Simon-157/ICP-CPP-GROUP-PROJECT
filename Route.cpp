#include "helpers/Route.h"
#include <iostream>

Route::Route(string airlineId, string airlineCode, string sourceAirportCode, string destinationAirportCode, string destinationAirportId, int stops)
{
  this->airlineId = airlineId;
  this->airlineCode = airlineCode;
  this->sourceAirportCode = sourceAirportCode;
  this->destinationAirportCode = destinationAirportCode;
  this->destinationAirportId = destinationAirportId;
  this->codeshare = codeshare;
  this->stops = stops;
}

void Route::setAirlineId(string airlineId)
{
  this->airlineId = airlineId;
}

void Route::setAirlineCode(string airlineCode)
{
  this->airlineCode = airlineCode;
}

void Route::setSourceAirportCode(string sourceAirportCode)
{
  this->sourceAirportCode = sourceAirportCode;
}

void Route::setDestinationAirportCode(string destinationAirportCode)
{
  this->destinationAirportCode = destinationAirportCode;
}

void Route::setDestinationAirportId(string destinationAirportId)
{
  this->destinationAirportId = destinationAirportId;
}

void Route::setCodeshare(bool codeshare)
{
  this->codeshare = codeshare;
}

void Route::setStops(int stops)
{
  this->stops = stops;
}

string Route::getAirlineId()
{
  return this->airlineId;
}

string Route::getAirlineCode()
{
  return this->airlineCode;
}

string Route::getSourceAirportCode()
{
  return this->sourceAirportCode;
}

string Route::getdestinationAirportCode()
{
  return this->destinationAirportCode;
}

string Route::getdestinationAirportId()
{
  return this->destinationAirportId;
}

bool Route::getCodeshare()
{
  return this->codeshare;
}

int Route::getStops()
{
  return this->stops;
}

Route::Route()
{
}
