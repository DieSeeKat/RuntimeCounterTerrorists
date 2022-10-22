//
// Created by Lukas Anthonissen on 2022/10/20.
//

#ifndef PROJECT_NODETYPE_H
#define PROJECT_NODETYPE_H

#include <map>

class Empire;

class Node;

class NodeType
{
  protected:
  Node *node;
  NodeType();

  public:
  NodeType(Node *node);
  virtual void colonise(Empire* empire) = 0;
  virtual NodeType* clone(std::map<void*,void*> &objmap) = 0;;
};


#endif//PROJECT_NODETYPE_H
