#ifndef ARCHERYBARRACKS_H
#define ARCHERYBARRACKS_H

#include "Barracks.h"

#include "../Units/Unit.h"
#include "../Units/Archer.h"

class ArcheryBarracks : public Barracks {
public:
    ArcheryBarracks();
	Unit* factoryMethod();
};

#endif
