#include "Node.h"
#include "Empire.h"

NodeIterator *Node::createIterator()
{
  // TODO - implement Node::createIterator
  throw "Not yet implemented";
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
