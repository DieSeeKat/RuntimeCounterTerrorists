#ifndef HEAVYWAR_H
#define HEAVYWAR_H

#include "../Graph/Node.h"

#include "RecruitmentPolicy.h"

class HeavyWar : public RecruitmentPolicy
{
  public:
  int calculateRecruits(int town_population);
};

#endif
