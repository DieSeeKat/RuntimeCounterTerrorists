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
  Empire *ownerEmpire;
  std::vector<Path *> paths;

  public:
  int dist;
  Node *prev = nullptr;

  NodeIterator *createIterator();
  void changed();
  void rechargeResources();
  virtual std::string getState() = 0;
  Army recruit(ArmyRatio ratio, int num_recruits);
  virtual void colonise(Empire *colonising_empire) = 0;
  void repopulate();
  int getPopulation();
  Node *recursivelyFindClosestEnemy(int depth, int max_depth);
  Node *nextStepTo(Node *node);
  Node *getClosestEnemy();
  std::vector<Node *> findShortestPathTo(Node *node);
};

#endif
