#ifndef HEAVYWAR_H
#define HEAVYWAR_H

#include "../Graph/Node.h"
#include "RecruitmentPolicy.h"

#include<string>

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
  /**
   * @brief Clone method for the HeavyWar Policy
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned HeavyWar Policy
   */
  RecruitmentPolicy* clone(std::map<void*, void*> &objmap);


  std::string getRecuitmentPolicyName() override;

};

#endif
