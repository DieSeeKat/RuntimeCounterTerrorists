#ifndef TOWN_H
#define TOWN_H

#include "../Empire.h"
#include "NodeType.h"
#include <map>

class Node;

class Town : public NodeType
{
  private:
  Town();
  public:
  Town(Node* node);
  ~Town();
  /**
   * @brief Colonise the current Node to be part of the colonising_empire
   * @param colonising_empire The Empire colonising this
   */
  void colonise(Empire* empire) override;
  /**
   * @brief Clone method for the Town
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned Town
   */
  NodeType* clone(std::map<void*,void*> &objmap);
};

#endif
