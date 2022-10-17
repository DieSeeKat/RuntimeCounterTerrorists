#ifndef WAR_H
#define WAR_H

#include <vector>

#include "../Empire.h"
#include "../Graph/Node.h"
#include "../Graph/Path.h"

#include "WarRollback.h"

class War
{

  private:
  std::vector<Node *> nodes;
  std::vector<Empire *> empires;
  std::vector<Path *> paths;
  std::vector<Alliance *> alliances;

  public:
  WarRollback createWarRollback();

  void setWarRollback(WarRollback war_rollback);

  std::vector<Empire *> getEmpires();
};

#endif
