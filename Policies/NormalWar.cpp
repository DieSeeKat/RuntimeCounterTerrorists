#include "NormalWar.h"
#include <iostream>

int NormalWar::calculateRecruits(int town_population)
{
  float percentage = 0.2;
  float value      = percentage * town_population;
  int return_value = static_cast<int>(value);
  return return_value;
}
NormalWar::NormalWar() : RecruitmentPolicy()
{
}
NormalWar::~NormalWar()
{
}
RecruitmentPolicy* NormalWar::clone(std::map<void*, void*> &objmap){
  if(objmap.find(this)!=objmap.end()){
    return (RecruitmentPolicy*)((*objmap.find(this)).second);
  }
  else{
    NormalWar* temp = new NormalWar();
    objmap.insert(std::pair<void*, void*>(this, temp));
    return temp;
  }
}

std::string NormalWar::getRecuitmentPolicyName(){
  return "Normal war";
}