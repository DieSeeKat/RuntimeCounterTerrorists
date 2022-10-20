#ifndef NODE_H
#define NODE_H

#include <string>


#include "../Army.h"
#include "../ArmyRatio.h"

#include "../Iterator/Aggregate.h"
#include "../Iterator/NodeIterator.h"

#include "Path.h"

#include "../Observer/Subject.h"

#include "../Mediator/Mediator.h"

class Empire;

class Node : Aggregate, Subject
{
  protected:
  Mediator *mediator;
  /// The number of resources a Node holds
  int resources;
  /// The total population of a Node
  int population;
  /// The original empire of population of the Node
  Empire *population_empire;
  /// The current controlling power
  Empire *owner_empire;
  /// All paths connecting to other Nodes
  std::vector<Path *> paths;
  std::vector<Army*> stationed_armies;

  public:
  /// The current distance from the start Node of the Label-Correcting Algorithm
  int dist;
  /// The previous node of the shortest path to the start Node of the Label-Correcting Algorithm
  Node *prev = nullptr;
  Node(Empire* owner_empire, int population);
  ~Node();
  /**
   * @brief Remove a path between this Node and another
   * @param path Path to be removed
   */
  void removePath(Path *path);
  NodeIterator *createIterator();
  /**
   * @brief Form a connection between this Node and another
   * @param node Node to connect to
   */
  void addPathTo(Node *node);
  /**
   * @brief Add a path to the Node's paths vector
   * @param path Path to be added
   */
  void addPath(Path *path);
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
  /**
   * @brief Get all paths origination from the Node
   * @return Return a vector of Path pointers
   */
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

  /**
   * @brief Handles the combat of when a Node gets attacked
   * Will destroy or weaken armies depending on the result of the battle and will be colonised if it loses the battle.
   * @param attacking_army The army performing the attack.
   */
  void onAttacked();
  void getAttacked(Army* attacking_army);
  /**
   * @brief Make this Node a free city. Will change the owner_empire attribute to nullptr
   */
  void makeFreeCity();

  /**
   * @brief Get armies stationed here.
   * @return Return a vector of Army pointers
   */
  std::vector<Army*> getStationedArmies();
  /**
   * @brief Remove a specific army from being stationed here
   * @param army Army to be removed
   */
  void removeStationedArmy(Army* army);
  /**
   * @todo Make clone method pure virtual after implementing clone() method in children classes.
  */
  virtual Node* clone();
};

#endif
