#ifndef LEGIONARYWARFARE_H
#define LEGIONARYWARFARE_H
#include "../ArmyRatio.h"
#include "../Graph/Node.h"
#include "WarStylePolicy.h"

#include <map>
#include<string>

class LegionaryWarfare : public WarStylePolicy
{
  public:
  /**
   * @brief creates the ArmyRatio depending on the type of warfare
   * @return ArmyRatio class
   */
  ArmyRatio createArmyRatio() override;
  /// Constructor
  LegionaryWarfare();
  /// Destructor
  ~LegionaryWarfare();
  /**
   * @brief Clone method for the LegionaryWarfare Policy
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned LegionaryWarfare Policy
   */
  WarStylePolicy* clone(std::map<void*,void*> &objmap);

  std::string getWarStyleName();
};


#endif//LEGIONARYWARFARE_H
