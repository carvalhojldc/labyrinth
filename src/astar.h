#ifndef ASTAR_H
#define ASTAR_H

#include <list>
#include "node.h"

class AStar {
private:
    Node *startNode, *endNode;

public:

    AStar() {

    }

    list<Node*> getNeighbors(Node* node) {
        list<Node*> neighbors;


        return neighbors;
    }
};

#endif // ASTAR_H
