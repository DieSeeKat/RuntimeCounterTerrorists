#include "Capitol.h"
#include "../Empire.h"

void Capitol::colonise(Empire *colonising_empire)
{
  Empire *old_owner_empire = owner_empire;
  owner_empire             = colonising_empire;

  colonising_empire->addTown(this);
  old_owner_empire->removeNode(this);

  delete old_owner_empire;
}
