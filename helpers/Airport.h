#ifndef AIRPORT_H
#define AIRPORT_H
#include <iostream>
using namespace std;

class Airport
{
public:
    Airport();
    Airport(int airportId, string name, string city, string country, string iataCode, string icaoCode);
    Airport(int airportId, string name, string city, string country, string iataCode, string icaoCode, double latitude, double longitude);
    // setters
    void setAirport(int airportId);
    void setName(string name);
    void setCity(string city);
    void setCountry(string country);
    void setIataCode(string iataCode);
    void seticaoCode(string iataCode);
    void setLatitude(double latitude);
    void setLongitude(double longitude);

    int getAirportId();
    string getName();
    string getCity();
    string getCountry();
    string getIataCode();
    string geticaoCode();
    double getLatitude();
    double getLongitude();

private:
    int airportId;
    string name;
    string city;
    string country;
    string iataCode;
    string icaoCode;
    double latitude;
    double longitude;
};

#endif