#ifndef MEDIATOR_H
#define MEDIATOR_H
//In my implementation I assume the capitol node will be the mediator. When an empire gets attacked its capitol is aware of this and notify all the surrounding towns.
class Node;

class Mediator
{
  public:
  virtual void notifyOfAttack(Node *node) = 0;
};

#endif
