#ifndef SLINGERBARRACKS_H
#define SLINGERBARRACKS_H

#include "../Units/Slinger.h"
#include "Barracks.h"

class SlingerBarracks:public Barracks
{
public:
    SlingerBarracks();
    Unit* factoryMethod();
};


#endif