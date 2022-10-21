#ifndef TERRAIN_H
#define TERRAIN_H

#include "../Army.h"
#include "Path.h"
class Terrain
{
  public:

  Terrain();
  ~Terrain();
  void calculate_losses(Army *army);
  virtual int determineNeededResources(int army_size)=0;
  virtual int determineNumDeaths(int army_size)=0;
};

#endif
