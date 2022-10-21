#ifndef HORSEMENWARFARE_H
#define HORSEMENWARFARE_H
#include "WarStylePolicy.h"
#include "ArmyRatio.h"
#include "Node.h"

class HorsemenWarfare : public WarStylePolicy
{
  public:
  ArmyRatio createArmyRatio() override;
  HorsemenWarfare();
  ~HorsemenWarfare();
};


#endif//HORSEMENWARFARE_H
