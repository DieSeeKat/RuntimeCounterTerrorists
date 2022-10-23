#ifndef BARRACKS_H
#define BARRACKS_H

#include "../Units/Unit.h"

class Barracks {

private:
	Unit* units;

protected:
	virtual Unit* factoryMethod(int numRecruits) = 0;

public:
	void createUnits();
};

#endif
