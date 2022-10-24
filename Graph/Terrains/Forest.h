#ifndef COS214PROJECT_FOREST_H
#define COS214PROJECT_FOREST_H
#include "../../Army.h"
#include "../Terrain.h"

class Forest : public Terrain
{
  public:
  ///Constructor for Forest
  Forest();
  /// Destructor for Forest

  ~Forest();
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
   * @brief Clone method for the Forest Terrain
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned Forest Terrain
   */
  Terrain *clone(std::map<void *, void *> &objmap);
};

#endif// COS214PROJECT_FOREST_H
