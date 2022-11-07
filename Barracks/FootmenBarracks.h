#ifndef FOOTMENBARRACKS_H
#define FOOTMENBARRACKS_H

#include "Barracks.h"
#include "../Units/Footmen.h"

class FootmenBarracks:public Barracks
{
public:
    FootmenBarracks();
    /**
     * @brief Factory method to create troops
     * 
     * @return Unit* 
     */
    Unit* factoryMethod();
    
};


#endif