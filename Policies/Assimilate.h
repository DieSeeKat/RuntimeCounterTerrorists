#ifndef ASSIMILATE_H
#define ASSIMILATE_H

#include "../Graph/Node.h"

#include "ColonyPolicy.h"

class Assimilate : ColonyPolicy {
public:
	int handleColony(Node* colony_town);
};

#endif
