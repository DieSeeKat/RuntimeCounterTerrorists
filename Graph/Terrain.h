#ifndef TERRAIN_H
#define TERRAIN_H

#include "../Army.h"

class Terrain
{
  public:
  virtual void calculate_losses(Army *army) = 0;
  Terrain(){};
  ~Terrain(){};
};

#endif
