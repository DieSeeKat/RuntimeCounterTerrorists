#ifndef DESERT_H
#define DESERT_H
#include "../../Army.h"
#include "../Terrain.h"

class Desert : public Terrain
{
  public:
      Desert();
      ~Desert();
      int determineNeededResources(int army_size) override;
      int determineNumDeaths(int army_size) override;
};


#endif//DESERT_H
