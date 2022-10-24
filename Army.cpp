#include "Army.h"
#include "Empire.h"
#include "Memento/War.h"

Army::Army(Node* current_position, Empire* owner_empire)
{
  position = current_position;
  empire = owner_empire;

  position->addObserver(this);
}

void Army::update()
{
    moveToTown(subject);
}

void Army::attackTown(Node *town)
{
  if (!(empire->isAlly(town->getOwnerEmpire()))){
    town->getAttacked(this);
  }
}

void Army::moveToTown(Node *town)
{
    if (town == position)
    {
        std::cout << "Army is already in that town" << std::endl;

    }

    else
    {

      position->removeObserver(this);

      position = town;

      position->addObserver(this);



      //TODO - Add position name to display below
      std::cout << "Army has been moved to " << std::endl;
    }
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
int Army::getNumUnits()
{
  return units.size();
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
void Army::addUnit(Unit unit)
{
  units.push_back(unit);
}
