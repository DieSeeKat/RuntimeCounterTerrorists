#include "LegionaryWarfare.h"
#include <iostream>

ArmyRatio LegionaryWarfare::createArmyRatio()
{
  float cavalry = 0.3;
  float archer = 0.05;
  float footmen = 0.6;
  float slingers = 0.05;
  ArmyRatio ratio =  ArmyRatio(cavalry,archer,footmen,slingers);

  return ratio;
}
LegionaryWarfare::LegionaryWarfare() : WarStylePolicy()
{
}
LegionaryWarfare::~LegionaryWarfare()
{
}
WarStylePolicy* LegionaryWarfare::clone(std::map<void*,void*> &objmap){
  if(objmap.find(this)!=objmap.end()){
    return (WarStylePolicy*)((*objmap.find(this)).second);
  }
  else{
    LegionaryWarfare* temp = new LegionaryWarfare();
    objmap.insert(std::pair<void*,void*>(this, temp));
    return temp;
  }
}


string LegionaryWarfare::getWarStyleName(){
  return "Legionary warfare";
}