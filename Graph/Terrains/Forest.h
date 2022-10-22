#ifndef COS214PROJECT_FOREST_H
#define COS214PROJECT_FOREST_H
#include "../../Army.h"
#include "../Terrain.h"

class Forest :public Terrain
{
  public:
      Forest();
      ~Forest();
      int determineNeededResources(int army_size) override;
      int determineNumDeaths(int army_size) override;
      Terrain* clone(std::map<void*,void*> &objmap);
};


#endif//COS214PROJECT_FOREST_H
