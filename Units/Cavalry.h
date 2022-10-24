#ifndef CAVALRY_H
#define CAVALRY_H

#include "Unit.h"

class Cavalry : Unit {
    Unit* clone(std::map<void*, void*> &objmap) override;
};

#endif
