#include "Path.h"

Path::Path(Node *first_node, Node *last_node)
{
  end_points    = new Node *[2];
  end_points[0] = first_node;
  end_points[1] = last_node;
}

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

/**
 * @todo Implement this clone
*/
Path* Path::clone(){
  return NULL;  
}