#ifndef FOOTMENBARRACKS_H
#define FOOTMENBARRACKS_H

#include "Barracks.h"
#include "../Units/Footmen.h"

class FootmenBarracks:public Barracks
{
private:
    /* data */
public:
    FootmenBarracks(/* args */);
    Unit* factoryMethod(int numRecruits);
    
};


#endif