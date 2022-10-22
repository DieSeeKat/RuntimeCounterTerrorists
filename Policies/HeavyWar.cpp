#include "HeavyWar.h"

int HeavyWar::calculateRecruits(int town_population)
{
  // TODO - implement HeavyWar::calculateRecruits
  throw "Not yet implemented";
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