#ifndef DEFENSE_H
#define DEFENSE_H

#include "../Empire.h"

#include "WarStage.h"
#include <map>

class Defense : public WarStage
{
  private:
  Defense();
  public:
  Defense(Empire *empire);
  ~Defense();
  /**
   * @brief Will determine what the Empire will do on its turn
   */
  void takeTurn();
  WarStage* clone(std::map<void*,void*> &objmap);
};

#endif
