#ifndef RECRUITMENTPOLICY_H
#define RECRUITMENTPOLICY_H

#include <map>

class RecruitmentPolicy
{
  public:
  /**
   * @brief calculates the number of recruits needed depending  on the war
   * @param town_population
   * @return
   */
  virtual int calculateRecruits(int town_population) = 0;

  /// Constructor
  RecruitmentPolicy();
  /// Destructor
  ~RecruitmentPolicy();
  virtual RecruitmentPolicy* clone(std::map<void*, void*> &objmap) = 0;

};
//had problems with the Git in regard to the Light, Heavy and Normal war - Dharshan Gopaul
#endif
