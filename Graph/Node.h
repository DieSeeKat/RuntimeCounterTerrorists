#ifndef NODE_H
#define NODE_H

#include <string>


#include "../Army.h"
#include "../ArmyRatio.h"

#include "Aggregate.h"
#include "NodeIterator.h"

#include "Path.h"

#include "../Observer/Subject.h"

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

  void removeObserver(Observer* observer);


  Node *nextStepTo(Node *node);
  std::vector<Path *> getPaths();

  Empire *getOwnerEmpire();
  std::vector<Node *> findShortestPathTo(std::vector<Node *> nodes, Node *node);
  bool connectedToCapital(std::vector<Node *> nodes, Node *capital);

};

#endif
