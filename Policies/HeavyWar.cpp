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
  std::cout << "The Army is in the Heavy War" << std::endl;
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