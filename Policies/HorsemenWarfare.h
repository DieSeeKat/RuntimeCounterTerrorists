#ifndef HORSEMENWARFARE_H
#define HORSEMENWARFARE_H
#include "ArmyRatio.h"
#include "Node.h"
#include "WarStylePolicy.h"

class HorsemenWarfare : public WarStylePolicy
{
  public:
  /**
   * @brief creates the ArmyRatio depending on the type of warfare
   * @return ArmyRatio class
   */
  ArmyRatio createArmyRatio() override;
  /// Constructor
  HorsemenWarfare();
  /// Destructor
  ~HorsemenWarfare();
};


#endif//HORSEMENWARFARE_H
