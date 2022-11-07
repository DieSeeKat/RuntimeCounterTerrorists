#ifndef CAVALRY_H
#define CAVALRY_H

#include "Unit.h"

class Cavalry :public Unit {

    public:
        Cavalry();
        /**
         * @brief Clone method for Cavalry
         * 
         * @param objmap 
         * @return Unit* The pointer to the cloned Cavalry object.
         */
        Unit* clone(std::map<void*, void*> &objmap) override;
};

#endif
