#include "Empire.h"
#include "War.h"

#include <utility>

#include "Attack.h"

Empire::Empire(std::string name)
{
  this->name      = name;
  this->war_stage = new Attack(this);
  this->armies    = std::vector<Army>();
  this->alliances = std::vector<AllianceComponent*>(); //Create alliance with yourself
  this->alliances.push_back(this);
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
    Node *current_town            = armies[army_index].getPosition();
    std::vector<Empire *> empires = war->getEmpires();
    for (auto empire : empires)
    {
      if (!isAlly(empire))
      {
        armies[army_index].moveToTown(current_town->findShortestPathTo(war->getNodes(), empire->getCapital())[0]);
        break;
      }
    }
  }
}

void Empire::retreatArmies()
{
  for (int army_index = 0; army_index < armies.size(); army_index++)
  {
    Node *current_town = armies[army_index].getPosition();
    if (current_town->getOwnerEmpire() == this)
    {
      armies[army_index].moveToTown(current_town);
    }
    else
    {
      armies[army_index].moveToTown(current_town->findShortestPathTo(war->getNodes(), capital)[0]);
    }
  }
}

void Empire::restoreTowns()
{
  for (int node_index = 0; node_index < owned_nodes.size(); node_index++)
  {
    if (owned_nodes[node_index]->connectedToCapital(war->getNodes(), capital))
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
  this->alliances = empire->alliances;
  this->alliances.at(0)->add(this);
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
bool Empire::isAlly(Empire *empire)
{
}
Node *Empire::getCapital()
{
  return capital;
}
std::vector<Node *> Empire::getNodes()
{
  return owned_nodes;
}
int Empire::getPrevNumNodes()
{
  return prev_num_nodes;
}
void Empire::setState(WarStage *state)
{
  this->war_stage = state;
}
void Empire::setPrevNumNodes(int num_nodes)
{
  prev_num_nodes = num_nodes;
}
