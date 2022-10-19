#ifndef INVASION_H
#define INVASION_H

#include "WarStage.h"

#include "../Empire.h"

class Attack : public WarStage
{
  public:
  Attack(Empire *empire);
  /**
   * @brief Will determine what the Empire will do on its turn
   */
  void takeTurn();
};

#endif
