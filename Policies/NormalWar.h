#ifndef NORMALWAR_H
#define NORMALWAR_H

#include <map>
#include "../Graph/Node.h"
#include "RecruitmentPolicy.h"

class NormalWar : public RecruitmentPolicy
{
  public:
  /**
   * @brief calculates the number of recruits needed depending  on the war
   * @param town_population
   * @return
   */
  int calculateRecruits(int town_population) override;
  /// Constructor
  NormalWar();
  /// Destructor
  ~NormalWar();
};


#endif//NORMALWAR_H
