#include "GuerillaWarfare.h"

ArmyRatio GuerillaWarfare::createArmyRatio()
{
  // TODO - implement GuerillaWarfare::createArmyRatio
  throw "Not yet implemented";
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