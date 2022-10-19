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

  std::vector<AllianceComponent *> getChildren();

  AllianceComponent *getChild(int index);
};

#endif
