#ifndef ROUTE_H
#define ROUTE_H
#include <iostream>
using namespace std;

class Route
{
public:
    Route();
    Route(string airlineId, string airlineCode, string sourceAirportCode, string destinationAirportCode, string destinationAirportId, int stops);
    void setAirlineId(string airlineId);
    void setAirlineCode(string airlineCode);
    void setSourceAirportCode(string sourceAirportCode);
    void setDestinationAirportCode(string destinationAirportCode);
    void setDestinationAirportId(string destinationAirportId);
    void setCodeshare(bool codeshare);
    void setStops(int stops);

    string getAirlineId();
    string getAirlineCode();
    string getSourceAirportCode();
    string getdestinationAirportCode();
    string getdestinationAirportId();
    bool getCodeshare();
    int getStops();

private:
    string airlineCode;
    string airlineId;
    string sourceAirportCode;
    string destinationAirportCode;
    string destinationAirportId;
    bool codeshare;
    int stops;
};

#endif