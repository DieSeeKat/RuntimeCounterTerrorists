#ifndef WAR_H
#define WAR_H

#include <vector>
#include <algorithm>
#include "../Empire.h"
#include "../Graph/Node.h"
#include "../Graph/Path.h"
#include <map>
#include <iostream>

#include "WarRollback.h"

class WarRollback;

class War
{

private:
  std::vector<Node *> nodes;
  std::vector<Empire *> empires;
  std::vector<Path *> paths;
  int index = 0;

public:
  ~War();
  std::map<void *, void *> objmap;
  WarRollback *createWarRollback();
  void setWarRollback(WarRollback *war_rollback);

  bool isFinished();

  std::vector<Empire *> getEmpires();
  std::vector<Node *> getNodes();
  std::vector<Path *> getPaths();

  void setEmpires(std::vector<Empire *> new_empires);
  void setNodes(std::vector<Node *> new_nodes);
  void setPaths(std::vector<Path *> new_paths);

  void addEmpire(Empire *new_empire);
  void addNode(Node *new_node);
  void addPath(Path *new_path);

  void removeEmpire(Empire *new_empire);
  void removeNode(Node *new_node);
  void removePath(Path *new_path);

  void updateEmpires();
  void updateNodes();

  void nextTurn();
};

#endif
