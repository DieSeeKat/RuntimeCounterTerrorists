#include "NodeIterator.h"

int path_index = 0;

NodeIterator::NodeIterator(Node* start)
{
  start_node = start;
  paths = start_node->getPaths();
  path_count = paths.size();
  current_node = NULL;
}

void NodeIterator::first()
{
  current_node = paths.at(path_index)->getOppositeEnd(start_node);
  path_index++;
}

void NodeIterator::next()
{
  current_node = paths.at(path_index)->getOppositeEnd(start_node);
  path_index++;
}

bool NodeIterator::isDone()
{
  if(path_index == this->path_count)
  {
    return true;
  }
  else
  {
    return false;
  }
}

Node *NodeIterator::currentNode()
{
  return current_node;
}
