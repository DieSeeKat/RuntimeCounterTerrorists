#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <map>
//In my implementation I assume the capitol node will be the mediator. When an empire gets attacked its capitol is aware of this and notify all the surrounding towns.
class Node;

class Mediator
{
  public:
  virtual void notifyOfAttack(Node *node) = 0;
  /**
   * @brief Clone method for the Mediator
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned Mediator
   */
  virtual Mediator* clone(std::map<void*, void*> &objmap) = 0;
};

#endif
