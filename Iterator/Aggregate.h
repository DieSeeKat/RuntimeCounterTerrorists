#ifndef AGGREGATE_H
#define AGGREGATE_H

#include "NodeIterator.h"

class Aggregate {
public:
	virtual NodeIterator* createIterator() = 0;
};

#endif
