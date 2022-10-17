#ifndef NODEITERATOR_H
#define NODEITERATOR_H

#include "Iterator.h"
#include "Node.h"
#include <vector>

class Node;
class Path;

class NodeIterator : Iterator
{

  public:
  Node *current_node;

  NodeIterator( Node* start);

  void first();

  void next();

  bool isDone();

  Node *currentNode();

  private:
  std::vector<Path*> paths;
  int path_count;
  Node* start_node;
};

#endif
