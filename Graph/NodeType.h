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
  Node *node = nullptr;
  NodeType();

  public:
  NodeType(Node *node);
  virtual void colonise(Empire* empire) = 0;
  /**
   * @brief Pure virtual clone method
   * 
   * @param objmap map<void*,void*>
   * @return NodeType* Any NodeType* of a class that inherits from NodeType
   */
  virtual NodeType* clone(std::map<void*,void*> &objmap) = 0;
};


#endif//PROJECT_NODETYPE_H
