#ifndef REQUESTALLIANCE_H
#define REQUESTALLIANCE_H

#include "Communication.h"

#include "../Empire.h"

class RequestAlliance : Communication
{

  private:
  bool state;
  Empire *sender;

  public:
    void handleAlliance(Empire * empire);
};

#endif
