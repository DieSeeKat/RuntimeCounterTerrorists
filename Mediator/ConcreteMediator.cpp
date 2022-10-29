#include "ConcreteMediator.h"

void ConcreteMediator::notifyOfAttack(Node* node) {
  NodeIterator* town_it = new NodeIterator(node);
  Node * current_town ;

  while(!town_it->isDone())
  {
      town_it->next();
      current_town = town_it->currentNode();
    if(current_town->getOwnerEmpire() == node->getOwnerEmpire())
    {
      current_town->onAttacked();
    }
  }
}

Mediator* ConcreteMediator::clone(std::map<void*, void*> &objmap){
  if(objmap.find(this)!=objmap.end()){
    return (Mediator*)((*objmap.find(this)).second);
  }
  else{
    ConcreteMediator* temp = new ConcreteMediator();
    objmap.insert(std::pair<void*,void*>(this, temp));
  
    return temp;
  }
}