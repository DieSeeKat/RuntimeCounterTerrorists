#include "Path.h"
#include <iostream>
#include <string>
using namespace std;

Path ::Path()
{
  cout << "The Army is travelling along a path. Some units may die" << endl;
}


Path::Path(Node *first_node, Node *last_node)
{
  end_points    = new Node *[2];
  end_points[0] = first_node;
  end_points[1] = last_node;
}

void Path::calculate_losses(Army *army)
{
  terrain_type->calculate_losses(army);
}

Path ::~Path()
{
  cout << "The Army has reached its destination";
}

//------------------------------------------------------------------
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

/**
 * @todo Implement this clone
*/
Path* Path::clone(){
  return NULL;  
}

