#ifndef LEGIONARYWARFARE_H
#define LEGIONARYWARFARE_H
#include "ArmyRatio.h"
#include "Node.h"
#include "WarStylePolicy.h"

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
};


#endif//LEGIONARYWARFARE_H
