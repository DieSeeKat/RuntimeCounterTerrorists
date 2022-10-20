#ifndef WARROLLBACK_H
#define WARROLLBACK_H

#include <vector>

#include "../Empire.h"
#include "../Graph/Node.h"
#include "../Graph/Path.h"

class War;
class WarRollback
{

  friend War;
  private:
  std::vector<Node *> nodes;
  std::vector<Empire *> empires;
  std::vector<Path *> paths;
  std::vector<Alliance *> alliances;

  public:
  std::vector<Node *> getNodes();

  void setNodes(std::vector<Node *> nodes);

  std::vector<Empire *> getEmpires();

  void setEmpires(std::vector<Empire *> empires);

  std::vector<Path *> getPaths();

  void setPaths(std::vector<Path *> paths);

  std::vector<Alliance *> getAlliances();

  void setAlliances(std::vector<Alliance *> alliances);
};

#endif
