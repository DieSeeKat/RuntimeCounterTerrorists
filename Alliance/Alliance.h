#ifndef ALLIANCE_H
#define ALLIANCE_H

#include "AllianceComponent.h"
#include <vector>

class Alliance : AllianceComponent
{

  public:
  std::vector<AllianceComponent *> children;

  void add(AllianceComponent *alliance_component);

  void remove(AllianceComponent *alliance_component);

  AllianceComponent *getChild(int index);
};

#endif
