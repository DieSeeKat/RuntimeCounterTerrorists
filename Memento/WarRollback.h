#ifndef WARROLLBACK_H
#define WARROLLBACK_H

#include <vector>

#include "../Empire.h"
#include "../Graph/Node.h"
#include "../Graph/Path.h"

class WarRollback
{

  private:
  std::vector<Node *> nodes;
  Empire *empires;
  Path *paths;
  Alliance *alliances;

  public:
  Node *getNodes();

  void setNodes(Node *nodes);

  Empire *getEmpires();

  void setEmpires(Empire *empires);

  Path *getPaths();

  void setPaths(Path *paths);

  Alliance *getAlliances();

  void setAlliances(Alliance *alliances);
};

#endif
