#ifndef OBSERVER_H
#define OBSERVER_H

class Observer
{
    public:
    /**
     * @brief A pure virtual method to change the status of the army and is implemented in the Army class
     */
   virtual void update() = 0;
};

#endif
