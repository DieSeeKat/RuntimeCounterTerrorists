#include "LightWar.h"
#include <iostream>

int LightWar::calculateRecruits(int town_population)
{
  float percentage = 0.1;
  float value      = percentage * town_population;
  int return_value = static_cast<int>(value);
  return return_value;
}
LightWar::LightWar() : RecruitmentPolicy()
{
}
LightWar::~LightWar()
{
}
RecruitmentPolicy* LightWar::clone(std::map<void*, void*> &objmap){
  if(objmap.find(this)!=objmap.end()){
    return (RecruitmentPolicy*)((*objmap.find(this)).second);
  }
  else{
    LightWar* temp = new LightWar();
    objmap.insert(std::pair<void*, void*>(this, temp));
    return temp;
  }
}