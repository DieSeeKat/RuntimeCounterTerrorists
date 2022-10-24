#ifndef DESERT_H
#define DESERT_H
#include "../../Army.h"
#include "../Terrain.h"

class Desert : public Terrain {
public:
  Desert();
  ~Desert();
  int determineNeededResources(int army_size) override;
  int determineNumDeaths(int army_size) override;
  /**
   * @brief Clone method for the Desert Terrain
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned Desert Terrain
   */
  Terrain *clone(std::map<void *, void *> &objmap);
};

#endif // DESERT_H
