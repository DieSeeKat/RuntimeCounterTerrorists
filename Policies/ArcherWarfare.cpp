#include "ArcherWarfare.h"
#include <iostream>
#include <map>

ArmyRatio ArcherWarfare::createArmyRatio()
{
  float cavalry = 0.1;
  float archer = 0.4;
  float footmen = 0.1;
  float slingers = 0.4;
  ArmyRatio ratio =  ArmyRatio(cavalry,archer,footmen,slingers);

  return ratio;
}
ArcherWarfare::ArcherWarfare() : WarStylePolicy()
{
}
ArcherWarfare::~ArcherWarfare()
{
}

WarStylePolicy* ArcherWarfare::clone(std::map<void*,void*> &objmap){
  if(objmap.find(this)!=objmap.end()){
    return (WarStylePolicy*)((*objmap.find(this)).second);
  }
  else{
    ArcherWarfare* temp = new ArcherWarfare();
    objmap.insert(std::pair<void*,void*>(this, temp));
    return temp;
  }
}


std::string ArcherWarfare::getWarStyleName(){
  return "Archer warfare";
}