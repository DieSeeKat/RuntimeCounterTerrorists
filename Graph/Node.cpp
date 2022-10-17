#include <vector>
#include <cmath>
#include <algorithm>

#include "Empire.h"
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
Node *Node::nextStepTo(Node *node)
{
  // TODO - use shortest path algorithm
  return nullptr;
}
Node *Node::getClosestEnemy()
{
  int max_depth = 0;
  while (max_depth < 200)
  {
    for (auto &path : paths)
    {
      Node *node = path->getOppositeEnd(this)->recursivelyFindClosestEnemy(0, max_depth);
      if (node != nullptr)
      {
        return node;
      }
    }
    max_depth++;
  }
  return nullptr;
}
void Node::rechargeResources()
{
  resources = population;
}
Node *Node::recursivelyFindClosestEnemy(int depth, int max_depth)
{
  if (depth < max_depth)
  {
    for (auto &path : paths)
    {
      Node *node = path->getOppositeEnd(this)->recursivelyFindClosestEnemy(0, max_depth);
      if (node != nullptr)
      {
        return node;
      }
    }
  }
  else
  {
    for (auto &path : paths)
    {
      Node *node = path->getOppositeEnd(this);
      if (!ownerEmpire->isAlly(node->ownerEmpire))
      {
        return node;
      }
    }
  }

  return nullptr;
}
std::vector<Node *> Node::findShortestPathTo(Node *end_node)
{
  std::vector<Node *> to_be_checked;
  //Populate Vector with all nodes in graph
  std::vector<Node *> nodes;

  for (auto node : nodes)
  {
    node->dist = INFINITY;
    node->prev = nullptr;
  }
  this->dist = 0;
  to_be_checked.push_back(this);

  while (!to_be_checked.empty())
  {
    Node *curr = to_be_checked.back();
    to_be_checked.pop_back();
    for (auto path : curr->paths)
    {
      int newDist = curr->dist + 1;
      if (newDist < path->getOppositeEnd(this)->dist)
      {
        path->getOppositeEnd(this)->dist = newDist;
        path->getOppositeEnd(this)->prev = curr;
        if (!(std::find(to_be_checked.begin(), to_be_checked.end(), path->getOppositeEnd(this)) != to_be_checked.end()))
          to_be_checked.push_back(path->getOppositeEnd(this));
      }
    }
  }

  std::vector<Node *> return_vector;
  Node *curr_node = end_node;
  while (curr_node != this)
  {
    return_vector.push_back(curr_node);
    curr_node = curr_node->prev;
  }

  return return_vector;
}

std::vector<Path*> Node::getPaths()
{
  return paths;
}
