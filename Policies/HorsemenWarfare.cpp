#include "HorsemenWarfare.h"
#include <iostream>

ArmyRatio HorsemenWarfare::createArmyRatio()
{
  float cavalry = 0.7;
  float archer = 0.1;
  float footmen = 0.1;
  float slingers = 0.1;
  ArmyRatio ratio =  ArmyRatio(cavalry,archer,footmen,slingers);

  return ratio;
}
HorsemenWarfare::HorsemenWarfare() : WarStylePolicy()
{
}
HorsemenWarfare::~HorsemenWarfare()
{
}
