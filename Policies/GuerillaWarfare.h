#ifndef GUERILLAWARFARE_H
#define GUERILLAWARFARE_H

#include "../ArmyRatio.h"

#include "../Graph/Node.h"

#include "WarStylePolicy.h"

class GuerillaWarfare : public WarStylePolicy
{
  public:
  /**
   * @brief creates the ArmyRatio depending on the type of warfare
   * @return ArmyRatio class
   */
  ArmyRatio createArmyRatio() override;
  /// Constructor
  GuerillaWarfare();
  /// Destructor
  ~GuerillaWarfare();
};

#endif
