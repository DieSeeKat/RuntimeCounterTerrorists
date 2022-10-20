#ifndef TERRAIN_H
#define TERRAIN_H

#include "../Army.h"

class Terrain
{
  public:
  virtual void calculate_losses(Army *army) = 0;
  Terrain();
  ~Terrain();
  virtual int determineNeededResources(int army_size)=0;
  virtual int determineNumDeaths(int army_size)=0;
};

#endif
