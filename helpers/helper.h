#include <cmath>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <list>
#include <cstdio>
#include <bits/stdc++.h>
#include <stack>
#include "FlightRoutes.h"
#include <regex>
using namespace std;

double deg2rad(double deg);
double rad2deg(double rad);
double distance(double lat1, double lon1, double lat2, double lon2, char unit);

double distance(double lat1, double lon1, double lat2, double lon2, char unit)
{
  double theta = lon1 - lon2;
  double dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
  dist = acos(dist);
  dist = rad2deg(dist);
  dist = dist * 60 * 1.1515;
  if (unit == 'K')
  {
    dist = dist * 1.609344;
  }
  else if (unit == 'N')
  {
    dist = dist * 0.8684;
  }
  return (dist);
}

double deg2rad(double deg)
{
  return (deg * M_PI / 180.0);
}

double rad2deg(double rad)
{
  return (rad * 180.0 / M_PI);
}

bool isContains(deque<Vertex *> q, Vertex *node)
{
  while (!q.empty())
  {
    if (q.front()->getAirport()->getIataCode() == node->getAirport()->getIataCode() && q.front()->getAirline()->getIataCode() == node->getAirline()->getIataCode())
    {

      cout << "ignoring insertion child is already on frontier" << endl;
      return true;
    }
    q.pop_front();
  }

  return false;
}

bool isNull(Vertex *node)
{
  if (node->getParent() == NULL)
  {
    return true;
  }
  return false;
}