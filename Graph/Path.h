#ifndef PATH_H
#define PATH_H

#include "../Army.h"
#include "Terrain.h"
#include <map>

class Node;

class Path
{

  private:
  Path();
  /// Pointer to one of the endpoints of the Path
  Node *nodeA = nullptr;
  /// Pointer to one of the endpoints of the Path
  Node *nodeB = nullptr;
  /// A pointer to the terrain type of a path
  Terrain *terrain_type = nullptr;

  public:
  /**
   * @brief Constructor of the path
   * @param first_node The first end of the path
   * @param last_node The second end of the path
   */
  Path(Node *first_node, Node *last_node, std::string terrain_type);
  Path(Node *first_node, Node *last_node);
  /// Destructor for Path
  ~Path();
  /**
   * @brief Determines and returns the end of the path which is not the passed
   * in Node
   * @param node The node of which the opposite end is calculated
   * @return Return a Node pointer
   */
  Node *getOppositeEnd(Node *node);
  /**
   * @brief Clone method for the Path
   * @param objmap A void to void pointer map
   * @return A pointer to a new cloned Path
   */
  Path *clone(std::map<void *, void *> &objmap);
  /**
   * @brief Calculates the loss in the army whilst on the path
   * @param army
   */
  void calculate_losses(Army *army);
};

#endif
