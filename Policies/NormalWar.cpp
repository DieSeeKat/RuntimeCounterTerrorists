#include "NormalWar.h"
#include <iostream>

int NormalWar::calculateRecruits(int town_population)
{
  float percentage = 0.2;
  float value      = percentage * town_population;
  int return_value = static_cast<int>(value);
  return return_value;
}
NormalWar::NormalWar() : RecruitmentPolicy()
{
}
NormalWar::~NormalWar()
{
}
