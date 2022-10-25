#ifndef CAVALRY_H
#define CAVALRY_H

#include "Unit.h"

class Cavalry :public Unit {

    public:
        Cavalry();
        Unit* clone(std::map<void*, void*> &objmap) override;
};

#endif
