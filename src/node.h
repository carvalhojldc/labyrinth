#ifndef NODE_H
#define NODE_H

#include <list>
#include "position.h"

using std::list;

class Node : public Position {
private:
    Node* parent;
    float g, \
          h;

public:
    Position position;

    Node() {
        setNode(nullptr, Position(-1,-1), -1, -1);
    }

    Node(Node* parent, Position positon) {
        setNode(parent, positon, -1, -1);
    }

    Node(Node* parent, Position positon, float g, float h) {
        setNode(parent, positon, g, h);
    }

    void setNode(Node* parent, Position positon, float g, float h) {
        this->parent = parent;
        this->position = positon;
        this->g = g;
        this->h = h;
    }

    inline float getHeuristic() const { return g+h; }

    inline float getG() const { return g; }
    inline void setG(const float g) { this->g = g; }

    inline float getH() const { return h; }
    inline void setH(const float h) { this->h = h; }

    inline Node* getParent() const { return parent; }
    inline void setParent(Node* parent) { this->parent = parent; }

    inline Node* getNode() { return this; }

    bool operator == (Node node) {
        return (this->position == node.position);
    }

    void operator = (Node node) {
        this->parent = node.getParent();
        this->position = node.position;
        this->g = node.getG();
        this->h = node.getH();
    }

    bool operator < (Node* node) {
        return this->getHeuristic() < node->getHeuristic();
    }
};

#endif // NODE_H
