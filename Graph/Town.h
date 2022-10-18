#ifndef TOWN_H
#define TOWN_H

#include "Node.h"

#include "../Empire.h"

class Town : public Node
{
  public:
  Town();
  void colonise(Empire *colonising_empire) override;
  std::string getState() override;
};

#endif
