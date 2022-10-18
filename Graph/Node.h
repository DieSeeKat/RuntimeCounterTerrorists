#ifndef NODE_H
#define NODE_H

#include <string>


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
  /// The current distance from the start Node of the Label-Correcting Algorithm
  int dist;
  /// The previous node of the shortest path to the start Node of the Label-Correcting Algorithm
  Node *prev = nullptr;
  NodeIterator *createIterator();
  void changed();
  /**
   * @brief Recharge resources to the maximum capacity according to the Node's population
   */
  void rechargeResources();
  virtual std::string getState() = 0;
  /**
   * @brief Recruit an army from the Node depending on the ArmyRatio and the number of recruits wanted.
   *
   * @param ratio
   * @param num_recruits
   * @return Army for the Empire to use
   */
  Army recruit(ArmyRatio ratio, int num_recruits);
  /**
   * @brief A pure virtual function that will be implemented in Town
   * @param colonising_empire
   */
  virtual void colonise(Empire *colonising_empire) = 0;
  /**
   * @brief Repopulate a town
   */
  void repopulate();
  /**
   * @brief Getter for population
   * @return Return population
   */
  int getPopulation();

  Node *nextStepTo(Node *node);
  std::vector<Path *> getPaths();
  /**
   * @brief Return owner_empire
   * @return The empire that owns the current Node
   */
  Empire *getOwnerEmpire();
  /**
   * A label-correcting algorithm to find the shortest path between the Army's Node and the Capital of an enemy empire. This is used to
   * create a vector of Nodes which the Army must follow to move to the passed in Node.
   *
   * @brief Find the shortest path between the current Node and the passed in Node.
   *
   * @param nodes
   * @param node
   * @return Returns a vector of Nodes leading to the passed in node
   */
  std::vector<Node *> findShortestPathTo(std::vector<Node *> nodes, Node *node);
  /**
   * Use the label correcting algorithm, avoiding enemy empires to determine if the Node is connected to its empire's capital.
   *
   * @brief Determine if the Node is connected to its empire's capital.
   *
   * @param nodes All the Nodes of the map
   * @param capital The capital to which the connection must be tested.
   * @return Returns a vector of Nodes leading to the passed in node
   */
  bool connectedToCapital(std::vector<Node *> nodes, Node *capital);
};

#endif
