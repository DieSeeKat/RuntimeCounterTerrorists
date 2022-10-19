#ifndef ARMY_H
#define ARMY_H

#include <string>

#include "Observer.h"

class Node;
class Empire;

class Army : Observer
{

  private:
  std::string observer_state;
  Node *subject;
  Node *position;
  int resources;
  Empire *empire;
  //--------------------------------------------------ADDED BY DHARSHAN GOPAUL
  int army_size;

  public:
  void update();

  void attackTown(Node *town);

  void moveToTown(Node *town);

  //--------------------------------------------------ADDED BY DHARSHAN GOPAUL
  int getResource();

  void setResource(int new_resource);

  int getArmySize();

  void setArmySize(int new_size);
  void defendTown(Node *town);

  Node *getPosition();
};

#endif
