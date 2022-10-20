#ifndef PATH_H
#define PATH_H

#include "../Army.h"

class Node;

class Path
{

  private:
  Node **end_points;
  int distance;

  public:
  /**
       * @brief Constructor of the path
       * @param first_node The first end of the path
       * @param last_node The second end of the path
       */
  Path(Node *first_node, Node *last_node);
  void calculate_losses(Army *army);
  /**
    * @brief Determines and returns the end of the path which is not the passed in Node
    * @param node The node of which the opposite end is calculated
    * @return Return a Node pointer
    */
  Node *getOppositeEnd(Node *node);
  Path* clone();
};

#endif
