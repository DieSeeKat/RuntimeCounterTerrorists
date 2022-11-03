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
  /**
   * @brief Clone method for the NormalWar Policy
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned NormalWar Policy
   */
  RecruitmentPolicy* clone(std::map<void*, void*> &objmap);

  std::string getRecuitmentPolicyName() override;
};


#endif//NORMALWAR_H
