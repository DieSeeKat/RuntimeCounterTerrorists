#include "HorsemenWarfare.h"
#include <iostream>

ArmyRatio HorsemenWarfare::createArmyRatio()
{
  float cavalry = 0.7;
  float archer = 0.1;
  float footmen = 0.1;
  float slingers = 0.1;
  ArmyRatio ratio =  ArmyRatio(cavalry,archer,footmen,slingers);

  return ratio;
}
HorsemenWarfare::HorsemenWarfare() : WarStylePolicy()
{
}
HorsemenWarfare::~HorsemenWarfare()
{
}
WarStylePolicy* HorsemenWarfare::clone(std::map<void*,void*> &objmap){
  if(objmap.find(this)!=objmap.end()){
    return (WarStylePolicy*)((*objmap.find(this)).second);
  }
  else{
    HorsemenWarfare* temp = new HorsemenWarfare();
    objmap.insert(std::pair<void*,void*>(this, temp));
    return temp;
  }
}


std::string HorsemenWarfare::getWarStyleName(){
  return "Horsemen warfare";
}