//
// Created by Lukas Anthonissen on 2022/10/06.
//

#include "ArmyRatio.h"

ArmyRatio::ArmyRatio::ArmyRatio(float cavalry_ratio, float archer_ratio, float footmen_ratio, float slinger_ratio)
{
  this->cavalry_ratio  = cavalry_ratio;
  this->archer_ratio  = archer_ratio;
  this->footmen_ratio = footmen_ratio;
  this->slinger_ratio = slinger_ratio;
}