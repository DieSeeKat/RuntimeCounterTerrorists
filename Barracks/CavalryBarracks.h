#ifndef CAVALRYBARRACKS_H
#define CAVALRYBARRACKS_H

#include "Barracks.h"

#include "../Units/Unit.h"
#include "../Units/Cavalry.h"

class CavalryBarracks : Barracks {

public:
	CavalryBarracks();
	Unit* factoryMethod();
};

#endif
