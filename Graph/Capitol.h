#ifndef CAPITOL_H
#define CAPITOL_H

#include "Node.h"

#include "../Empire.h"

class Capitol : Node {
public:
	void colonise(Empire* colonising_empire);
};

#endif
