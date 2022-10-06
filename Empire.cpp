#include "Empire.h"

#include <utility>

#include "Attack.h"

Empire::Empire(std::string name)
{
  this->name      = name;
  this->war_stage = new Attack();
}

void Empire::algorithm()
{
  // TODO - implement Empire::algorithm
  throw "Not yet implemented";
}

void Empire::request()
{
  // TODO - implement Empire::request
  throw "Not yet implemented";
}

void Empire::action()
{
  // TODO - implement Empire::action
  throw "Not yet implemented";
}

void Empire::recruit()
{
  for (auto &owned_node : owned_nodes)
  {
    int population       = owned_node->getPopulation();
    ArmyRatio army_ratio = war_style_policy->createArmyRatio();
    int army_size        = recruitment_policy->calculateRecruits(population);

    Army army = owned_node->recruit(army_ratio, army_size);
  }
}

void Empire::takeTurn()
{
  // TODO - implement Empire::takeTurn
  throw "Not yet implemented";
}

void Empire::addTown(Node *town)
{
  // TODO - implement Empire::addTown
  throw "Not yet implemented";
}

void Empire::joinAlliance(Empire *empire)
{
  // TODO - implement Empire::joinAlliance
  throw "Not yet implemented";
}

void Empire::add(AllianceComponent *alliance_component)
{
}

void Empire::remove(AllianceComponent *alliance_component)
{
}

AllianceComponent *Empire::getChild(int index)
{
  return nullptr;
}
