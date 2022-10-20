#ifndef EMPIRE_H
#define EMPIRE_H

#include <string>
#include <vector>
#include <algorithm>

#include "Alliance/Alliance.h"
#include "Alliance/AllianceComponent.h"

#include "Army.h"

#include "Graph/Node.h"

#include "Policies/ColonyPolicy.h"
#include "Policies/RecruitmentPolicy.h"
#include "Policies/WarStylePolicy.h"

#include "WarStages/WarStage.h"

class War;

class Empire : public AllianceComponent
{
  private:
  /// A vector of all Nodes controlled by the Empire
  std::vector<Node *> owned_nodes;
  /// Name of the Empire
  std::string name;
  /// Policy determining what to do with captured towns
  ColonyPolicy *colony_policy;
  /// Policy determining the ratio of different troops in this Empire's armies
  WarStylePolicy *war_style_policy;
  /// Policy determining the number of recruits based on a towns population
  RecruitmentPolicy *recruitment_policy;
  /// The current stage of war (Attacking or Defending)
  WarStage *war_stage;
  std::vector<AllianceComponent *>alliances;
  /// A vector of all controlled armies
  std::vector<Army> armies;
  /// A pointer to the War object, which hold information on all other entities in the war
  War *war;
  /// The Empire's capital Node
  Node *capital;
  /// The number of controlled nodes in the the previous round
  int prev_num_nodes = 0;

  public:
  Empire(std::string name);
  ~Empire();
  void algorithm();
  void request();
  void action();
  /**
   * @brief Removes a Node from the Empire's owned_nodes array
   * @param node Node to be removed
   */
  void removeNode(Node *node);
  /**
   * @brief A method to recruit armies from all qualifying Nodes that the Empire owns
   * This method loops through all owned Nodes and generates an ArmyRatio for each of them. It will then recruit an Army from each town and station that Army at the town.
   */
  void recruit();
  /**
   * @brief Calls the takeTurn() method of the active WarStage
   */
  void takeTurn();
  /**
   * @brief Advance all Armies to attack new enemy Nodes
   * This method loops through all owned armies. For each army, it finds the closest enemy Node and moves the Army to the first Node on the path to that enemy Node
   */
  void advanceArmies();
  /**
   * @brief Retreat all Armies to defend ally Nodes
   * This method loops through all owned armies. For each army, it finds the closest ally Node and moves the Army to the first Node on the path to that ally Node
   */
  void retreatArmies();
  /**
   * @brief Restores all resources and some population to owned nodes connected to the capital
   */
  void restoreTowns();
  /**
   * @brief Add a town to the owned_nodes vector of the Empire
   * @param town The town that the Empire now owns
   */
  void addTown(Node *town);
  void joinAlliance(Empire *empire);
  void add(AllianceComponent *alliance_component);
  void remove(AllianceComponent *alliance_component);
  /**
   * @brief Determine if an Empire is an ally
   *
   * @param empire The empire to test
   * @return Return a boolean value
   */
  bool isAlly(Empire *empire);
  /**
   * @brief A getter for all the Nodes the Empire owns
   * @return Return a vector of Node pointers
   */
  std::vector<Node *> getNodes();
  AllianceComponent *getChild(int index);
  /**
   * @brief A getter for the Capital Node of the Empire
   * @return Return a Node pointer
   */
  Node *getCapital();
  /**
   * @brief A getter for the prev_num_nodes attribute
   * @return Return an int
   */
  int getPrevNumNodes();
  /**
   * @brief A setter for the prev_num_nodes attribute
   * @param num_nodes The number of nodes that the Empire owns
   */
  void setPrevNumNodes(int num_nodes);
  /**
   * @brief Set the state of the Empire
   * @param state New state of the Empire
   */
  void setState(WarStage *state);
  void unwindAlliances();
};

#endif
