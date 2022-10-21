#ifndef RECRUITMENTPOLICY_H
#define RECRUITMENTPOLICY_H

class RecruitmentPolicy
{
  public:
  virtual int calculateRecruits(int town_population) = 0;
  RecruitmentPolicy();
  ~RecruitmentPolicy();
};

#endif
