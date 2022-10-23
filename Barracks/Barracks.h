#ifndef BARRACKS_H
#define BARRACKS_H

#include "../Units/Unit.h"

class Barracks {

private:
	Unit* units;

protected:
	virtual Unit* factoryMethod() = 0;

public:
	Barracks();
	void createUnits();
};

#endif
