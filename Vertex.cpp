#include "helpers/Vertex.h"
#include <stack>
#include <iostream>
#include <fstream>

Vertex::Vertex(Vertex *parent, Airport *airport, Airline *airline, int stops)
{
   this->parent = parent;
   this->airport = airport;
   this->airline = airline;
   this->stops = stops;
}
Vertex::Vertex(Airport *airport)
{
   this->airport = airport;
   this->parent = NULL;
   this->airline = NULL;
   this->stops = 0;
}

int Vertex::getStops()
{
   return stops;
};

Airport *Vertex::getAirport()
{
   return airport;
}

Airline *Vertex::getAirline()
{
   return airline;
}

Vertex *Vertex::getParent()
{
   return parent;
}

stack<Vertex *> Vertex::getSolutionPath()
{
   Vertex *currentVertex = this;
   stack<Vertex *> soln;
   while (currentVertex != NULL)
   {
      soln.push(currentVertex);
      currentVertex = currentVertex->getParent();
   }
   return soln;
}

void Vertex::writeToFile(string filename)
{
   cout << "------------" << endl
        << "wait while program outputs result to file" << endl;
   stack<Vertex *> results = this->getSolutionPath();
   ofstream outputfile("outputs/" + filename + "_output.txt");
   int totalFlights = results.size() - 1;
   int index = 0;
   int totalStops = 0;
   if (outputfile.is_open())
   {
      while (!results.empty())
      {
         Vertex *vertex = results.top();
         totalStops = totalStops + vertex->getStops();
         results.pop();
         if (vertex->getParent() != NULL)
         {
            if (vertex->getAirline() != NULL)
            {
               outputfile << index << ". " << vertex->getAirline()->getIataCode() << " from " << vertex->getParent()->getAirport()->getIataCode() << " to " << vertex->getAirport()->getIataCode() << "\n";
            }
            else
            {
               outputfile << index << ". "
                          << "N/A"
                          << " from " << vertex->getParent()->getAirport()->getIataCode() << " to " << vertex->getAirport()->getIataCode() << " " << vertex->getStops() + " stops "
                          << "\n";
            }
         }

         index += 1;
      }

      outputfile << "Total flights: " << to_string(totalFlights) << endl;
      outputfile << "Total additional stops: " + to_string(totalStops) << endl;
      outputfile << "Optimality Criteria: Flights" << endl;
      outputfile.close();
   }
   else
      cout << "file not found, couldnt write to file" << endl;
   cout << ".............." << endl
        << "Success writing to file" << endl;
}
