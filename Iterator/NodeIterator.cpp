#include "NodeIterator.h"
#include "../Graph/Node.h"

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
  if (paths.size() != 0)
  {
    current_node = paths.at(0)->getOppositeEnd(start_node);
  }
}

void NodeIterator::next()
{
  cout << "F" << endl;
  path_index++;
  current_node = paths.at(path_index % paths.size())->getOppositeEnd(start_node);
  cout << "G" << endl;
}

bool NodeIterator::isDone()
{
  if(path_index >= this->path_count)
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
