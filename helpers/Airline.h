#ifndef AIRLINE_H
#define AIRLINE_H
#include <iostream>
using namespace std;

class Airline
{
public:
    Airline();
    Airline(int airlineId, string iataCode);
    Airline(int airlineId, string airlineName, string airlineAlias, string iataCode, string icaoCode, string callsign, string country, bool isActive);
    int getAirlineId();
    void setAirlineId(int airlineId);
    string getAirlineName();
    void setAirlineName(string airlineName);
    string getAirlineAlias();
    void setAirlineAlias(string airlineAlias);
    string getIataCode();
    void setIataCode(string iataCode);
    void setIcaoCode(string iataCode);
    string getIcaoCode();
    void setCallsign(string callsign);
    string getCallsign();
    void setCountry(string country);
    string getCountry();
    bool getIsActive();
    void setIsActive(bool isActive);

private:
    int airlineId;
    string airlineName;
    string airlineAlias;
    string iataCode;
    string icaoCode;
    string callsign;
    string country;
    bool isActive;
};

#endif