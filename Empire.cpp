#include "Empire.h"

#include <utility>

#include "Attack.h"

Empire::Empire(std::string name)
{
  this->name      = name;
  this->war_stage = new Attack(this);
  this->armies    = std::vector<Army>();
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

    armies.push_back(army);
  }
}

void Empire::advanceArmies()
{
  for (int army_index = 0; army_index < armies.size(); army_index++)
  {
    Node *current_town = armies[army_index].getPosition();
    // TODO - Find closest enemy town to current_town
    Node *closest_enemy_town = current_town;
    armies[army_index].moveToTown(closest_enemy_town);
  }
}

void Empire::retreatArmies()
{
  for (int army_index = 0; army_index < armies.size(); army_index++)
  {
    Node *current_town = armies[army_index].getPosition();
    // TODO - Find closest enemy town to current_town
    Node *closest_ally_town = current_town;
    armies[army_index].moveToTown(closest_ally_town);
  }
}

void Empire::restoreTowns()
{
  for (int node_index = 0; node_index < owned_nodes.size(); node_index++)
  {
    // TODO - Find out if town is connected
    bool town_is_connected = true;
    if (town_is_connected)
    {
      owned_nodes[node_index]->rechargeResources();
      owned_nodes[node_index]->repopulate();
    }
  }
}

void Empire::takeTurn()
{
  war_stage->takeTurn();
}

void Empire::addTown(Node *town)
{
  owned_nodes.push_back(town);
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
