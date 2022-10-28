#ifndef LIGHTWAR_H
#define LIGHTWAR_H

#include "RecruitmentPolicy.h"
#include<string>

using namespace std;

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
  /**
   * @brief Clone method for the LightWar Policy
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned LightWar Policy
   */
  RecruitmentPolicy* clone(std::map<void*, void*> &objmap);

  virtual string getRecuitmentPolicyName();
};


#endif//LIGHTWAR_H
