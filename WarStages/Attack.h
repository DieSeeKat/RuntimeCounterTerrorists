#ifndef INVASION_H
#define INVASION_H

#include "WarStage.h"

#include "Empire.h"

class Attack : public WarStage
{
  public:
  Attack(Empire *empire);
  void takeTurn();
};

#endif
