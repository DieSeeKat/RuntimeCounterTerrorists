#ifndef CAPITOL_H
#define CAPITOL_H

#include "../Empire.h"
#include "Node.h"

class Capital : public Node
{
  public:
  Capital(Empire* empire, int population);
  ~Capital();
  std::string getState();
  /**
   * @brief Colonise the current Node to be part of the colonising_empire
   * @param colonising_empire The Empire colonising this
   */
  void colonise(Empire *colonising_empire);
};

#endif
