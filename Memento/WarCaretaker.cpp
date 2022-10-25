#include "WarCaretaker.h"

void WarCaretaker::storeMemento(WarRollback *to_store)
{
    this->mementos.push(to_store);
}
WarRollback *WarCaretaker::getMemento()
{
    WarRollback *temp = NULL;
    temp = this->mementos.top();
    this->mementos.pop();
    return temp;
}