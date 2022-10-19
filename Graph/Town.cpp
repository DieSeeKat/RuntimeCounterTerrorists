#include "Town.h"

void Town::colonise(Empire *colonising_empire)
{
  Empire *old_owner_empire = owner_empire;
  owner_empire             = colonising_empire;

  colonising_empire->addTown(this);
  old_owner_empire->removeNode(this);
}

Town::Town() : Node()
{
}

std::string Town::getState()
{
  return "NULL";
}
