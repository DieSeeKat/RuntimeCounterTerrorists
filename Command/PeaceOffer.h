#ifndef PEACEOFFER_H
#define PEACEOFFER_H

#include "Communication.h"

#include "../Empire.h"

class PeaceOffer : Communication
{

  private:
  bool state;
  Empire *sender;

  public:
  void requestAlliance();
};

#endif
