#ifndef CAVALRYBARRACKS_H
#define CAVALRYBARRACKS_H

#include "Barracks.h"

#include "../Units/Unit.h"
#include "../Units/Cavalry.h"

class CavalryBarracks : public Barracks {

public:
    CavalryBarracks();
    /**
     * @brief Factory method to create troops
     * 
     * @return Unit* 
     */
	Unit* factoryMethod();
};

#endif
