#ifndef ALLIANCE_H
#define ALLIANCE_H

#include "AllianceComponent.h"

class Alliance : AllianceComponent
{

  public:
  AllianceComponent *children;

  void add(AllianceComponent *alliance_component);

  void remove(AllianceComponent *alliance_component);

  AllianceComponent *getChild(int index);
};

#endif
