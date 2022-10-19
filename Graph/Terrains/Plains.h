#ifndef PLAINS_H
#define PLAINS_H

#include "../../Army.h"

#include "../Terrain.h"

class Plains : Terrain
{
  public:
  void calculate_losses(Army *army);
  Plains();
  ~Plains();
};

#endif
