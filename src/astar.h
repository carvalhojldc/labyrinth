#ifndef ASTAR_H
#define ASTAR_H

#include <list>
#include <algorithm>

#include "labyrinth.h"
#include "node.h"

#include <QDebug>
#include <QTime>

using std::list;

#define MANHATTAN_DISTANCE 1
#define EUCLIDEAN_DISTANCE 2

class AStar {
private:
    Labyrinth *labyrinth;

    Node *startNode, *endNode;

    list<Node*> openPath, closedPath, myPath;

private:

    bool inList(list<Node*> l, Position position) {
        list<Node*>::iterator it;
        Node *temp;
        for(it=l.begin(); it!=l.end(); it++) {
            temp = *it;
            if(temp->position == position)
                return true;
        }
        return false;
    }

    bool isFree(Node* node, Position neighbor) {
        Node* parent = node->getParent();

        if( ( labyrinth->map->get(neighbor.getX(), neighbor.getY()) != CELL_WALL ) && \
            ( node->position != neighbor) && \
            ( parent == nullptr || parent->position != neighbor ) )
            return true;

        return false;
    }

    float getH(Position position, int type) {
        float distance = 0;

        if(type == MANHATTAN_DISTANCE) {
            // manhattan: d(a,b) = |Xb−Xa| + |Yb−Ya|.
            float dx = abs(position.getX() - endNode->position.getX());
            float dy = abs(position.getY() - endNode->position.getY());

            distance = dx + dy;
        } else {
            // euclidian: d(a,b) = sqrt( (Xa−Xb)^2 + (Ya−Yb)^2 ).
            float dx = pow(position.getX() - endNode->position.getX(), 2);
            float dy = pow(position.getY() - endNode->position.getY(), 2);

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

    Node* getBest(list<Node*> l) {
        list<Node*>::iterator it;
        Node *best = l.front();
        Node *aux;

        for(it=l.begin(); it!=l.end(); it++) {
            aux = *it;
            if(aux < best) best = aux;
        }

        return best;
    }

    bool removeNodeList(list<Node*>& l, Node* node) {
        list<Node*>::iterator it;
        Node* temp;
        for(it=l.begin();it!=l.end(); it++) {
            temp = *it;
            if(temp->position == node->position) {
                l.erase(it);
                return true;
            }
        }
        return false;
    }

    void addInOpenList(Node* node) {
        openPath.push_back(node);

        if(node->position != endNode->position && node->position != startNode->position)
            labyrinth->map->setBoardColor(node->position, CELL_OPEN_LIST);
    }

    void addInClosedList(Node* node) {
        closedPath.push_back(node);
        removeNodeList(openPath, node);

        if(node->position != endNode->position && node->position != startNode->position)
            labyrinth->map->setBoardColor(node->position, CELL_CLOSED_LIST);
    }

    bool getNeighbors(Node* node) {
        list<Node*>::iterator it;
        Node *theBest = nullptr;
        Node *temp = nullptr;

        float g, h;

        int startLine, endLine, \
            startColumn, endColumn;

        int myX = node->position.getX();
        int myY = node->position.getY();

        myX == 0 ? startLine = myX : startLine = myX-1;
        myX == labyrinth->map->getNLines()-1 ? endLine = myX : endLine = myX+1;
        myY == 0 ? startColumn = myY : startColumn = myY-1;
        myY == labyrinth->map->getNColumns()-1 ? endColumn = myY : endColumn = myY+1;

        for(int line=startLine; line<=endLine; line++) {
            for(int column=startColumn; column<=endColumn; column++) {

                Position newNeighbor(line,column);

                if( isFree(node, newNeighbor) && !inList(closedPath, newNeighbor) )
                {
                    g = getG(newNeighbor, node);
                    h = getH(newNeighbor, EUCLIDEAN_DISTANCE);

                    Node *neighbor = new Node(node, newNeighbor, g, h);

                    if(neighbor->position==endNode->position) {
                        theBest = neighbor;
                        break;
                    }


                    if(theBest == nullptr)
                        theBest = neighbor;
                    else if(neighbor->getHeuristic() < theBest->getHeuristic())
                        theBest = neighbor;

                    for(it=openPath.begin(); it!=openPath.end(); it++) {
                        temp = *it;
                        if(temp->position == neighbor->position)
                            break;
                    }

                    if(it == openPath.end()) {
                        addInOpenList(neighbor);
                    } else {
                        temp->setParent(node);
                        temp->setG(g);
                    }
                }
            }
        }

        if(theBest != nullptr) {
            addInClosedList(theBest);
        } else if(openPath.size() != 0) {
            theBest = getBest(openPath);
            addInClosedList(theBest);
        } else {           
            return false;
        }

        if(theBest->position != endNode->position) {
            getNeighbors(closedPath.back());
        } else {
            return true;
        }
    }

public:

    AStar() {
        labyrinth = nullptr;
    }

    AStar(Labyrinth* labyrinth) {
        this->labyrinth = labyrinth;

        startNode = new Node(nullptr, labyrinth->map->getStartPosition());
        endNode   = new Node(nullptr, labyrinth->map->getEndPosition());
    }

    const inline list<Node*> getMyPath() const
    { return myPath; }

    const inline list<Node*> getClosedPath() const
    { return closedPath; }

    const inline list<Node*> getOpenPath() const
    { return openPath; }

    void searchPath() {
        closedPath.push_back(startNode);

        if(getNeighbors(closedPath.back()))
        {
            Node *temp;
            myPath.push_front( closedPath.back() );
            while(myPath.front() != startNode) {
                temp = myPath.front();

                if(temp->position != startNode->position && temp->position != endNode->position)
                    labyrinth->map->setBoardColor( temp->position, CELL_PATH);

                myPath.push_front( temp->getParent() );
            }
        }


        qDebug() << "myPath gg" << myPath.size();

        /*
        list<Node*>::iterator it;

        qDebug() <<"closedPath.size(): " << closedPath.size();
        for(it=closedPath.begin(); it!=closedPath.end(); it++) {
            Node* temp = *it;
            qDebug() << temp->position.getX() << " " << temp->position.getY();
        }
        qDebug() <<"openPath.size(): " << openPath.size();
        for(it=openPath.begin(); it!=openPath.end(); it++) {
            Node* temp = *it;
            qDebug() << temp->position.getX() << " " << temp->position.getY();
        }

        qDebug() <<"myPath.size(): " << myPath.size();
        for(it=myPath.begin(); it!=myPath.end(); it++) {
            Node* temp = *it;
            qDebug() << temp->position.getX() << " " << temp->position.getY();

        }
        */
    }
};

#endif // ASTAR_H
