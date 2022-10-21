#ifndef ARCHERWARFARE_H
#define ARCHERWARFARE_H
#include "WarStylePolicy.h"
#include "ArmyRatio.h"
#include "Node.h"

class ArcherWarfare : public WarStylePolicy
{
  public:
  ArmyRatio createArmyRatio() override;
  ArcherWarfare();
  ~ArcherWarfare();
};


#endif//ARCHERWARFARE_H
