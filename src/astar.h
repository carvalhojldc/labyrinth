#ifndef ASTAR_H
#define ASTAR_H

#include <list>
#include <algorithm>

#include "labyrinth.h"
#include "node.h"

#include <QDebug>

using std::list;

#define MANHATTAN_DISTANCE 1
#define EUCLIDEAN_DISTANCE 2

class AStar {
private:
    Labyrinth *labyrinth;
    Position startPosition, endPosition;
    Node *start, *end;

    list<Node*> openPath, closedPath;

private:

    bool comp(Node* a, Node* b) { return a<b; }

    float getH(Position position, int type) {
        float distance = 0;

        if(type == MANHATTAN_DISTANCE) {
            // manhattan: d(a,b) = |Xb−Xa| + |Yb−Ya|.
            float dx = abs(position.getX() - endPosition.getX());
            float dy = abs(position.getY() - endPosition.getY());

            distance = dx + dy;
        } else {
            // euclidian: d(a,b) = sqrt( (Xa−Xb)^2 + (Ya−Yb)^2 ).
            float dx = pow(position.getX() - endPosition.getX(), 2);
            float dy = pow(position.getY() - endPosition.getY(), 2);

            distance = sqrt(dx+dy);
        }

        distance = int(distance*100);
        distance /= 100;

        return distance;
    }

    float getG(Position position, Node* parent) {
        if(position.getX() == parent->position.getX())
            return labyrinth->getCostHorizontal();
        else if(position.getY() == parent->position.getY())
            return labyrinth->getCostVertical();
        else
            return labyrinth->getCostDiagonal();
    }

    bool isFree(Node* node, Position neighbor) {
        Node* parent = node->getParent();

        if( ( labyrinth->map->get(neighbor.getX(), neighbor.getY()) != CELL_WALL ) && \
            ( node->position != neighbor) && \
            ( parent == nullptr || parent->position != neighbor ) )
            return true;

        return false;
    }

    void printList(list<Node*> l) {
        list<Node*>::iterator findIter;
        qDebug() << "list";
        for(findIter=l.begin(); findIter!=l.end(); findIter++) {
            Node* temp = *findIter;

            qDebug() << "Heuristic(): " << temp->getHeuristic();
        }
    }

    list<Node*> getNeighbors(Node* node) {

        list<Node*>::iterator findIter;
        list<Node*> myNeighbors;

        Node* theBest;

        float g, h;

        int startLine, endLine, \
            startColumn, endColumn;

        int myX = node->position.getX();
        int myY = node->position.getY();

        {
            myX == 0 ?
                startLine = myX : startLine = myX-1;

            myX == labyrinth->map->getNLines()-1 ?
                endLine = myX : endLine = myX+1;

            myY == 0 ?
                startColumn = myY : startColumn = myY-1;

            myY == labyrinth->map->getNColumns()-1 ?
                endColumn = myY : endColumn = myY+1;
        }

        qDebug() << " - startLine: " << startLine << " endLine: " << endLine;
        qDebug() << " - startColumn: " << startColumn << " endColumn:  " << endColumn;

        std::min_element(closedPath.begin(), closedPath.end(), comp);

        qDebug() << "theBest" << theBest->getH();

        for(int line=startLine; line<=endLine; line++) {
            for(int column=startColumn; column<=endColumn; column++) {
                qDebug() << "# search = line: " << line << " column: " << column;
                Position newNeighbor(line,column);

                if( isFree(node, newNeighbor) )
                {
                    qDebug() << " neighbor = x:" << newNeighbor.getX() << " y:" << newNeighbor.getY();
                    g = getG(newNeighbor, node);
                    h = getH(newNeighbor, EUCLIDEAN_DISTANCE);

                    Node *neighbor = new Node(node, newNeighbor, g, h);
                    findIter = find(openPath.begin(), openPath.end(), neighbor);

                    if(findIter == openPath.end()) {
                        openPath.push_back(neighbor);
                    } else {
                        Node *temp = *findIter;
                        temp->setParent(node);
                        temp->setG(g);
                    }
                }
            }
        }

        qDebug() << "openPath.size(): " << openPath.size();


        //qsort(openPath.begin(), openPath.end(), comp);
        //qsort(openPath.begin(), openPath.size(), sizeof(Node*), comp);
        printList(openPath);

        return myNeighbors;
    }

public:

    AStar() {
        labyrinth = nullptr;
    }

    AStar(Labyrinth* labyrinth) {
        this->labyrinth = labyrinth;
        startPosition = labyrinth->map->getStartPosition();
        endPosition = labyrinth->map->getEndPosition();


        start = new Node(nullptr, startPosition, 0, getH(startPosition, EUCLIDEAN_DISTANCE));
        end   = new Node(nullptr, endPosition);
    }

    void searchPath() {
        closedPath.push_back(start);

        qDebug() << "startPosition= x:" << startPosition.getX() << " y:" << startPosition.getY();
        list<Node*> temp = getNeighbors(start);

        qDebug() << "my heighbors: " << temp.size();

        //list<Node*>::it iterator;

        //for(it = temp.begin(); it != temp.end(); it++)
//            qDebug() << it.
    }
};

#endif // ASTAR_H
