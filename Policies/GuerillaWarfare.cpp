#include "GuerillaWarfare.h"
#include <iostream>
ArmyRatio GuerillaWarfare::createArmyRatio()
{
  float cavalry = 0.1;
  float archer = 0.2;
  float footmen = 0.5;
  float slingers = 0.2;
  ArmyRatio ratio =  ArmyRatio(cavalry,archer,footmen,slingers);

  return ratio;
}
GuerillaWarfare::GuerillaWarfare() : WarStylePolicy()
{
}
GuerillaWarfare::~GuerillaWarfare()
{
}

WarStylePolicy* GuerillaWarfare::clone(std::map<void*,void*> &objmap){
  if(objmap.find(this)!=objmap.end()){
		return (WarStylePolicy*)((*objmap.find(this)).second);
	}
	else{
		GuerillaWarfare* temp = new GuerillaWarfare();
		objmap.insert(std::pair<void*,void*>(this, temp));
		return temp;
	}
}