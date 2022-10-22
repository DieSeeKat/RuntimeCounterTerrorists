#ifndef INVASION_H
#define INVASION_H

#include "WarStage.h"

#include "../Empire.h"

class Attack : public WarStage
{
  private:
  Attack();
  public:
  Attack(Empire *empire);
  ~Attack();
  /**
   * @brief Will determine what the Empire will do on its turn
   */
  void takeTurn();
  WarStage* clone(std::map<void*,void*> &objmap);
};

#endif
