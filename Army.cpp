#include "Army.h"
#include "Empire.h"
#include "Memento/War.h"

Army::Army() {}

Army::Army( War* war, Node *current_position, Empire *owner_empire)
{
  this->war = war;

  position = current_position;
}

void Army::update()
{
  moveToTown(subject);
}

void Army::attackTown(Node *town)
{
  if (!(getOwnerEmpire()->isAlly(town->getOwnerEmpire())))
  {
#ifndef disable_output
    std::cout << "Army of " << getOwnerEmpire()->getName() << " is attacking "
              << town->getName() << std::endl;
#endif
    cout << "A" << endl;
    town->getAttacked(this);
    cout << "Z" << endl;
  }
}

void Army::moveToTown(Node *town)
{
  if (town != position)
  {

    if (subject != nullptr)
    {
      subject->removeObserver(this);
    }

    subject = position;

    position = town;

    subject->addObserver(this);

#ifndef disable_output
    std::cout << "Army from " << getOwnerEmpire()->getName() << " is marching towards "
              << town->getName() << std::endl;
#endif

    for (auto path : subject->getPaths())
    {
      if (path->getOppositeEnd(subject) == position)
      {
        path->calculate_losses(this);
        break;
      }
    }

    if (units.size() == 0)
    {
      delete this;
    }
    else
    {
      attackTown(position);
    }
  }
}
Node *Army::getPosition()
{
  return position;
}

int Army::getResource() { return resources; }

void Army::setResource(int new_resource) { resources = new_resource; }

int Army::getArmySize() { return units.size(); }
Army::~Army()
{
  if (getOwnerEmpire() != nullptr)
  {
    getOwnerEmpire()->removeArmy(this);
  }
  if (subject != nullptr)
  {
    subject->removeObserver(this);
  }
}
Empire *Army::getOwnerEmpire()
{
  for (auto empire : war->getEmpires())
  {
    for (auto army : empire->getArmies())
    {
      if (army == this)
      {
        return empire;
      }
    }
  }

  return nullptr;
}

int Army::getResources()
{
  return resources;
}
int Army::getNumUnits()
{
  int total_units = 0;
  for (Unit unit : units)
  {
    total_units++;
  }
  return total_units;
}
void Army::killRandomUnit()
{
  if (units.size() != 0)
  {
    int random_num                 = rand() % (units.size());
    std::vector<Unit>::iterator it = units.begin() + random_num;
    units.erase(it);
  }

  if (units.size() == 0)
  {

#ifndef disable_output
    std::cout << "Army " << getOwnerEmpire()->getName()
              << " has lost all troops and disbanded" << std::endl;
#endif
  }
}
void Army::addUnit(Unit unit) { units.push_back(unit); }
void Army::rechargeResources() { resources = getArmySize(); }

Army *Army::clone(std::map<void *, void *> &objmap)
{
  if (objmap.find(this) != objmap.end())
  {
    return (Army *) ((*objmap.find(this)).second);
  }
  else
  {
    Army *temp = new Army();
    objmap.insert(std::pair<void *, void *>(this, temp));

    temp->war = war;

    temp->observer_state = observer_state;

    if (position)
      temp->position = position->clone(objmap);

    temp->resources = resources;

    if (subject)
      temp->subject = subject->clone(objmap);

    std::vector<Unit> newunits;
    for (auto unit : units)
    {
      if (&unit)
        newunits.push_back(*unit.clone(objmap));
    }
    temp->units = newunits;
    return temp;
  }
}