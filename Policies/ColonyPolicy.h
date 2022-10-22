#ifndef COLONYPOLICY_H
#define COLONYPOLICY_H

#include "../Graph/Node.h"
#include <map>

class ColonyPolicy {
public:
	int handleColony(Node* colony_town);
	virtual ColonyPolicy* clone(std::map<void*,void*> &objmap);
};

#endif
