#ifndef FOOTMENBARRACKS_H
#define FOOTMENBARRACKS_H

#include "Barracks.h"
#include "../Units/Footmen.h"

class FootmenBarracks:public Barracks
{
public:
    FootmenBarracks();
    Unit* factoryMethod();
    
};


#endif