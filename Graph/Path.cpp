#include "Path.h"

void Path::calculate_losses(Army *army)
{
  // TODO - implement Path::calculate_losses
  throw "Not yet implemented";
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

Node** Path::getEndPoints()
{
  return end_points;
}
