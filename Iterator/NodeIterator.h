#ifndef NODEITERATOR_H
#define NODEITERATOR_H

#include "Iterator.h"

#include <vector>

class Node;

class Path;

class NodeIterator : Iterator {

public:
    /**
     * @brief The constructor for the iterator
     * @param start The node where the iterator will start from
     */
    NodeIterator(Node *start);

    /**
   * @brief Get the first adjacent town
   */
    void first();

    /**
   * @brief Get the next adjacent town
   */
    void next();

    /**
     * @brief Check if the iterator went through all the adjacent towns
     * @return return true if done else false
     */
    bool isDone();

    /**
     * @brief Get the node the iterator is at
     * @return The iterator the node is at
     */
    Node *currentNode();

private:
    ///The node the iterator is at
    Node *current_node;
    ///A vector of the paths around the start node
    std::vector<Path *> paths;
    ///The number of paths around the start node
    int path_count;
    ///The origin node
    Node *start_node;
};

#endif
