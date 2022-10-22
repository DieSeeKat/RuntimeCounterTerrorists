#ifndef CAPITOL_H
#define CAPITOL_H

#include "../Empire.h"
#include "NodeType.h"

class Node;

class Capital : public NodeType
{
  private:
  Capital();
  public:
  Capital(Node* node);
  ~Capital();
  /**
   * @brief Colonise the current Node to be part of the colonising_empire
   * @param colonising_empire The Empire colonising this
   */
  void colonise(Empire* empire) override;
  NodeType* clone(std::map<void*,void*> &objmap);
};

#endif
