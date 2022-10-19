#ifndef PLAINS_H
#define PLAINS_H

#include "../../Army.h"

#include "../Terrain.h"

class Plains : Terrain
{
  public:
  void calculate_losses(Army *army);
  //------------------------------------------------------ADDED BY DHARSHAN GOPAUL
  Plains();
  ~Plains();
  int determineNeededResources(int  army_size);
};

#endif
