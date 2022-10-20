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
  std::vector<Unit> units;
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
     * @brief A method to move an Army to another Node
     * @param town The town which will be moved to
     */
  void moveToTown(Node *town);

  /**
     * @brief Return the current position of the Army
     * @return Returns a Node pointer
     */
  Node *getPosition();
};

#endif
