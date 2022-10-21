#ifndef NORMALWAR_H
#define NORMALWAR_H

#include "RecruitmentPolicy.h"
#include "Node.h"

class NormalWar : public RecruitmentPolicy
{
  public:
  int calculateRecruits(int town_population) override;
  NormalWar();
  ~NormalWar();
};


#endif//NORMALWAR_H
