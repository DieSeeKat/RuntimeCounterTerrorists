#include "LegionaryWarfare.h"
#include <iostream>

ArmyRatio LegionaryWarfare::createArmyRatio()
{
  float cavalry = 0.3;
  float archer = 0.05;
  float footmen = 0.6;
  float slingers = 0.05;
  ArmyRatio ratio =  ArmyRatio(cavalry,archer,footmen,slingers);

  return ratio;
}
LegionaryWarfare::LegionaryWarfare()
{
  std::cout<<"The Army has chosen Legionary Warfare"<<std::endl;
}
LegionaryWarfare::~LegionaryWarfare()
{
}
