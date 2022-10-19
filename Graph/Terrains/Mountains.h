#ifndef MOUNTAINS_H
#define MOUNTAINS_H

#include "../../Army.h"

#include "../Terrain.h"

class Mountains : Terrain
{
  public:
  void calculate_losses(Army *army);
  Mountains();
  ~Mountains();
};

#endif
