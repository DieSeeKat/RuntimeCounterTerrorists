#include <climits>
#include <cmath>
#include <deque>
#include <vector>

#include "../Barracks/ArcheryBarracks.h"
#include "../Barracks/Barracks.h"
#include "../Barracks/CavalryBarracks.h"
#include "../Barracks/FootmenBarracks.h"
#include "../Barracks/SlingerBarracks.h"
#include "../Empire.h"
#include "Capital.h"
#include "Node.h"
#include "Town.h"

#include "../Units/Unit.h"

Node::Node() {}

NodeIterator *Node::createIterator() { return new NodeIterator(this); }

void Node::changed()
{
  // TODO - implement Node::changed
  throw "Not yet implemented";
}

Army *Node::recruit(ArmyRatio ratio, int num_recruits)
{
  Barracks *archer_barracks  = new ArcheryBarracks();
  Barracks *cavalry_barracks = new CavalryBarracks();
  Barracks *footmen_barracks = new FootmenBarracks();
  Barracks *slinger_barracks = new SlingerBarracks();

  archer_barracks->createUnits(ceil(ratio.archer_ratio * num_recruits));
  cavalry_barracks->createUnits(ceil(ratio.cavalry_ratio * num_recruits));
  footmen_barracks->createUnits(ceil(ratio.footmen_ratio * num_recruits));
  slinger_barracks->createUnits(ceil(ratio.slinger_ratio * num_recruits));

  Army *new_army = new Army(war, this, owner_empire);

  for (auto unit : archer_barracks->getUnits())
  {
    new_army->addUnit(*unit);
  }
  for (auto unit : cavalry_barracks->getUnits())
  {
    new_army->addUnit(*unit);
  }
  for (auto unit : footmen_barracks->getUnits())
  {
    new_army->addUnit(*unit);
  }
  for (auto unit : slinger_barracks->getUnits())
  {
    new_army->addUnit(*unit);
  }

  return new_army;
}
int Node::getResources()
{
  return resources;
}
void Node::repopulate() { population = ceil(population * 1.1); }
int Node::getPopulation() { return population; }
void Node::rechargeResources() { resources = population; }
std::vector<Node *> Node::findShortestPathTo(std::vector<Node *> nodes,
                                             Node *end_node)
{
  std::deque<Node *> to_be_checked;

  for (auto node : nodes)
  {
    node->dist = INT_MAX;
    node->prev = nullptr;
  }
  this->dist = 0;
  to_be_checked.push_back(this);

  while (!to_be_checked.empty())
  {
    Node *curr = to_be_checked.front();
    to_be_checked.pop_front();
    for (auto path : curr->paths)
    {
      int newDist = curr->dist + 1;
      if (newDist < path->getOppositeEnd(curr)->dist)
      {
        path->getOppositeEnd(curr)->dist = newDist;
        path->getOppositeEnd(curr)->prev = curr;
        if (std::find(to_be_checked.begin(), to_be_checked.end(),
                      path->getOppositeEnd(curr)) == to_be_checked.end())
        {
          to_be_checked.push_back(path->getOppositeEnd(curr));
        }
      }
    }
  }

  std::vector<Node *> return_vector;
  Node *curr_node = end_node;
  while (curr_node != this && curr_node != nullptr)
  {
    return_vector.push_back(curr_node);
    curr_node = curr_node->prev;
  }

  std::reverse(return_vector.begin(), return_vector.end());

  return return_vector;
}
Empire *Node::getOwnerEmpire() { return owner_empire; }
bool Node::connectedToCapital(std::vector<Node *> nodes, Node *capital)
{
  if (this == capital)
  {
    return true;
  }

  std::deque<Node *> to_be_checked;

  for (auto node : nodes)
  {
    node->dist = INT_MAX;
    node->prev = nullptr;
  }
  this->dist = 0;
  to_be_checked.push_back(this);

  while (!to_be_checked.empty())
  {
    Node *curr = to_be_checked.front();
    to_be_checked.pop_front();
    for (auto path : curr->paths)
    {
      int newDist = curr->dist + 1;
      if (newDist < path->getOppositeEnd(curr)->dist &&
          path->getOppositeEnd(curr)->getOwnerEmpire() == owner_empire)
      {
        path->getOppositeEnd(curr)->dist = newDist;
        path->getOppositeEnd(curr)->prev = curr;
        if (std::find(to_be_checked.begin(), to_be_checked.end(),
                      path->getOppositeEnd(curr)) == to_be_checked.end())
        {
          to_be_checked.push_back(path->getOppositeEnd(curr));
        }
      }
    }
  }

  return capital->prev != nullptr;
}

std::vector<Path *> Node::getPaths() { return paths; }
Node::Node(War* war, Empire *owner_empire, std::string name, int population)
{
  this->war = war;
  this->owner_empire      = owner_empire;
  this->population_empire = owner_empire;
  this->population        = population;
  this->resources         = population;
  this->name              = name;
  this->node_type         = new Town(this);

  owner_empire->addTown(this);
}
void Node::addPath(Path *path) { paths.push_back(path); }
void Node::addPathTo(Node *node)
{
  Path *new_path = new Path(this, node);
  addPath(new_path);
  node->addPath(new_path);
}
void Node::onAttacked() { owner_empire->recruitArmy(this); }
Node::~Node()
{
  std::vector<Path *> path_pointers = paths;
  for (auto path : path_pointers)
  {
    delete path;
  }
  paths.clear();
}
void Node::removePath(Path *path)
{
  paths.erase(std::find(paths.begin(), paths.end(), path));
}
void Node::makeFreeCity() { owner_empire = nullptr; }

void Node::getAttacked(Army *attacking_army)
{
  int friendly_units_in_footmen = 0;
  int enemy_units_in_footmen    = 0;

  // Calculate friendly_units_in_footmen
  for (Army *army : getStationedArmies())
  {
    if (getOwnerEmpire() == army->getOwnerEmpire() ||
        getOwnerEmpire()->isAlly(army->getOwnerEmpire()))
    {
      friendly_units_in_footmen += army->getNumUnits();
    }
  }

  // Calculate enemy_units_in_footmen
  enemy_units_in_footmen += attacking_army->getNumUnits();

  if (enemy_units_in_footmen > friendly_units_in_footmen)
  {
    for (Army *army : getStationedArmies())
    {
      if (army != attacking_army)
      {
        delete army;
      }
    }
    for (int i = 0; i < friendly_units_in_footmen; i++)
    {
      attacking_army->killRandomUnit();
    }
    this->colonise(attacking_army->getOwnerEmpire());
    notify();
  }
  else if (enemy_units_in_footmen == friendly_units_in_footmen)
  {
    for (Army *army : getStationedArmies())
    {
      if (army != attacking_army)
      {
        delete army;
      }
    }
    delete attacking_army;
  }
  else
  {
    for (int i = 0; i < enemy_units_in_footmen; i++)
    {
      if (!getStationedArmies().empty())
      {
        getStationedArmies().at(0)->killRandomUnit();
      }
    }
    delete attacking_army;
  }
}

Node *Node::clone(std::map<void *, void *> &objmap)
{
  if (objmap.find(this) != objmap.end())
  {
    return (Node *) ((*objmap.find(this)).second);
  }
  else
  {
    Node *temp = new Node();
    objmap.insert(std::pair<void *, void *>(this, temp));

    temp->name = this->name;

    temp->dist = dist;

    if (mediator)
      temp->mediator = mediator->clone(objmap);

    if (node_type)
      temp->node_type = node_type->clone(objmap);

    if (owner_empire)
      temp->owner_empire = owner_empire->clone(objmap);

    std::vector<Path *> newpaths;
    for (auto path : paths)
    {
      if (path)
        newpaths.push_back(path->clone(objmap));
    }
    temp->paths      = newpaths;
    temp->population = population;

    if (population_empire)
      temp->population_empire = population_empire->clone(objmap);

    if (prev)
      temp->prev = prev->clone(objmap);

    temp->resources = resources;

    std::vector<Army *> newstationedarmies;
    for (auto army : getStationedArmies())
    {
      if (army)
        newstationedarmies.push_back(army->clone(objmap));
    }
    temp->stationed_armies = newstationedarmies;
    return temp;
  }
}
void Node::setOwnerEmpire(Empire *empire) { owner_empire = empire; }
void Node::colonise(Empire *colonising_empire)
{
  owner_empire->removeNode(this);
  node_type->colonise(colonising_empire);
  owner_empire = colonising_empire;

  colonising_empire->addTown(this);
}
void Node::setNodeType(NodeType *node_type) { this->node_type = node_type; }
Node::Node(War* war, Empire *owner_empire, std::string name, int population, bool capital)
{
  this->owner_empire      = owner_empire;
  this->population_empire = owner_empire;
  this->population        = population;
  this->resources         = population;
  this->name              = name;
  owner_empire->addTown(this);
  if (capital)
  {
    this->node_type = new Capital(this);
    owner_empire->setCapital(this);
  }
  else
  {
    this->node_type = new Town(this);
  }
}

void Node::removeObserver(Observer *army)
{
  detach(army);
}

void Node::addObserver(Observer *army)
{
  attach(army);
}

NodeType *Node::getNodeType() { return node_type; }
void Node::setResources(int resources) { this->resources = resources; }
void Node::setName(std::string name) { this->name = name; }
std::string Node::getName() { return name; }
