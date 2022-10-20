#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H

#include "Mediator.h"

#include "../Graph/Node.h"

class ConcreteMediator : Mediator {

public:
	void notifyOfAttack(Node* node);
};

#endif
