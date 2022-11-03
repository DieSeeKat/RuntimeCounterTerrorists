#ifndef NODE_H
#define NODE_H

#include <string>

#include "../ArmyRatio.h"

#include "../Iterator/Aggregate.h"
#include "../Iterator/NodeIterator.h"

#include "Path.h"

#include "../Memento/War.h"

#include "../Observer/Subject.h"

#include "../Mediator/Mediator.h"

#include "NodeType.h"
#include "../Army.h"

#include "../Memento/War.h"

#include <map>
#include <algorithm>
class Empire;

class War;

class Node : Aggregate, public Subject
{
  private:
  Node();
  protected:
  Mediator *mediator = nullptr;
  /// The number of resources a Node holds

  War* war = nullptr;

  int resources;
  /// The total population of a Node
  int population;
  /// All paths connecting to other Nodes
  std::vector<Path *> paths;
  /// A pointer to the NodeType of the Node
  NodeType *node_type = nullptr;
  std::string name = "";

  public:
  void setWar(War* w);
  /// The current distance from the start Node of the Label-Correcting Algorithm
  int dist = 0;
  /// The previous node of the shortest path to the start Node of the Label-Correcting Algorithm
  Node *prev = nullptr;
  Node(War* war, Empire *owner_empire, std::string name, int population);
  Node(War* war, Empire *owner_empire, std::string name, int population, bool capital);
  ~Node();
  /**
   * @brief Remove a path between this Node and another
   * @param path Path to be removed
   */
  void removePath(Path *path);
  /**
   * @brief Remove a path between this Node and another
   * @return Iterator to iterate through the adjacent towns
   */
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
  /**
   * @brief Recharge resources to the maximum capacity according to the Node's population
   */
  void rechargeResources();
  /**
   * @brief Recruit an army from the Node depending on the ArmyRatio and the number of recruits wanted.
   *
   * @param ratio
   * @param num_recruits
   * @return Army for the Empire to use
   */
  Army* recruit(ArmyRatio ratio, int num_recruits);
  /**
   * @brief A pure virtual function that will be implemented in Town and Capital
   * @param colonising_empire
   */
  void colonise(Empire *colonising_empire);
  /**
   * @brief Repopulate a town
   */
  void repopulate();
  /**
   * @brief Getter for population
   * @return Return population
   */
  int getPopulation();
  /**
   * @brief Remove an army observer from the Observer List from that specific node
   * @param army is used to remove it from the Observer List
   */
  void removeObserver(Observer* army);
  /**
   * @brief Add an army observer to the Observer List at that specific node
   * @param army is used to add it to the Observer List
   */
  void addObserver(Observer* army);
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
  void getAttacked(Army *attacking_army);
  /**
   * @brief Handles the Mediator method when the Node gets attacked
   */
  void onAttacked();
  /**
   * @brief Get armies stationed here.
   * @return Return a vector of Army pointers
   */
  std::vector<Army*> getStationedArmies();
  /**
   * @brief Clone method for the Node
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned Node
   */
  Node *clone(std::map<void*, void*> &objmap);
  /**
   * @brief A setter for the node_type
   * @param node_type A pointer to the new NodeType to be set
   */
  void setNodeType(NodeType *node_type);
  /**
   * @brief A getter for the node_type
   * @return Return a pointer to the node_type
   */
  NodeType* getNodeType();
  /**
   * @brief Get the current amount of resources in the Node
   * @return The current amount of resources in an Integer
   */
  int getResources();
  /**
   * @brief A setter for the amount of resources available in the Node
   * @param resources The new amount of resources
   */
  void setResources(int resources);
  std::string getName();
  void setName(std::string name);
};

#endif
