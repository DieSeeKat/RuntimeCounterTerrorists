#include "HeavyWar.h"
#include <iostream>

int HeavyWar::calculateRecruits(int town_population)
{
  float percentage = 0.4;
  float value      = percentage * town_population;
  int return_value = static_cast<int>(value);
  return return_value;
}
HeavyWar::HeavyWar() : RecruitmentPolicy()
{
}
HeavyWar::~HeavyWar()
{
}

RecruitmentPolicy* HeavyWar::clone(std::map<void*, void*> &objmap){
  if(objmap.find(this)!=objmap.end()){
    return (RecruitmentPolicy*)((*objmap.find(this)).second);
  }
  else{
    HeavyWar* temp = new HeavyWar();
    objmap.insert(std::pair<void*, void*>(this, temp));
    return temp;
  }
}

string HeavyWar::getRecuitmentPolicyName(){
  return "Heavy war";
}