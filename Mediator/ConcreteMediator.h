#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H

#include "Mediator.h"

#include "../Graph/Node.h"

class ConcreteMediator : public Mediator {

public:
    /**
 * @brief Method to notify the adjacent towns in the empire when it is under attack
 * @param node A node pointer of the town that is under attack
 */
  void notifyOfAttack(Node *node);
  /**
   * @brief Clone method for the ConcreteMediator
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned ConcreteMediator
   */
  Mediator *clone(std::map<void *, void *> &objmap);
};

#endif
