#ifndef VERTEX_H
#define VERTEX_H
#include <string>
#include "airline.h"
#include "airport.h"
#include <stack>
using namespace std;

class Vertex
{
private:
   Vertex *parent;
   Airport *airport;
   Airline *airline;
   int stops;
   double distance;

public:
   Vertex(Vertex *parent, Airport *airport, Airline *airline, int stops);
   Vertex(Airport *airport);
   Vertex *getParent();
   Airport *getAirport();
   Airline *getAirline();
   double getDistance();
   stack<Vertex *> getSolutionPath();
   void writeToFile(string filename);
   int getStops();
   bool operator==(Vertex *node)
   {
      if (this->airport->getIataCode() == node->getAirport()->getIataCode())
      {
         return true;
      }
      return false;
   }

   operator string()
   {
      return "{Node with airline" + airline->getAirlineName() + " iatacode = " + airport->getIataCode() + " airport id = " + to_string(airport->getAirportId()) + "}";
   }
};
#endif