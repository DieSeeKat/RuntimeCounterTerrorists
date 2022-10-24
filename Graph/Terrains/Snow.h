#ifndef SNOW_H
#define SNOW_H
#include "../../Army.h"
#include "../Terrain.h"

class Snow : public Terrain
{
  public:
  /// Constructor for Snow
  Snow();
  /// Destructor for Snow

  ~Snow();
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
   * @brief Clone method for the Snow Terrain
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned Snow Terrain
   */
  Terrain *clone(std::map<void *, void *> &objmap);
};


#endif//SNOW_H
