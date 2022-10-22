#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <map>
//In my implementation I assume the capitol node will be the mediator. When an empire gets attacked its capitol is aware of this and notify all the surrounding towns.
class Node;

class Mediator
{
  public:
  virtual void notifyOfAttack(Node *node) = 0;
  virtual Mediator* clone(std::map<void*, void*> &objmap) = 0;
};

#endif
