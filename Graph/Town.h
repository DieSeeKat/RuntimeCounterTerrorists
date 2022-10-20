#ifndef TOWN_H
#define TOWN_H

#include "../Empire.h"
#include "NodeType.h"

class Node;

class Town : public NodeType
{
  public:
  Town(Node* node);
  ~Town();
  /**
   * @brief Colonise the current Node to be part of the colonising_empire
   * @param colonising_empire The Empire colonising this
   */
  void colonise(Empire* empire) override;
};

#endif
