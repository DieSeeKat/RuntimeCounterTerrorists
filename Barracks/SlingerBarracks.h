#ifndef SLINGERBARRACKS_H
#define SLINGERBARRACKS_H

#include "../Units/Slinger.h"
#include "Barracks.h"

class SlingerBarracks:public Barracks
{
private:
    /* data */
public:
    SlingerBarracks(/* args */);
    Unit* factoryMethod(int numRecruits);
};


#endif