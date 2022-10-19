#ifndef DEFENSE_H
#define DEFENSE_H

#include "Empire.h"

#include "WarStage.h"

class Defense : public WarStage
{
  public:
  Defense(Empire *empire);
  /**
   * @brief Will determine what the Empire will do on its turn
   */
  void takeTurn();
};

#endif
