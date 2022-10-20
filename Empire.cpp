#include "Empire.h"
#include "Memento/War.h"

#include <utility>

#include "WarStages/Attack.h"
#include "Policies/Assimilate.h"
#include "Policies/HeavyWar.h"
#include "Policies/GuerillaWarfare.h"

Empire::Empire(std::string name, War* war)
{
  this->name      = name;
  this->war_stage = new Attack(this);
  this->armies    = std::vector<Army*>();
  this->colony_policy = new Assimilate();
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
    Node *current_town            = army->getPosition();
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
  for (int army_index = 0; army_index < armies.size(); army_index++)
  {
    Node *current_town = armies[army_index]->getPosition();
    if (current_town->getOwnerEmpire() == this)
    {
      armies[army_index]->moveToTown(current_town);
    }
    else
    {
      armies[army_index]->moveToTown(current_town->findShortestPathTo(war->getNodes(), capital)[0]);
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
    if(empire != NULL)
    {
        if(empire->alliances.empty())
        {
            this->alliances.push_back(empire);
        }
        else
        {
            for(int i = 0; i < empire->alliances.size(); i++)
            {
                this->alliances.push_back(empire->alliances.at(i));
            }
        }

        if(this->alliances.empty())
        {
            empire->alliances.push_back(this);
        }
        else
        {
            for(int i = 0; i < this->alliances.size(); i++)
            {
                empire->alliances.push_back(this->alliances.at(i));
            }
        }
    }
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
    if (empire == this) {
      return true;
    }

    if(this->alliances.empty())
    {
        return false;
    }
    else
    {
        for(int i = 0; i < this->alliances.size(); i++)
        {
            if(this->alliances.at(i) == empire)
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
  owned_nodes.erase(std::remove(owned_nodes.begin(), owned_nodes.end(), node), owned_nodes.end());
}
Empire::~Empire()
{
  for (auto node : owned_nodes)
  {
    node->makeFreeCity();
    owned_nodes.erase(std::remove(owned_nodes.begin(), owned_nodes.end(), node), owned_nodes.end());
  }
  delete colony_policy;
  delete war_style_policy;
  delete recruitment_policy;
  delete war_stage;
  unwindAlliances();
}
void Empire::unwindAlliances()
{
}
War *Empire::getWar()
{
  return war;
}
void Empire::setWar(War* war)
{
  this->war = war;
}
void Empire::removeArmy(Army * army)
{
  armies.erase(std::remove(armies.begin(), armies.end(), army), armies.end());
  delete army;
}
void Empire::addArmy(Army *army)
{
  armies.push_back(army);
}
void Empire::recruitArmy(Node* node)
{
  int population       = node->getPopulation();
  ArmyRatio army_ratio = war_style_policy->createArmyRatio();
  int army_size        = recruitment_policy->calculateRecruits(population);

  Army army = node->recruit(army_ratio, army_size);

  armies.push_back(&army);
}

std::vector<Empire*> Empire::getAlliances()
{
    return this->alliances;
}

/**
 * @todo Implement this function
*/
Empire* Empire::clone(){
  return NULL;
}
Empire::Empire(std::string name)
{
  this->name      = name;
  this->war_stage = new Attack(this);
  this->armies    = std::vector<Army*>();
  this->colony_policy = new Assimilate();
  this->recruitment_policy = new HeavyWar();
  this->war_style_policy = new GuerillaWarfare();
  this->war = nullptr;
}
void Empire::setCapital(Node* capital)
{
  this->capital = capital;
}
void Empire::dieOff()
{
  for (auto node : owned_nodes){
    node->makeFreeCity();
    owned_nodes.erase(std::remove(owned_nodes.begin(), owned_nodes.end(), node), owned_nodes.end());
  }
  capital = nullptr;
  armies.clear();
}
