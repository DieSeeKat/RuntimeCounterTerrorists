#ifndef GUERILLAWARFARE_H
#define GUERILLAWARFARE_H

#include "../ArmyRatio.h"

#include "../Graph/Node.h"

#include "WarStylePolicy.h"

class GuerillaWarfare : public WarStylePolicy
{
  public:
  ArmyRatio createArmyRatio() override;
  GuerillaWarfare();
  ~GuerillaWarfare();
};

#endif
