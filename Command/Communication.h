#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "../Empire.h"

class Communication {
public:
	virtual void handleAlliance(Empire * empire) = 0;
};

#endif
