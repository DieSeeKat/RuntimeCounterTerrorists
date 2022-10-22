#ifndef LIGHTWAR_H
#define LIGHTWAR_H

#include "RecruitmentPolicy.h"

class LightWar : public RecruitmentPolicy
{
  public:
  /**
   * @brief calculates the number of recruits needed depending  on the war
   * @param town_population
   * @return
   */
  int calculateRecruits(int town_population) override;
  /// Constructor
  LightWar();
  /// Destructor
  ~LightWar();
};


#endif//LIGHTWAR_H
