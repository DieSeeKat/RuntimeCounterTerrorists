#ifndef PEACEOFFER_H
#define PEACEOFFER_H

#include "Communication.h"

#include "../Empire.h"

class AcceptAlliance : Communication
{

  private:
  bool state;
  Empire *sender;

  public:
  void handleAlliance(Empire * empire);
};

#endif
