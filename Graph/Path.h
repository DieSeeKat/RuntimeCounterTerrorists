#ifndef PATH_H
#define PATH_H

#include "../Army.h"
#include "Terrain.h"
class Node;

class Path
{

  private:
  Node **end_points;
  int distance;

  public:
  void calculate_losses(Army *army);
  Node *getOppositeEnd(Node *);
  //-------------------------------------------------------------ADDED BY DHARSHAN GOPAUL
  Path();
  ~Path();
  virtual int determineNeededResources(int army_size)=0;
  virtual int determineNumDeaths(int army_size)=0;

};

#endif
