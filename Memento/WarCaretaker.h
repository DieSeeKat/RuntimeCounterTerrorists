#ifndef WARCARETAKER_H
#define WARCARETAKER_H

#include <iostream>
#include <stack>
#include "WarRollback.h"

class WarCaretaker
{
private:
    std::stack<WarRollback*> mementos;
public:
    void storeMemento(WarRollback* to_store);
    WarRollback* getMemento();
};

#endif
