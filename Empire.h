#ifndef EMPIRE_H
#define EMPIRE_H

#include <string>
#include <vector>

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
  std::vector<Node *> owned_nodes;
  std::string name;
  ColonyPolicy *colony_policy;
  WarStylePolicy *war_style_policy;
  RecruitmentPolicy *recruitment_policy;
  WarStage *war_stage;
  Alliance **alliances;
  std::vector<Army> armies;
  War *war;
  Node *capital;
  int prev_num_nodes = 0;

  public:
  Empire(std::string name);
  void algorithm();
  void request();
  void action();
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
};

#endif
