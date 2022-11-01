#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <map>
class Node;

class Mediator
{
  public:
    /**
     * @brief Method to notify the adjacent towns in the empire when it is under attack
     * @param node A node pointer of the town that is under attack
     */
  virtual void notifyOfAttack(Node *node) = 0;
  /**
   * @brief Clone method for the Mediator
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned Mediator
   */
  virtual Mediator* clone(std::map<void*, void*> &objmap) = 0;
};

#endif
