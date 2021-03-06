#ifndef ASTAR_H
#define ASTAR_H

#include <list>
#include <cmath>
#include "labyrinth.h"
#include "node.h"

using std::list;

#define MANHATTAN_DISTANCE 1
#define EUCLIDEAN_DISTANCE 2

class AStar {
private:
    Labyrinth *labyrinth;

    Node *startNode, \
         *endNode;

    list<Node*> openPath, \
                closedPath, \
                myPath;

    int distanceType;

private:

    Node *inList(list<Node*> l, Position position);

    bool isFree(Position neighbor);

    float getH(Position position);

    float getG(Position position, Node* parent);

    Node* getBest(list<Node*> l);

    bool removeNodeList(list<Node*>& l, Node* node);

    void addInOpenList(Node* node);

    void addInClosedList(Node* node);

    bool getNeighbors(Node* node);

public:

    AStar();

    AStar(Labyrinth* labyrinth, int distanceType);

    list<Node*> getMyPath() const;

    list<Node*> getClosedPath() const;

    list<Node*> getOpenPath() const;

    void searchPath();
};

#endif // ASTAR_H
