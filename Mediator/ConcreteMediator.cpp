#include "ConcreteMediator.h"

void ConcreteMediator::notifyOfAttack(Node* node) {
  NodeIterator* town_it = new NodeIterator(node);
  town_it->first();
  Node * current_town = town_it->currentNode();

  while(!town_it->isDone())
  {
    current_town->onAttacked();
    town_it->next();
    current_town = town_it->currentNode();
  }
}
