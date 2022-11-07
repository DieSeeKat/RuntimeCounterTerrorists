#ifndef CAPITOL_H
#define CAPITOL_H

#include "../Empire.h"
#include "NodeType.h"

class Node;

class Capital : public NodeType {
private:
  /// A private Constructor used for Cloning
  Capital();

public:
    /**
     * @param node The node that will be declared as the empire's capital
     */
  Capital(Node *node);
  ~Capital();
  /**
   * @brief Colonise the current Node to be part of the colonising_empire
   * @param colonising_empire The Empire colonising this
   */
  void colonise(Empire *empire) override;
  /**
   * @brief Clone method for the Capital
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned Capital
   */
  NodeType *clone(std::map<void *, void *> &objmap);
};

#endif
