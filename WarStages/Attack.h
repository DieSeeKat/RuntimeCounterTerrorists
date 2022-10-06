#ifndef INVASION_H
#define INVASION_H

#include "WarStage.h"

class Attack : public WarStage
{
  public:
  Attack();
  void takeTurn();
};

#endif
