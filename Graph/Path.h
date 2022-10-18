#ifndef PATH_H
#define PATH_H

#include "../Army.h"

class Node;

class Path
{

  private:
  Node **end_points;
  int distance;

  public:
  Path(Node *first_node, Node *last_node);
  void calculate_losses(Army *army);
  Node *getOppositeEnd(Node *);
};

#endif
