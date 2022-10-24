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
  /**
   * @brief Clone method for the Snow Terrain
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned Snow Terrain
   */
  Terrain* clone(std::map<void*,void*> &objmap);
};


#endif//SNOW_H
