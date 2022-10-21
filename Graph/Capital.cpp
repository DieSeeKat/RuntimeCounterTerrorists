#include "Capital.h"
#include "../Empire.h"
#include "Town.h"
#include "Node.h"

void Capital::colonise(Empire* empire)
{
  empire->dieOff();

  node->setNodeType(new Town(node));
}
Capital::~Capital()
{
}
Capital::Capital(Node* node) : NodeType(node)
{
}
