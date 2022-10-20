#ifndef ARMY_H
#define ARMY_H

#include <string>
#include <iostream>

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

  public:

  Army(Node* current_position);

  void update();

  void attackTown(Node *town);

  void moveToTown(Node *town);

  void defendTown(Node *town);


  Node *getPosition();
};

#endif
