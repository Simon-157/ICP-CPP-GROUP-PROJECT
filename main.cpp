#include <iostream>
#include "helpers/FlightRoutes.h"
using namespace std;

int main()
{
  FlightRoutes test("ghardaia-accra.txt");
  test.getStartAndEndDetails();
  cout << "Test for flight route with pointers --------------------------------" << endl;
  unordered_map<string, Airport *> search = test.getSourceAndDestinationAirportDetails();
  // cout << search["destination"]->getName() << endl;
  Vertex *nodeP = test.getFlightRoutesByBFS(search["source"], search["destination"]);
  exit(0);

  return 0;
}
