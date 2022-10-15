#include "NodeIterator.h"
#include "Path.h"

NodeIterator::NodeIterator(Path **_paths, int num_paths)
{
  paths = _paths;
}

void NodeIterator::first()
{
  Node **all_end_points = paths[0]->getEndPoints();
}

void NodeIterator::next()
{
  // TODO - implement NodeIterator::next
  throw "Not yet implemented";
}

bool NodeIterator::isDone()
{
  // TODO - implement NodeIterator::isDone
  throw "Not yet implemented";
}

Node *NodeIterator::currentNode()
{
  return current_node;
}
