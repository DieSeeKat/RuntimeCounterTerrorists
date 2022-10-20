#include "Capital.h"
#include "../Empire.h"

void Capital::colonise(Empire *colonising_empire)
{
  Empire *old_owner_empire = owner_empire;
  owner_empire             = colonising_empire;

  colonising_empire->addTown(this);
  old_owner_empire->removeNode(this);

  delete old_owner_empire;
}
Capital::~Capital()
{
}
Capital::Capital(Empire *empire, int population) : Node(empire, population)
{
}
