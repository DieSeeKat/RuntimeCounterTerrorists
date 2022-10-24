#ifndef MOUNTAINS_H
#define MOUNTAINS_H

#include "../../Army.h"

#include "../Terrain.h"

class Mountains : public Terrain
{
  public:
  //------------------------------------------------------ADDED BY DHARSHAN GOPAUL
  Mountains();
  ~Mountains();
  int determineNeededResources(int army_size) override;
  int determineNumDeaths(int army_size) override;
  /**
   * @brief Clone method for the Mountains Terrain
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned Mountains Terrain
   */
  Terrain* clone(std::map<void*,void*> &objmap);
};

#endif
