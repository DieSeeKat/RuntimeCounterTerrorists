#ifndef PLAINS_H
#define PLAINS_H

#include "../../Army.h"

#include "../Terrain.h"

class Plains : public Terrain
{
  public:
  //------------------------------------------------------ADDED BY DHARSHAN GOPAUL
  Plains();
  ~Plains();
  int determineNeededResources(int army_size) override;
  int determineNumDeaths(int army_size) override;
  Terrain* clone(std::map<void*,void*> &objmap);
};

#endif
