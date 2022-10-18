#ifndef DEFENSE_H
#define DEFENSE_H

#include "Empire.h"

#include "WarStage.h"

class Defense : public WarStage
{
  public:
  Defense(Empire *empire);
  void takeTurn();
};

#endif
