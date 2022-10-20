#ifndef PLAINS_H
#define PLAINS_H

#include "../../Army.h"

#include "../Terrain.h"

class Plains : Terrain
{
  public:
  //------------------------------------------------------ADDED BY DHARSHAN GOPAUL
  Plains();
  ~Plains();
  int determineNeededResources(int army_size) override;
  int determineNumDeaths(int army_size) override;
};

#endif
