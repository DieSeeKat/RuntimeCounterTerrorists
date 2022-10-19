#include "Path.h"
#include <iostream>
#include <string>
using namespace std;

Path ::Path()
{
  cout << "The Army is travelling along a path. Some units may die" << endl;
}


void Path::calculate_losses(Army *army)
{
  int resources_needed = determineNeededResources(army->getArmySize());

  int difference = army->getResource() - resources_needed;

  army->setResource(difference);

  int num_deaths = 0;

  if (army->getResource() <= 0)
  {
  }

  army->setArmySize(army->getArmySize() - num_deaths);

  if (army->getArmySize() <= 0)
  {
    cout << "The Army has perished along the path" << endl;
  }
  else
  {
    cout << "The Army has lost " << num_deaths << " units whilst along the path" << endl;
  }
}

Path ::~Path()
{
  cout << "The Army has reached its destination";
}
Node *Path::getOppositeEnd(Node *node)
{
  if (end_points[0] == node)
  {
    return end_points[1];
  }
  else
  {
    return end_points[0];
  }
}
