#include "Army.h"
#include "Empire.h"
#include "Memento/War.h"

Army::Army(Node* current_position, Empire* owner_empire)
{
  position = current_position;
  empire = owner_empire;
}

void Army::update()
{
  // TODO - implement Army::update
  throw "Not yet implemented";
}

void Army::attackTown(Node *town)
{
  if (!(empire->isAlly(town->getOwnerEmpire()))){
    town->getAttacked(this);
  }
}

void Army::moveToTown(Node *town)
{
  // TODO - implement Army::moveToTown
  throw "Not yet implemented";
}
Node *Army::getPosition()
{
  return position;
}
Army::~Army()
{
}
Empire *Army::getOwnerEmpire()
{
  return empire;
}

int Army::getResources()
{
    return resources;
}
int Army::getNumUnits()
{
  int total_units = 0;
  for (Unit unit : units){
    total_units++;
  }
  return total_units;
}
void Army::killSelf()
{
  empire->removeArmy(this);
}
void Army::killRandomUnit()
{
  //TODO - Random Removal
  units.pop_back();
  if (units.size() == 0) {
    if (position != nullptr) {
      position->removeStationedArmy(this);
    }
    killSelf();
  }
}
