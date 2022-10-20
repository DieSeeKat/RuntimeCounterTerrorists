#ifndef MOUNTAINS_H
#define MOUNTAINS_H

#include "../../Army.h"

#include "../Terrain.h"

class Mountains : Terrain
{
  public:
  //------------------------------------------------------ADDED BY DHARSHAN GOPAUL
  Mountains();
  ~Mountains();
  int determineNeededResources(int army_size) override;
  int determineNumDeaths(int army_size) override;
};

#endif
