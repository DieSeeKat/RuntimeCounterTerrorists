#ifndef MOUNTAINS_H
#define MOUNTAINS_H

#include "../../Army.h"

#include "../Terrain.h"

class Mountains : public Terrain
{
  public:
  /// Constructor for Mountain
  Mountains();
  /// Destructor for Mountain

  ~Mountains();
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
   * @brief Clone method for the Mountains Terrain
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned Mountains Terrain
   */
  Terrain *clone(std::map<void *, void *> &objmap);
};

#endif
