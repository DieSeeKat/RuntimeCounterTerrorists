#include "War.h"
#include <vector>

/**
 * @brief Destroy the War:: War object this will also delete all empires and nodes in this war.
 * 
 */
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

/**
 * @brief Create a memento, a copy of everything in the war and their relationships.
 * 
 * @return WarRollback* 
 */
WarRollback *War::createWarRollback()
{
  WarRollback *temp = new WarRollback();
  std::vector<Empire *> temp_empires;
  for (auto empire : empires)
  {
    temp_empires.push_back(empire->clone(objmap));
  }
  temp->empires = temp_empires;

  std::vector<Node *> temp_nodes;
  for (std::vector<Node *>::iterator it = nodes.begin(); it != nodes.end(); it++)
  {
    temp_nodes.push_back((*it)->clone(objmap));
  }
  temp->nodes = temp_nodes;

  return temp;
}

/**
 * @brief Use this to restore the war to the state of the passed in Memento
 * 
 * @param war_rollback 
 */
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
}

/**
 * @brief Return all empires currently in this war.
 * 
 * @return std::vector<Empire *> 
 */
std::vector<Empire *> War::getEmpires()
{
  return empires;
}
/**
 * @brief Return all nodes currently in this war.
 * 
 * @return std::vector<Node *> 
 */
std::vector<Node *> War::getNodes()
{
  return nodes;
}
/**
 * @brief Setter for empires in this war.
 * 
 * @param new_empires 
 */
void War::setEmpires(std::vector<Empire *> new_empires)
{
  for (std::vector<Empire *>::iterator it = empires.begin(); it != empires.end(); it++)
  {
    delete (*it);
  }

  empires = new_empires;
  updateEmpires();
}
/**
 * @brief Setter for nodes in this war.
 * 
 * @param new_nodes 
 */
void War::setNodes(std::vector<Node *> new_nodes)
{
  for (std::vector<Node *>::iterator it = nodes.begin(); it != nodes.end(); it++)
  {
    delete (*it);
  }

  nodes = new_nodes;
  updateNodes();
}
/**
 * @brief Add a single empire to this war.
 * 
 * @param new_empire 
 */
void War::addEmpire(Empire *new_empire)
{
  empires.push_back(new_empire);
  updateEmpires();
}
/**
 * @brief Add a single node to this war.
 * 
 * @param new_node 
 */
void War::addNode(Node *new_node)
{
  nodes.push_back(new_node);
  updateNodes();
}
/**
 * @brief Remove a single empire from this war.
 * 
 * @param to_remove 
 */
void War::removeEmpire(Empire *to_remove)
{
  empires.erase(std::find(empires.begin(), empires.end(), to_remove));
  delete to_remove;

  if (index != 0)
  {
    index = -1;
  }
}
/**
 * @brief Remove a single node from this war.
 * 
 * @param to_remove 
 */
void War::removeNode(Node *to_remove)
{
  delete to_remove;
  nodes.erase(std::find(nodes.begin(), nodes.end(), to_remove));
}
/**
 * @brief This is a helper method used to update all Empire::war to this current war.
 * 
 */
void War::updateEmpires()
{
  for (auto empire : empires)
  {
    empire->setWar(this);
  }
}
/**
 * @brief This is a helper method used to update all Node::war to this current war.
 * 
 */
void War::updateNodes()
{
  for (auto node : nodes)
  {
    node->setWar(this);
  }
}
/**
 * @brief Function to check if the war is finished or still ongoing.
 * This is done by checking if there are any opposing empires left in the war.
 * 
 * @return true 
 * @return false 
 */
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
/**
 * @brief Method used to loop between empires and do execute by turn moves.
 * 
 */
void War::nextTurn()
{
  index = (index + 1) % empires.size();
  empires.at(index)->takeTurn();
}
