#include "Army.h"
#include "Empire.h"
#include "Memento/War.h"

Army::Army(){

}

Army::Army(Node *current_position, Empire *owner_empire)
{
  position = current_position;
  empire   = owner_empire;

  position->addStationedArmy(this);
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
  if (empire != nullptr)
  {
    empire->removeArmy(this);
  }
  if (position != nullptr)
  {
    position->removeStationedArmy(this);
  }
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
    delete this;
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

Army* Army::clone(std::map<void*,void*> &objmap){
  if(objmap.find(this)!=objmap.end()){
    return (Army*)((*objmap.find(this)).second);
  }
  else{
    Army* temp = new Army();
    objmap.insert(std::pair<void*,void*>(this, temp));

    if(empire)
      temp->empire = empire->clone(objmap);
    
    temp->observer_state = observer_state;
    
    if(position)
      temp->position = position->clone(objmap);
    
    temp->resources = resources;
    
    if(subject)
      temp->subject = subject->clone(objmap);

    std::vector<Unit> newunits;
    for(auto unit: units){
      if(&unit)
        newunits.push_back(*unit.clone(objmap));
    }
    temp->units = newunits;
    return temp;
  }
}