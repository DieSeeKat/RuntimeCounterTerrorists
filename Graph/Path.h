#ifndef PATH_H
#define PATH_H

#include "Node.h"

#include "../Army.h"

class Path
{

  private:
  Node **end_points;
  int distance;

  public:
  void calculate_losses(Army *army);
};

#endif
