#ifndef PATH_H
#define PATH_H

#include "../Army.h"
#include "Terrain.h"
#include <map>

class Node;

class Path
{

  private:
      ///An array of the different endpoints of a Path
  std::vector<Node*> end_points;
  Node* nodeA = nullptr;
  Node* nodeB = nullptr;
  /// The distance between the endpoints of the Path
  int distance;
  /// A pointer to the terrain type of a path
  Terrain* terrain_type;

  public:
  /**
       * @brief Constructor of the path
       * @param first_node The first end of the path
       * @param last_node The second end of the path
       */

  void calculate_losses(Army *army);
  //-------------------------------------------------------------ADDED BY DHARSHAN GOPAUL
  Path(Node *first_node, Node *last_node, std::string terrain_type);
  Path(Node *first_node, Node *last_node);
  ~Path();

  /**
    * @brief Determines and returns the end of the path which is not the passed in Node
    * @param node The node of which the opposite end is calculated
    * @return Return a Node pointer
    */
  Node *getOppositeEnd(Node *node);
  Path* clone(std::map<void*, void*> &objmap);
};

#endif
