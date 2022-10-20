#ifndef WAR_H
#define WAR_H

#include <vector>

#include "../Empire.h"
#include "../Graph/Node.h"
#include "../Graph/Path.h"
#include <algorithm>

#include "WarRollback.h"

class War
{

private:
  std::vector<Node *> nodes;
  std::vector<Empire *> empires;
  std::vector<Path *> paths;
  std::vector<Alliance *> alliances;

public:
  WarRollback *createWarRollback();
  void setWarRollback(WarRollback *war_rollback);

  std::vector<Empire *> getEmpires();
  std::vector<Node *> getNodes();
  std::vector<Path *> getPath();
  std::vector<Alliance *> getAlliance();

  void setEmpires(std::vector<Empire *> new_empires);
  void setNodes(std::vector<Node *> new_nodes);
  void setPaths(std::vector<Path *> new_paths);
  void setAlliance(std::vector<Alliance *> new_alliances);

  void addEmpire(Empire *new_empire);
  void addNode(Node *new_node);
  void addPath(Path *new_path);
  void addAlliance(Alliance *new_alliance);

  void removeEmpire(Empire *new_empire);
  void removeNode(Node *new_node);
  void removePath(Path *new_path);
  void removeAlliance(Alliance *new_alliance);
};

#endif
