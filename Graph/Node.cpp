#include <vector>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>

#include "../Empire.h"
#include "Node.h"

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
  population = round(population * 1.1);
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
Node::Node()
{
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
  // TODO - implement Node::onAttacked
  throw "Not yet implemented";
}
Node::~Node()
{
  for (auto path : paths)
  {
    remove(paths.begin(), paths.end(), path);
    path->getOppositeEnd(this)->removePath(path);
  }
}
void Node::removePath(Path *path)
{
  remove(paths.begin(), paths.end(), path);
  delete path;
}
void Node::makeFreeCity()
{
  owner_empire = NULL;
}
