#include "ColonyPolicy.h"

int ColonyPolicy::handleColony(Node* colony_town) {
	// TODO - implement ColonyPolicy::handleColony
	throw "Not yet implemented";
}


ColonyPolicy* ColonyPolicy::clone(std::map<void*,void*> &objmap){
  if(objmap.find(this)!=objmap.end()){
		return (ColonyPolicy*)((*objmap.find(this)).second);
	}
	else{
		ColonyPolicy* temp = new ColonyPolicy();
		objmap.insert(std::pair<void*,void*>(this, temp));
		return temp;
	}
}