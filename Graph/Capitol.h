#ifndef CAPITOL_H
#define CAPITOL_H

#include "../Empire.h"
#include "Node.h"

class Capitol : public Node
{
  public:
  void colonise(Empire *colonising_empire);
};

#endif
