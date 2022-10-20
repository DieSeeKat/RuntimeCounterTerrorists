#ifndef CAPITOL_H
#define CAPITOL_H

#include "../Empire.h"
#include "Node.h"

class Capital : public Node
{
  public:
  Capital(Empire* empire, int population);
  ~Capital();
  void colonise(Empire *colonising_empire);
};

#endif
