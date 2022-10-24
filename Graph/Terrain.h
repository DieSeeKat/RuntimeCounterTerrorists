#ifndef TERRAIN_H
#define TERRAIN_H

#include "../Army.h"
#include <map>

class Path;

class Terrain
{
  public:
  /// Constructor for Terrain

  Terrain();
  /// Destructor for Terrain

  ~Terrain();
  /**
   * @brief Calculate the number of deaths if a Army travels through the Terrain and removes those Units from the Army
   * @param army A pointer to the Army travelling through the Terrain
   */
  void calculate_losses(Army *army);
  /**
   * @brief determines the number of resources needed with respect with the army size
   * @param army_size
   * @return the number of resources needed
   */

  virtual int determineNeededResources(int army_size) = 0;
  /**
   * @brief determines the number of deaths once the resources has run out
   * @param army_size
   * @return the number of deaths
   */

  virtual int determineNumDeaths(int army_size)            = 0;
  virtual Terrain *clone(std::map<void *, void *> &objmap) = 0;
};

#endif
