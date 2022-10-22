#ifndef ASSIMILATE_H
#define ASSIMILATE_H

#include "../Graph/Node.h"

#include "ColonyPolicy.h"

class Assimilate : public ColonyPolicy {
public:
	int handleColony(Node* colony_town);
	ColonyPolicy* clone(std::map<void*,void*> &objmap);
};

#endif
