#include <vector>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <climits>
#include <iostream>

#include "../Empire.h"
#include "Node.h"
#include "Town.h"
#include "Capital.h"

NodeIterator *Node::createIterator()
{
  return new NodeIterator(this);
}

void Node::changed()
{
  // TODO - implement Node::changed
  throw "Not yet implemented";
}

Army Node::recruit(ArmyRatio ratio, int num_recruits)
{
  // TODO - implement Node::recruit
  throw "Not yet implemented";
}

void Node::repopulate()
{
  population = ceil(population * 1.1);
}
int Node::getPopulation()
{
  return population;
}
void Node::rechargeResources()
{
  resources = population;
}
std::vector<Node *> Node::findShortestPathTo(std::vector<Node *> nodes, Node *end_node)
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
        if (std::find(to_be_checked.begin(), to_be_checked.end(), path->getOppositeEnd(curr)) == to_be_checked.end())
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
Empire *Node::getOwnerEmpire()
{
  return owner_empire;
}
bool Node::connectedToCapital(std::vector<Node *> nodes, Node *capital)
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
      if (newDist < path->getOppositeEnd(curr)->dist && path->getOppositeEnd(curr)->getOwnerEmpire() == owner_empire)
      {
        path->getOppositeEnd(curr)->dist = newDist;
        path->getOppositeEnd(curr)->prev = curr;
        if (std::find(to_be_checked.begin(), to_be_checked.end(), path->getOppositeEnd(curr)) == to_be_checked.end())
        {
          to_be_checked.push_back(path->getOppositeEnd(curr));
        }
      }
    }
  }

  return capital->prev != nullptr;
}


std::vector<Path *> Node::getPaths()
{
  return paths;
}
Node::Node(Empire* owner_empire, int population)
{
  this->owner_empire = owner_empire;
  this->population_empire = owner_empire;
  this->population = population;
  this->resources = population;
  this->node_type = new Town(this);
}
void Node::addPath(Path *path)
{
  paths.push_back(path);
}
void Node::addPathTo(Node *node)
{
  Path *new_path = new Path(this, node);
  addPath(new_path);
  node->addPath(new_path);
}

void Node::onAttacked()
{
  owner_empire->recruitArmy(this);
}
Node::~Node()
{
  for (auto path : paths)
  {
    paths.erase(remove(paths.begin(), paths.end(), path), paths.end());
    path->getOppositeEnd(this)->removePath(path);
  }
  owner_empire->removeNode(this);
}
void Node::removePath(Path *path)
{
  paths.erase(remove(paths.begin(), paths.end(), path), paths.end());
  delete path;
}
void Node::makeFreeCity()
{
  owner_empire = nullptr;
}
std::vector<Army *> Node::getStationedArmies()
{
  return stationed_armies;
}
void Node::removeStationedArmy(Army* army)
{
  stationed_armies.erase(std::remove(stationed_armies.begin(),  stationed_armies.end(), army), stationed_armies.end());
}
void Node::getAttacked(Army *attacking_army)
{
  int friendly_units_in_footmen = 0;
  int enemy_units_in_footmen    = 0;

  //Calculate friendly_units_in_footmen
  for (Army* army : getStationedArmies()){
    if (getOwnerEmpire() == army->getOwnerEmpire() || getOwnerEmpire()->isAlly(army->getOwnerEmpire())){
      friendly_units_in_footmen += army->getNumUnits();
    }
  }

  //Calculate enemy_units_in_footmen
  enemy_units_in_footmen += attacking_army->getNumUnits();

  int difference = enemy_units_in_footmen - friendly_units_in_footmen;

  if (difference > 0) {
    for (Army* army : getStationedArmies()) {
      removeStationedArmy(army);
      army->killSelf();
    }

    for (int i = 0; i < friendly_units_in_footmen; i++) {
      attacking_army->killRandomUnit();
    }
    this->colonise(attacking_army->getOwnerEmpire());
  }else {
    for (int i = 0; i < enemy_units_in_footmen; i++) {
      if (!getStationedArmies().empty())
      {
        getStationedArmies()[0]->killRandomUnit();
      }
    }
    attacking_army->killSelf();
  }
}

/**
 * @brief Implement this function in child classes
*/
Node* Node::clone(std::map<void*, void*> &objmap){
  return NULL;
}
void Node::addStationedArmy(Army* army)
{
  stationed_armies.push_back(army);
}
void Node::setOwnerEmpire(Empire* empire)
{
  owner_empire = empire;
}
void Node::colonise(Empire *colonising_empire)
{
  Empire *old_owner_empire = owner_empire;
  owner_empire             = colonising_empire;

  colonising_empire->addTown(this);
  old_owner_empire->removeNode(this);

  node_type->colonise(old_owner_empire);
}
void Node::setNodeType(NodeType *node_type)
{
  this->node_type = node_type;
}
Node::Node(Empire *owner_empire, int population, bool capital)
{
  this->owner_empire = owner_empire;
  this->population_empire = owner_empire;
  this->population = population;
  this->resources = population;
  if (capital)
  {
    this->node_type = new Capital(this);
  }else {
    this->node_type = new Town(this);
  }
}
NodeType *Node::getNodeType()
{
  return node_type;
}
int Node::getResources()
{
  return resources;
}
void Node::setResources(int resources)
{
  this->resources = resources;
}
