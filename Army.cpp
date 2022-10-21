#include "Army.h"
#include "Empire.h"
#include "Memento/War.h"

Army::Army(Node *current_position, Empire *owner_empire)
{
  position = current_position;
  empire   = owner_empire;
}

void Army::update()
{
  // TODO - implement Army::update
  throw "Not yet implemented";
}

void Army::attackTown(Node *town)
{
  if (!(empire->isAlly(town->getOwnerEmpire())))
  {
    town->getAttacked(this);
  }
}

void Army::moveToTown(Node *town)
{
  position = town;
  attackTown(town);
}
//-------------------------------------------ADDED BY DHARSHAN GOPAUL
int Army::getResource()
{
  return resources;
}

void Army::setResource(int new_resource)
{
  resources = new_resource;
}

int Army::getArmySize()
{
  return units.size();
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
  if (position != nullptr)
  {
    position->removeStationedArmy(this);
  }
  empire->removeArmy(this);
}
void Army::killRandomUnit()
{
  int random_num                 = rand() % (units.size());
  std::vector<Unit>::iterator it = units.begin() + random_num;
  units.erase(it);

  if (units.size() == 0)
  {
    if (position != nullptr)
    {
      position->removeStationedArmy(this);
    }
    killSelf();
  }
}
void Army::addUnit(Unit unit)
{
  units.push_back(unit);
}
void Army::rechargeResources()
{
  resources = getArmySize();
}
