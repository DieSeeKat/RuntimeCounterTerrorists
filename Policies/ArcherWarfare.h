#ifndef ARCHERWARFARE_H
#define ARCHERWARFARE_H

#include <map>

#include "../ArmyRatio.h"
#include "../Graph/Node.h"
#include "WarStylePolicy.h"

class ArcherWarfare : public WarStylePolicy
{
  public:
  /**
   * @brief creates the ArmyRatio depending on the type of warfare
   * @return ArmyRatio class
   */
  ArmyRatio createArmyRatio() override;
  /// Constructor
  ArcherWarfare();
  /// Destructor
  ~ArcherWarfare();
  /**
   * @brief Clone method for the ArcherWarfare Policy
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned ArcherWarfare Policy
   */
  WarStylePolicy* clone(std::map<void*,void*> &objmap);
};


#endif//ARCHERWARFARE_H
