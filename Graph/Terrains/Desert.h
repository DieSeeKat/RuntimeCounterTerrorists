#ifndef DESERT_H
#define DESERT_H
#include "../../Army.h"
#include "../Terrain.h"

class Desert : public Terrain
{
  public:
  /// Constructor for Desert
  Desert();
  /// Destructor for Desert

  ~Desert();
  /**
   * @brief determines the number of resources needed with respect with the army size
   * @param army_size
   * @return the number of resources needed
   */

  int determineNeededResources(int army_size) override;
  /**
   * @brief determines the number of deaths once the resources has run out
   * @param army_size
   * @return the number of deaths
   */

  int determineNumDeaths(int army_size) override;
  /**
   * @brief Clone method for the Desert Terrain
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned Desert Terrain
   */
  Terrain *clone(std::map<void *, void *> &objmap);
};

#endif// DESERT_H
