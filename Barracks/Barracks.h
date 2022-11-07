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
	/**
	 * @brief Create a Units object
	 * 
	 * @param num_units 
	 */
	void createUnits(int num_units);
	/**
	 * @brief Get the Units object
	 * 
	 * @return std::vector<Unit*> 
	 */
    std::vector<Unit*> getUnits();
	/**
	 * @brief Clears all units
	 * 
	 */
    void clearUnits();
};

#endif
