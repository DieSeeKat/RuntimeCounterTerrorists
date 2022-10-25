#ifndef ARCHER_H
#define ARCHER_H

#include "Unit.h"

class Archer : public Unit
{
    Unit* clone(std::map<void*, void*> &objmap);
    public:
        Archer();

};

#endif
