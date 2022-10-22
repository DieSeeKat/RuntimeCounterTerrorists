#include "GuerillaWarfare.h"
#include <iostream>
ArmyRatio GuerillaWarfare::createArmyRatio()
{
  float cavalry = 0.1;
  float archer = 0.2;
  float footmen = 0.5;
  float slingers = 0.2;
  ArmyRatio ratio =  ArmyRatio(cavalry,archer,footmen,slingers);

  return ratio;
}
GuerillaWarfare::GuerillaWarfare() : WarStylePolicy()
{
  std::cout<<"The Army has chosen Guerilla Warfare"<<std::endl;
}
GuerillaWarfare::~GuerillaWarfare()
{
}
