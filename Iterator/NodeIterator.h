#ifndef NODEITERATOR_H
#define NODEITERATOR_H

#include "Iterator.h"

class Node;

class NodeIterator : Iterator
{

  public:
  Node *current_node;

  void first();

  void next();

  bool isDone();

  Node *currentNode();
};

#endif
