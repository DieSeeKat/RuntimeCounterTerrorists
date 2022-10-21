#include "War.h"

WarRollback *War::createWarRollback()
{
  WarRollback* temp = new WarRollback();
  std::map<void*, void*> objmap;

  std::vector<Empire*> temp_empires;
  for(std::vector<Empire*>::iterator it = empires.begin(); it != empires.end(); it++){
    temp_empires.push_back((*it)->clone(objmap));
  }
  temp->empires = empires;

  std::vector<Path*> temp_paths;
  for(std::vector<Path*>::iterator it = paths.begin(); it != paths.end(); it++){
    temp_paths.push_back((*it)->clone(objmap));
  }
  temp->paths = temp_paths;

  std::vector<Node*> temp_nodes;
  for(std::vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++){
    temp_nodes.push_back((*it)->clone(objmap));
  }
  temp->nodes = temp_nodes;
  return temp;
}

void War::setWarRollback(WarRollback *war_rollback)
{
  
  for(std::vector<Empire*>::iterator it = empires.begin(); it != empires.end(); it++){
    if(it!=empires.end())
      delete (*it);
  }

  for(std::vector<Path*>::iterator it = paths.begin(); it != paths.end(); it++){
      if(it!=paths.end())
        delete (*it);
  }

  for(std::vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++){
      if(it!=nodes.end() && it!=nodes.begin()){
        delete (*it);
      }
  }
  
  this->empires = war_rollback->empires;
  updateEmpires();
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

void War::setEmpires(std::vector<Empire *> new_empires)
{
  for(std::vector<Empire*>::iterator it = empires.begin(); it != empires.end(); it++){
    delete (*it);
  }

  empires = new_empires;
  updateEmpires();
}
void War::setNodes(std::vector<Node *> new_nodes)
{
  for(std::vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++){
    delete (*it);
  }

  nodes = new_nodes;
}
void War::setPaths(std::vector<Path *> new_paths)
{
  for(std::vector<Path*>::iterator it = paths.begin(); it != paths.end(); it++){
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
}
void War::addPath(Path *new_path)
{
  paths.push_back(new_path);
}

void War::removeEmpire(Empire *to_remove)
{
  delete to_remove;
  empires.erase(std::remove(empires.begin(), empires.end(), to_remove), empires.end());
}
void War::removeNode(Node *to_remove)
{
  delete to_remove;
  nodes.erase(std::remove(nodes.begin(), nodes.end(), to_remove), nodes.end());
}
void War::removePath(Path *to_remove)
{
  delete to_remove;
  paths.erase(std::remove(paths.begin(), paths.end(), to_remove), paths.end());
}
void War::updateEmpires(){
  for(std::vector<Empire*>::iterator it = empires.begin(); it != empires.end(); it++){
    (*it)->setWar(this);
  }
}