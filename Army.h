#ifndef ARMY_H
#define ARMY_H

#include <string>
#include <vector>

#include "Observer/Observer.h"
#include "Units/Unit.h"

class Node;

class Empire;

class Army : Observer
{

  private:
  std::string observer_state;
  Node *subject;
  /// The current Node at which the Army is stationed
  Node *position;
  /// The number of resources that the Army has
  int resources;
  /// The controlling Empire of the Army
  Empire *empire;
  /// The vector of all the Units in the Army
  std::vector<Unit> units;
  //--------------------------------------------------
  public:
  Army(Node* current_position, Empire* owner_empire);
  ~Army();

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

  //--------------------------------------------------ADDED BY DHARSHAN GOPAUL
  int getResource();

  void setResource(int new_resource);

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
  int getNumUnits();
  /**
   * @brief Will notify the owning Empire to delete and remove the current Army
   */
  void killSelf();
  /**
   * @brief Kills a random Unit from the units vector
   */
  void killRandomUnit();
  void rechargeResources();
};

#endif
