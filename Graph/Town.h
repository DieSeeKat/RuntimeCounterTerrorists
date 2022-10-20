#ifndef TOWN_H
#define TOWN_H

#include "Node.h"

#include "../Empire.h"

class Town : public Node
{
  public:
  Town(Empire* empire, int population);
  ~Town();
  /**
   * @brief Colonise the current Node to be part of the colonising_empire
   * @param colonising_empire The Empire colonising this
   */
  void colonise(Empire *colonising_empire) override;
  std::string getState() override;
};

#endif
