#ifndef EMPIRE_H
#define EMPIRE_H

#include <string>
#include <vector>
#include <map>

#include "Army.h"

#include "Graph/Node.h"

#include "Policies/RecruitmentPolicy.h"
#include "Policies/WarStylePolicy.h"

#include "WarStages/WarStage.h"

class War;

class Empire
{
  private:
  Empire();
  /// A vector of all Nodes controlled by the Empire
  std::vector<Node *> owned_nodes;
  /// Name of the Empire
  std::string name;
  /// Policy determining the ratio of different troops in this Empire's armies
  WarStylePolicy *war_style_policy = nullptr;
  /// Policy determining the number of recruits based on a towns population
  RecruitmentPolicy *recruitment_policy = nullptr;
  /// The current stage of war (Attacking or Defending)
  WarStage *war_stage = nullptr;
  /// A vector containing all the empires that is in an alliance
  std::vector<Empire *> alliances;
  /// A vector of all controlled armies
  std::vector<Army *> armies;
  /// A pointer to the War object, which hold information on all other entities in the war
  War *war = nullptr;
  /// The Empire's capital Node
  Node *capital = nullptr;
  /// The number of controlled nodes in the the previous round
  int prev_num_nodes = 0;

  public:  
  Empire(std::string name, War *war);
  Empire(std::string name);
  ~Empire();
  /**
   * @brief A getter for the Empire's name
   * @return Return a string
   */
  std::string getName();
  /**
   * @brief A method called after an Empire's capital is colonised to make it invalid.
   */
  void dieOff();
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
   * @brief Recruit an Army from the specific Node
   * @param node Node to be recruited from
   */
  void recruitArmy(Node *node);
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
  /**
   * @brief Request an alliance with the passed in empire
   * @param empire Pointer to the empire that this empire want to form an alliance with
   */
  void requestAlliance(Empire * empire);
    /**
   * @brief Consider to form an alliance with the passed in empire by checking if it will benefit from the alliance
   * @param empire Pointer to the empire that this empire want to form an alliance with
   */
  void considerAlliance(Empire *empire);
  /**
    * @brief Join the alliance of the passed in empire. If the empire is not in an alliance it will create an alliance between the two empires
    * @param empire The empire to form the alliance with
    */
  void joinAlliance(Empire *empire);
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
  /**
   * @brief A getter for the Capital Node of the Empire
   * @return Return a Node pointer
   */
  Node *getCapital();
  /**
   * @brief Set the capital Node of an Empire
   * @param capital The capital Node
   */
  void setCapital(Node* capital);
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
  /**
   * @brief Get the War attribute
   * @return Return a War pointer
   */
  War *getWar();
  /**
   * @brief Set the War attribute
   * @param war New War
   */
  void setWar(War *war);
  /**
   * @brief Remove and delete Army from the armies vector.
   */
  void removeArmy(Army *);
  /**
   * @brief Return the current alliances of the empire
   */
  std::vector<Empire *> getAlliances();
  /**
   * @brief Add an Army to the Empire
   * @param army
   */
  void addArmy(Army *army);
  /**
   * @brief Return the vector of owned armies
   * @return Vector of Army pointers
   */
  std::vector<Army*> getArmies();
  /**
   * @brief Clone method for the Empire
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned Empire
   */
  Empire* clone(std::map<void*, void*> &objmap);
  /**
   * @brief Remove an Empire from this Empire's alliance
   * @param empire The Empire to be removed from the alliance.
   */
  void removeAlliance(Empire* empire);

  std::string getRecruitmentPolicy();

  void setRecruitmentPolicy(RecruitmentPolicy* policy);

  std::string getWarStylePolicy();

  void setWarStylePolicy(WarStylePolicy* policy);

};

#endif
