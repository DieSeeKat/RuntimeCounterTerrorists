#ifndef OBSERVER_H
#define OBSERVER_H

#include "Subject.h"

class Observer
{

    public:
        virtual void update() = 0;
        void register(Subject* subject);

    protected:

        Subject* subject


};

#endif
