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

    int enemy_units_in_footmen = 0;
    int ally_units_in_footmen = 0;

    //Calculate enemy_units_in_footmen
    std::vector<Army*> armies_on_node = std::vector<Army*>();
    for (Army* army : town->getStationedArmies()){
      if (town->getOwnerEmpire()->isAlly(army->getOwnerEmpire())){
        enemy_units_in_footmen += army->getNumUnits();
      }
    }

    //Calculate ally_units_in_footmen
    ally_units_in_footmen += getNumUnits();

    int difference = ally_units_in_footmen - enemy_units_in_footmen;

    if (difference >= 0) {
      for (Army* army : town->getStationedArmies()) {
        town->removeStationedArmy(army);
      }
      town->colonise(empire);
    }else {
      for (int i = 0; i < ally_units_in_footmen; i++) {
        if (town->getStationedArmies().size() > 0)
        {
          town->getStationedArmies()[0]->killRandomUnit();
        }
      }
      killSelf();
    }
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
