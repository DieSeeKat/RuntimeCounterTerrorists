#ifndef NODEITERATOR_H
#define NODEITERATOR_H

#include "Iterator.h"

class Node;
class Path;

class NodeIterator : Iterator
{

  public:
  Node *current_node;

  NodeIterator(Path **_paths, int num_paths);

  void first();

  void next();

  bool isDone();

  Node *currentNode();

  private:
  Path **paths;
  int path_count;
};

#endif
