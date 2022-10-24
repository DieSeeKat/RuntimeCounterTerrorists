#include "Capital.h"
#include "../Empire.h"
#include "Node.h"
#include "../Memento/War.h"
#include "Town.h"
#include <iostream>

Capital::Capital() { this->node = nullptr; }

void Capital::colonise(Empire *empire) {
#ifndef disable_output
  std::cout << node->getOwnerEmpire()->getName() << "'s capital, "
            << node->getName() << ", has been captured by " << empire->getName()
            << ". " << node->getOwnerEmpire()->getName()
            << " has collapsed due to the war effort." << std::endl;
#endif

  node->getOwnerEmpire()->getWar()->removeEmpire(node->getOwnerEmpire());

  node->setNodeType(new Town(node));
}
Capital::~Capital() {}
Capital::Capital(Node *node) : NodeType(node) {}

NodeType *Capital::clone(std::map<void *, void *> &objmap) {
  if (objmap.find(this) != objmap.end()) {
    return (NodeType *)((*objmap.find(this)).second);
  } else {
    Capital *temp = new Capital();
    objmap.insert(std::pair<void *, void *>(this, temp));
    if (node)
      temp->node = node->clone(objmap);
    return temp;
  }
}