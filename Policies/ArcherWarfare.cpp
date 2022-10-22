#include "ArcherWarfare.h"
#include <iostream>
#include <map>

ArmyRatio ArcherWarfare::createArmyRatio()
{
  float cavalry = 0.1;
  float archer = 0.4;
  float footmen = 0.1;
  float slingers = 0.4;
  ArmyRatio ratio =  ArmyRatio(cavalry,archer,footmen,slingers);

  return ratio;
}
ArcherWarfare::ArcherWarfare() : WarStylePolicy()
{
}
ArcherWarfare::~ArcherWarfare()
{
}
