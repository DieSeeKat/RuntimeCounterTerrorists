#include "Path.h"
#include <iostream>
#include <string>
using namespace std;

Path ::Path()
{
  cout << "The Army is travelling along a path. Some soldiers may die " << endl;
}


void Path::calculate_losses(Army *army)
{
  int army_resource = army->getResource();
  int army_size     = army->getArmySize();
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

