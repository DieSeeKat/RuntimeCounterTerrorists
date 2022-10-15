#include "NodeIterator.h"
#include "Path.h"

int path_index = 0;

NodeIterator::NodeIterator(Path **_paths, int num_paths)
{
  paths = _paths;
  path_count = num_paths;
}

void NodeIterator::first()
{
  Node **first_end_points = paths[path_index]->getEndPoints();
  current_node = first_end_points[1];
  path_index++;
}

void NodeIterator::next()
{
  Node **next_end_points = paths[path_index]->getEndPoints();
  current_node = next_end_points[1];
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
