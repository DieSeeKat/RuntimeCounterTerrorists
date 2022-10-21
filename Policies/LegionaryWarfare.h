#ifndef LEGIONARYWARFARE_H
#define LEGIONARYWARFARE_H
#include "WarStylePolicy.h"
#include "ArmyRatio.h"
#include "Node.h"

class LegionaryWarfare : public WarStylePolicy
{
  public:
  ArmyRatio createArmyRatio() override;
  LegionaryWarfare();
  ~LegionaryWarfare();
};


#endif//LEGIONARYWARFARE_H
