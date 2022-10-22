#include "Empire.h"
#include "Memento/War.h"

#include <utility>

#include "Policies/GuerillaWarfare.h"
#include "Policies/HeavyWar.h"
#include "WarStages/Attack.h"

Empire::Empire()
{
}

Empire::Empire(std::string name, War *war)
{
  this->name = name;
  this->war_stage = new Attack(this);
  this->armies = std::vector<Army *>();
  this->recruitment_policy = new HeavyWar();
  this->war_style_policy = new GuerillaWarfare();
  this->war = war;
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
    recruitArmy(owned_node);
  }
}

void Empire::advanceArmies()
{
  for (auto army : armies)
  {
    Node *current_town = army->getPosition();
    std::vector<Empire *> empires = war->getEmpires();
    for (auto empire : empires)
    {
      if (!isAlly(empire))
      {
        army->moveToTown(current_town->findShortestPathTo(war->getNodes(), empire->getCapital())[0]);
        break;
      }
    }
  }
}

void Empire::retreatArmies()
{
  for (auto army : armies)
  {
    if (army->getPosition()->getOwnerEmpire() != this)
    {
      Node *current_town = army->getPosition();
      if (current_town->getOwnerEmpire() == this)
      {
        army->moveToTown(current_town);
      }
      else
      {
        army->moveToTown(current_town->findShortestPathTo(war->getNodes(), capital)[0]);
      }
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
  if (empire != nullptr)
  {
    empire->alliances.push_back(this);
    alliances.push_back(empire);

    for (auto alliance : alliances)
    {
      if (!empire->isAlly(alliance))
      {
        alliance->joinAlliance(empire);
      }
    }

    for (auto alliance : empire->alliances)
    {
      if (!isAlly(alliance))
      {
        alliance->joinAlliance(empire);
      }
    }
  }
}

bool Empire::isAlly(Empire *empire)
{
  if (empire == this)
  {
    return true;
  }

  if (this->alliances.empty())
  {
    return false;
  }
  else
  {
    for (auto &alliance : this->alliances)
    {
      if (alliance == empire)
      {
        return true;
      }
    }
  }

  return false;
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
void Empire::removeNode(Node *node)
{
  owned_nodes.erase(std::find(owned_nodes.begin(), owned_nodes.end(), node));
}
Empire::~Empire()
{
  dieOff();
}
void Empire::unwindAlliances()
{
}
War *Empire::getWar()
{
  return war;
}
void Empire::setWar(War *war)
{
  this->war = war;
}
void Empire::removeArmy(Army *army)
{
  armies.erase(std::find(armies.begin(), armies.end(), army));
}
void Empire::addArmy(Army *army)
{
  armies.push_back(army);
}
void Empire::recruitArmy(Node *node)
{
  int population = node->getPopulation();
  ArmyRatio army_ratio = war_style_policy->createArmyRatio();
  int army_size = recruitment_policy->calculateRecruits(population);

  Army army = node->recruit(army_ratio, army_size);

  armies.push_back(&army);
}

std::vector<Empire *> Empire::getAlliances()
{
  return this->alliances;
}

/**
 * @todo Implement this function
 */
Empire::Empire(std::string name)
{
  this->name = name;
  this->war_stage = new Attack(this);
  this->armies = std::vector<Army *>();
  this->recruitment_policy = new HeavyWar();
  this->war_style_policy = new GuerillaWarfare();
  this->war = nullptr;
}
void Empire::setCapital(Node *capital)
{
  this->capital = capital;
}
void Empire::dieOff()
{
  for (auto empire : alliances)
  {
    empire->removeAlliance(this);
  }
  alliances.clear();

  for (auto node : owned_nodes)
  {
    node->makeFreeCity();
  }
  owned_nodes.clear();
  capital = nullptr;

  for (auto army : armies)
  {
    delete army;
  }
  armies.clear();

  if (war_style_policy != nullptr)
  {
    delete war_style_policy;
  }
  if (recruitment_policy != nullptr)
  {
    delete recruitment_policy;
  }
  if (war_stage != nullptr)
  {
    delete war_stage;
  }
}
std::vector<Army *> Empire::getArmies()
{
  return armies;
}

Empire *Empire::clone(std::map<void *, void *> &objmap)
{
  if (objmap.find(this) != objmap.end())
  {
    return (Empire *)((*objmap.find(this)).second);
  }
  else
  {
    Empire *temp = new Empire();
    objmap.insert(std::pair<void *, void *>(this, temp));

    std::vector<Empire *> newalliancees;
    for (auto al : alliances)
    {
      if (al)
        newalliancees.push_back(al->clone(objmap));
    }
    temp->alliances = newalliancees;

    std::vector<Army *> newarmies;
    for (auto army : armies)
    {
      if (army)
        newarmies.push_back(army->clone(objmap));
    }
    temp->armies = newarmies;

    if (capital)
      temp->capital = capital->clone(objmap);

    temp->name = name;

    std::vector<Node *> newownednodes;
    for (auto node : owned_nodes)
    {
      if (node)
        newownednodes.push_back(node->clone(objmap));
    }
    temp->owned_nodes = newownednodes;

    temp->prev_num_nodes = prev_num_nodes;

    if (recruitment_policy)
      temp->recruitment_policy = recruitment_policy->clone(objmap);

    if (war_stage)
      temp->war_stage = war_stage->clone(objmap);

    if (war_style_policy)
      temp->war_style_policy = war_style_policy->clone(objmap);

    return temp;
  }
}
void Empire::removeAlliance(Empire *empire)
{
  alliances.erase(std::find(alliances.begin(), alliances.end(), empire));
}
std::string Empire::getName()
{
  return name;
}
