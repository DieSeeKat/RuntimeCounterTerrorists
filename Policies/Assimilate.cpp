#include "Assimilate.h"

int Assimilate::handleColony(Node* colony_town) {
	// TODO - implement Assimilate::handleColony
	throw "Not yet implemented";
}


ColonyPolicy* Assimilate::clone(std::map<void*,void*> &objmap){
  if(objmap.find(this)!=objmap.end()){
		return (ColonyPolicy*)((*objmap.find(this)).second);
	}
	else{
		Assimilate* temp = new Assimilate();
		objmap.insert(std::pair<void*,void*>(this, temp));
		return temp;
	}
}