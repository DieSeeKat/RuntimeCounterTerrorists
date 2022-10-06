#ifndef NODE_H
#define NODE_H

#include <string>


#include "Army.h"
#include "ArmyRatio.h"

#include "Aggregate.h"
#include "NodeIterator.h"

#include "Path.h"

#include "Subject.h"

#include "Mediator.h"

class Empire;

class Node : Aggregate, Subject
{

  private:
  Mediator *mediator;
  int resources;
  int population;
  Empire *population_empire;
  Path **paths;

  public:
  NodeIterator *createIterator();

  void changed();

  virtual std::string getState() = 0;

  Army recruit(ArmyRatio ratio);

  virtual void colonise(Empire *colonising_empire) = 0;

  void repopulate();
};

#endif
