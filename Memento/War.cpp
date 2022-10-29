#include "War.h"
#include <vector>

War::~War(){
  for (auto empire : empires)
  {
    delete empire;
  }
  for (std::vector<Node *>::iterator it = nodes.begin(); it != nodes.end(); it++)
  {
    if (it != nodes.end())
    {
      delete (*it);
    }
  }
}

WarRollback *War::createWarRollback()
{
  WarRollback *temp = new WarRollback();
  std::vector<Empire *> temp_empires;
  for (auto empire : empires)
  {
    temp_empires.push_back(empire->clone(objmap));
  }
  temp->empires = temp_empires;

  std::vector<Path *> temp_paths;
  for (std::vector<Path *>::iterator it = paths.begin(); it != paths.end(); it++)
  {
    temp_paths.push_back((*it)->clone(objmap));
  }
  temp->paths = temp_paths;

  std::vector<Node *> temp_nodes;
  for (std::vector<Node *>::iterator it = nodes.begin(); it != nodes.end(); it++)
  {
    temp_nodes.push_back((*it)->clone(objmap));
  }
  temp->nodes = temp_nodes;

  return temp;
}

void War::setWarRollback(WarRollback *war_rollback)
{
  for (auto empire : empires)
  {
    delete empire;
  }
  for (std::vector<Node *>::iterator it = nodes.begin(); it != nodes.end(); it++)
  {
    if (it != nodes.end())
    {
      delete (*it);
    }
  }

  this->empires = war_rollback->empires;
  updateEmpires();
  this->nodes = war_rollback->nodes;
  updateNodes();
  this->paths = war_rollback->paths;
}

std::vector<Empire *> War::getEmpires()
{
  return empires;
}
std::vector<Node *> War::getNodes()
{
  return nodes;
}
std::vector<Path *> War::getPaths()
{
  return paths;
}

void War::setEmpires(std::vector<Empire *> new_empires)
{
  for (std::vector<Empire *>::iterator it = empires.begin(); it != empires.end(); it++)
  {
    delete (*it);
  }

  empires = new_empires;
  updateEmpires();
}
void War::setNodes(std::vector<Node *> new_nodes)
{
  for (std::vector<Node *>::iterator it = nodes.begin(); it != nodes.end(); it++)
  {
    delete (*it);
  }

  nodes = new_nodes;
  updateNodes();
}
void War::setPaths(std::vector<Path *> new_paths)
{
  for (std::vector<Path *>::iterator it = paths.begin(); it != paths.end(); it++)
  {
    delete (*it);
  }
  paths = new_paths;
}

void War::addEmpire(Empire *new_empire)
{
  empires.push_back(new_empire);
  updateEmpires();
}
void War::addNode(Node *new_node)
{
  nodes.push_back(new_node);
  updateNodes();
}
void War::addPath(Path *new_path)
{
  paths.push_back(new_path);
}

void War::removeEmpire(Empire *to_remove)
{
  empires.erase(std::find(empires.begin(), empires.end(), to_remove));
  delete to_remove;

  if (index != 0)
  {
    index = -1;
  }
}
void War::removeNode(Node *to_remove)
{
  delete to_remove;
  nodes.erase(std::find(nodes.begin(), nodes.end(), to_remove));
}
void War::removePath(Path *to_remove)
{
  delete to_remove;
  paths.erase(std::find(paths.begin(), paths.end(), to_remove));
}
void War::updateEmpires()
{
  for (auto empire : empires)
  {
    empire->setWar(this);
  }
}
void War::updateNodes()
{
  for (auto node : nodes)
  {
    node->setWar(this);
  }
}
bool War::isFinished()
{
  Empire * firstEmpire = empires.at(0);
  for (auto empire : empires) {
    if (!firstEmpire->isAlly(empire)){
      return false;
    }
  }
  return true;
}
void War::nextTurn()
{
  index = (index + 1) % empires.size();
  empires.at(index)->takeTurn();
}
