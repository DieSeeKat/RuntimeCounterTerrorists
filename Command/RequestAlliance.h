#ifndef REQUESTALLIANCE_H
#define REQUESTALLIANCE_H

#include "Communication.h"

#include "../Empire.h"

class RequestAlliance : Communication
{
  private:
  Empire *sender;

  public:
    RequestAlliance(Empire * _sender);
    void handleAlliance(Empire * empire);
};

#endif
