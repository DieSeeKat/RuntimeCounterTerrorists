#ifndef HEAVYWAR_H
#define HEAVYWAR_H

#include "../Graph/Node.h"
#include "RecruitmentPolicy.h"

class HeavyWar : public RecruitmentPolicy
{
  public:
  /**
   * @brief calculates the number of recruits needed depending  on the war
   * @param town_population
   * @return
   */
  int calculateRecruits(int town_population) override;
  /// Constructor
  HeavyWar();
  /// Destructor
  ~HeavyWar();
};

#endif
