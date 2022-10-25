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
  /**
   * @brief Clone method for the Defense Stage
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned Defense Stage
   */
  WarStage* clone(std::map<void*,void*> &objmap);
};

#endif
