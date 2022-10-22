#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H

#include "Mediator.h"

#include "../Graph/Node.h"

class ConcreteMediator : Mediator {

public:
	void notifyOfAttack(Node* node);
	Mediator* clone(std::map<void*, void*> &objmap);
};

#endif
