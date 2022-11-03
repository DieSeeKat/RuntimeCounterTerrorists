#ifndef WARSTYLEPOLICY_H
#define WARSTYLEPOLICY_H

#include "../ArmyRatio.h"
#include <map>
#include<string>

class WarStylePolicy {
public:
  /**
   * @brief creates the ArmyRatio depending on the type of warfare
   * @return ArmyRatio class
   */
  virtual ArmyRatio createArmyRatio() = 0;
  /// Constructor
  WarStylePolicy();
  /// Destructor
  ~WarStylePolicy();
  /**
   * @brief Clone method for the WarStylePolicy
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned WarStylePolicy
   */
  virtual WarStylePolicy *clone(std::map<void *, void *> &objmap) = 0;

  virtual std::string getWarStyleName() = 0;
};

#endif
