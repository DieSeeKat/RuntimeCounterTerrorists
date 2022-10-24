#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H

#include "Mediator.h"

#include "../Graph/Node.h"

class ConcreteMediator : Mediator {

public:
  void notifyOfAttack(Node *node);
  /**
   * @brief Clone method for the ConcreteMediator
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned ConcreteMediator
   */
  Mediator *clone(std::map<void *, void *> &objmap);
};

#endif
