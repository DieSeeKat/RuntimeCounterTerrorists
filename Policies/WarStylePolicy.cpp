#include "WarStylePolicy.h"

ArmyRatio WarStylePolicy::createArmyRatio() {
	// TODO - implement WarStylePolicy::createArmyRatio
	throw "Not yet implemented";
}


WarStylePolicy* WarStylePolicy::clone(std::map<void*,void*> &objmap){
	if(objmap.find(this)!=objmap.end()){
		return (WarStylePolicy*)((*objmap.find(this)).second);
	}
	else{
		WarStylePolicy* temp = new WarStylePolicy();
		objmap.insert(std::pair<void*,void*>(this, temp));
		return temp;
	}
}