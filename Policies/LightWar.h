#ifndef LIGHTWAR_H
#define LIGHTWAR_H
#include "RecruitmentPolicy.h"

class LightWar : public RecruitmentPolicy
{
  public:
  int calculateRecruits(int town_population) override;
  LightWar();
  ~LightWar();
};


#endif//LIGHTWAR_H
