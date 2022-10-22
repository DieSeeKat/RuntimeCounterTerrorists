#ifndef LEGIONARYWARFARE_H
#define LEGIONARYWARFARE_H
#include "../ArmyRatio.h"
#include "../Graph/Node.h"
#include "WarStylePolicy.h"

#include <map>

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
  WarStylePolicy* clone(std::map<void*,void*> &objmap);
};


#endif//LEGIONARYWARFARE_H
