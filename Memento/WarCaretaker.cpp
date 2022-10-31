#include "WarCaretaker.h"
/**
 * @brief Stores a WarRollback object in a stack to possibly restore it at a later time.
 * Use the War::createWarRollback() method and pass the result into this method.
 * @param to_store WarRollback*
 */
void WarCaretaker::storeMemento(WarRollback *to_store)
{
    this->mementos.push(to_store);
}
/**
 * @brief Returns the WarRollback* at the top of the stack.
 * Use the War::setWarRollback(WarRollback*) method and pass it the result from this method.
 * @return WarRollback* 
 */
WarRollback *WarCaretaker::getMemento()
{
    WarRollback *temp = NULL;
    temp = this->mementos.top();
    this->mementos.pop();
    return temp;
}