#ifndef MEDIATOR_H
#define MEDIATOR_H

class Node;

class Mediator
{
  public:
  virtual void notifyOfAttack(Node *node) = 0;
};

#endif
