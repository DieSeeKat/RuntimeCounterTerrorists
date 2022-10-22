#ifndef WARSTYLEPOLICY_H
#define WARSTYLEPOLICY_H

#include "../ArmyRatio.h"

class WarStylePolicy {
public:
    /**
     * @brief creates the ArmyRatio depending on the type of warfare
     * @return ArmyRatio class
     */
	virtual ArmyRatio createArmyRatio()=0;
    /// Constructor
    WarStylePolicy();
    /// Destructor
    ~WarStylePolicy();
};

#endif
