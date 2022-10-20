#include "War.h"

WarRollback *War::createWarRollback()
{
  WarRollback* temp = new WarRollback();
  std::vector<Alliance*> temp_alliances;
  for(std::vector<Alliance*>::iterator it = alliances.begin(); it != alliances.end(); it++){
    temp_alliances.push_back((*it)->clone());
  }
  temp->alliances = temp_alliances;

  std::vector<Empire*> temp_empires;
  for(std::vector<Empire*>::iterator it = empires.begin(); it != empires.end(); it++){
    temp_empires.push_back((*it)->clone());
  }
  temp->empires = empires;

  std::vector<Path*> temp_paths;
  for(std::vector<Path*>::iterator it = paths.begin(); it != paths.end(); it++){
    temp_paths.push_back((*it)->clone());
  }
  temp->paths = temp_paths;

  std::vector<Node*> temp_nodes;
  for(std::vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++){
    temp_nodes.push_back((*it)->clone());
  }
  temp->nodes = temp_nodes;

  return temp;
}

void War::setWarRollback(WarRollback *war_rollback)
{
  this->alliances = war_rollback->alliances;
  this->empires = war_rollback->empires;
  this->paths = war_rollback->paths;
  this->nodes = war_rollback->nodes;
}

std::vector<Empire *> War::getEmpires()
{
  return empires;
}
std::vector<Node *> War::getNodes()
{
  return nodes;
}
std::vector<Path *> War::getPath()
{
  return paths;
}
std::vector<Alliance *> War::getAlliance()
{
  return alliances;
}

void War::setEmpires(std::vector<Empire *> new_empires)
{
  empires = new_empires;
}
void War::setNodes(std::vector<Node *> new_nodes)
{
  nodes = new_nodes;
}
void War::setPaths(std::vector<Path *> new_paths)
{
  paths = new_paths;
}
void War::setAlliance(std::vector<Alliance *> new_alliances)
{
  alliances = new_alliances;
}

void War::addEmpire(Empire *new_empire)
{
  empires.push_back(new_empire);
}
void War::addNode(Node *new_node)
{
  nodes.push_back(new_node);
}
void War::addPath(Path *new_path)
{
  paths.push_back(new_path);
}
void War::addAlliance(Alliance *new_alliance)
{
  alliances.push_back(new_alliance);
}

void War::removeEmpire(Empire *to_remove)
{
  std::remove(empires.begin(), empires.end(), to_remove);
}
void War::removeNode(Node *to_remove)
{
  std::remove(nodes.begin(), nodes.end(), to_remove);
}
void War::removePath(Path *to_remove)
{
  std::remove(paths.begin(), paths.end(), to_remove);
}
void War::removeAlliance(Alliance *to_remove)
{
  std::remove(alliances.begin(), alliances.end(), to_remove);
}