#ifndef SNOW_H
#define SNOW_H
#include "../../Army.h"
#include "../Terrain.h"

class Snow : public Terrain
{
  public:
  Snow();
  ~Snow();
  int determineNeededResources(int army_size) override;
  int determineNumDeaths(int army_size) override;
  Terrain* clone(std::map<void*,void*> &objmap);
};


#endif//SNOW_H
