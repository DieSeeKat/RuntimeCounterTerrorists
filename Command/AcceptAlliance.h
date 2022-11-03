#ifndef PEACEOFFER_H
#define PEACEOFFER_H

#include "Communication.h"

#include "../Empire.h"

class AcceptAlliance : Communication
{

  private:
  Empire *sender;

  public:
    AcceptAlliance(Empire * _sender);
  void handleAlliance(Empire * empire);
};

#endif
