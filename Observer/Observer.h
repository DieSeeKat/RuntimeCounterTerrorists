#ifndef OBSERVER_H
#define OBSERVER_H

#include "Subject.h"

class Observer
{

    public:
        Observer(): subject(0)
        {

        };

        void register(Subject* subject);
        virtual void update() = 0;

    protected:
        Subject* subject


};

#endif
