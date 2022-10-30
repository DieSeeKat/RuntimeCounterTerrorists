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
  WarRollback();
  /**
   * @brief Used to store War::nodes
   * 
   */
  std::vector<Node *> nodes;
  /**
   * @brief Used to store War::empires
   * 
   */
  std::vector<Empire *> empires;
  /**
   * @brief Used to store War::paths
   * 
   */
  std::vector<Path *> paths;
};

#endif
