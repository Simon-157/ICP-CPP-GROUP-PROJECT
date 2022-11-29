#include <iostream>
#include "helpers/FlightRoutes.h"
using namespace std;

int main()
{
  FlightRoutes test("london-dubai.txt");
  test.getStartAndEndDetails();
  cout << "Test Searching for flight route with pointers --------------------------------" << endl;
  unordered_map<string, Airport *> search = test.getSourceAndDestinationAirportDetails();
  Vertex *nodeP = test.getFlightRoutesByBFS(search["source"], search["destination"]);
  exit(0);

  return 0;
}
