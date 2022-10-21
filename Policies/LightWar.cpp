#include "LightWar.h"
#include <iostream>
int LightWar::calculateRecruits(int town_population)
{
  float percentage = 0.1;
  float value      = percentage * town_population;
  int return_value = static_cast<int>(value);
  return return_value;
}
LightWar::LightWar() : RecruitmentPolicy()
{
  std::cout << "The Army is in the Light War" << std::endl;
}
LightWar::~LightWar()
{
}
