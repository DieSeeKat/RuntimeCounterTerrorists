#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

#include "../Army.h"
#include "../ArmyRatio.h"

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
  std::vector<Path *> paths;

  public:
  NodeIterator *createIterator();
  void changed();
  void rechargeResources();
  virtual std::string getState() = 0;
  Army recruit(ArmyRatio ratio, int num_recruits);
  virtual void colonise(Empire *colonising_empire) = 0;
  void repopulate();
  int getPopulation();
  Node *findClosestEnemy();
  Node *nextStepTo(Node *node);
  Node *getAdjacentEnemy();
};

#endif
