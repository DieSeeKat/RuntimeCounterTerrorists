#ifndef ARMY_H
#define ARMY_H

#include <string>
#include <iostream>
#include <vector>

#include "Observer/Observer.h"
#include "Units/Unit.h"
#include "Memento/War.h"


class Node;

class Empire;

class Army : public Observer
{
  private:
  Army();
  std::string observer_state;
  Node *subject = nullptr;
  /// The current Node at which the Army is stationed
  Node *position = nullptr;
  /// The number of resources that the Army has
  int resources = 0;
  War* war = nullptr;
  /// The vector of all the Units in the Army
  std::vector<Unit> units;
  //--------------------------------------------------
  public:
  Army(War* war, Node* current_position, Empire* owner_empire);
  ~Army();

  /**
   * @brief A method to to update the position of an army
   */
  void update();
  /**
   * @brief A method to allow the Army to siege a Node
   * @param town The town which will be attacked
   */
  void attackTown(Node *town);
  /**
   * @brief Add a new Unit to the Army
   * @param unit The unit to be added
   */
  void addUnit(Unit unit);
  /**
   * @brief A method to move an Army to another Node
   * @param town The town which will be moved to
   */
  void moveToTown(Node *town);
  /**
   * @brief Return the current position of the Army
   * @return Returns a Node pointer
   */
  Node *getPosition();

  /**
   * @breif A getter for the current resources of the Army
   * @return Return an integer
   */
  int getResource();

  /**
   * @brief A setter for the amount of resources of this Army
   * @param new_resource The new amount of resources in an integer
   */
  void setResource(int new_resource);

  /**
   * @brief A getter for the size of the Army
   * @return Return an int referring to the size of the Army
   */
  int getArmySize();

  /**
   * @brief Get the empire that owns the current Army
   * @return Return an Empire pointer
   */
  Empire* getOwnerEmpire();
  /**
   * @brief Calculate and return the number of Units in the Army
   * @return Return an integer representing the number of Units
   */

  int getResources();
  int getNumUnits();
  /**
   * @brief Kills a random Unit from the units vector
   */
  void killRandomUnit();
  /**
   * @brief Recharge the amount of resources of the Army to the maximum amount
   */
  void rechargeResources();
  /**
   * @brief Clone method for the Army
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned Army
   */
  Army* clone(std::map<void*,void*> &objmap);
};

#endif
