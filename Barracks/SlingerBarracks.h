#ifndef SLINGERBARRACKS_H
#define SLINGERBARRACKS_H

#include "../Units/Slinger.h"
#include "../Units/Unit.h"
#include "Barracks.h"

class SlingerBarracks : public Barracks
{
public:
    SlingerBarracks();
    /**
     * @brief Factory method to create troops
     * 
     * @return Unit* 
     */
    Unit* factoryMethod();
};


#endif