#ifndef WARSTYLEPOLICY_H
#define WARSTYLEPOLICY_H

#include "../ArmyRatio.h"

class WarStylePolicy {
public:
	virtual ArmyRatio createArmyRatio()=0;
    WarStylePolicy();
    ~WarStylePolicy();
};

#endif
