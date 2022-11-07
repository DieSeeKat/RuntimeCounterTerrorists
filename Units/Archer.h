#ifndef ARCHER_H
#define ARCHER_H

#include "Unit.h"

class Archer : public Unit
{
    /**
     * @brief Clone method for Unit
     * 
     * @param objmap map<void*,void*>
     * @return Unit* The cloned Unit
     */
    Unit* clone(std::map<void*, void*> &objmap);
    public:
        Archer();

};

#endif
