#ifndef BARRACKS_H
#define BARRACKS_H

#include <vector>
#include "../Units/Unit.h"

class Barracks {

private:
	std::vector<Unit*> units;

protected:
	virtual Unit* factoryMethod() = 0;

public:
	void createUnits(int num_units);
    std::vector<Unit*> getUnits();
    void clearUnits();
};

#endif
