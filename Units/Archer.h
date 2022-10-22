#ifndef ARCHER_H
#define ARCHER_H

#include "Unit.h"

class Archer : Unit
{
    Unit* clone(std::map<void*, void*> &objmap);
};

#endif
