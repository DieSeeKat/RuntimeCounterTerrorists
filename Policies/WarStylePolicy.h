#ifndef WARSTYLEPOLICY_H
#define WARSTYLEPOLICY_H

#include "../ArmyRatio.h"
#include <map>

class WarStylePolicy {
public:
	ArmyRatio createArmyRatio();
	virtual WarStylePolicy* clone(std::map<void*,void*> &objmap);
};

#endif
