#ifndef NODE_H
#define NODE_H

#include "position.h"

class Node : public Position{
private:
    Position position;
    Node* parent = nullptr;

    float gl, hl;

public:
    Node(int x, int y) {
        position.setPosition(x, y);

        gl = 0;
        hl = 0;
    }

    bool operator ==(Node* n) {
        return ( position == Position(n->getX(), n->getY()) );
    }
};

#endif // NODE_H
