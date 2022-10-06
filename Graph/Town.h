#ifndef TOWN_H
#define TOWN_H

#include "Node.h"

#include "../Empire.h"

class Town : Node
{
  public:
  void colonise(Empire *colonising_empire);
};

#endif
