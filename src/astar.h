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

    Node *startNode, *endNode;

    list<Node*> openPath, closedPath;

private:

    bool comp(Node* a, Node* b) { return a<b; }

    bool inList(list<Node*> l, Position position) {
        list<Node*>::iterator it;
        Node *temp;
        for(it=l.begin(); it!=l.end(); it++) {
            temp = *it;
            if(temp->position == position) {
            //    qDebug() << ">>>>>>>>>>>>> ta fechado" << temp->position.getX() << " " << temp->position.getY();
                return true;
            }
        }
      //  qDebug() << ">>>>>>>>>>>>> ta " << temp->position.getX() << " " << temp->position.getY();
     //   Node* a = l.back();
//        qDebug() << ">>>>>>>>>>>>> ta " << a->position.getX() << " " << a->position.getY();
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

    bool isFree(Node* node, Position neighbor) {
        Node* parent = node->getParent();

        if( ( labyrinth->map->get(neighbor.getX(), neighbor.getY()) != CELL_WALL ) && \
            ( node->position != neighbor) && \
            ( parent == nullptr || parent->position != neighbor ) )
            return true;

        return false;
    }

    Node* getBest(list<Node*> l) {
        list<Node*>::iterator it;
        Node *best = l.front();
        Node *aux;

        for(it=l.begin(); it!=l.end(); it++) {
            aux = *it;
            if(aux < best) {
                best = aux;
            }
        }

        return best;
    }

    bool getNeighbors(Node* node) {

        list<Node*>::iterator it;
        Node* theBest = nullptr;
        Node *temp = nullptr;

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

        qDebug() << "l" << endLine << "c" << endColumn;
        //if(endLine<1 || endColumn<1 || (endLine==1 && endColumn==1)) return false;

        qDebug() << "#####################################";
        qDebug() << " - startLine: " << startLine << " endLine: " << endLine;
        qDebug() << " - startColumn: " << startColumn << " endColumn:  " << endColumn;

        for(int line=startLine; line<=endLine; line++) {
            for(int column=startColumn; column<=endColumn; column++) {
                qDebug() << "# search = line: " << line << " column: " << column;
                Position newNeighbor(line,column);

                if( isFree(node, newNeighbor) && !inList(closedPath, newNeighbor) )
                {
                    //qDebug() << " neighbor = x:" << newNeighbor.getX() << " y:" << newNeighbor.getY();
                    g = getG(newNeighbor, node);
                    h = getH(newNeighbor, EUCLIDEAN_DISTANCE);

                    Node *neighbor = new Node(node, newNeighbor, g, h);

                    //qDebug() << "    neighbor: x" << neighbor->position.getX() << " y" << neighbor->position.getY() << "  heuristic" << neighbor->getHeuristic();

                    if(theBest == nullptr) theBest = neighbor;
                    else if(neighbor->getHeuristic() < theBest->getHeuristic())
                        theBest = neighbor;


                    //qDebug() << "    thebest: x" << theBest->position.getX() << " y" << theBest->position.getX() << "  heuristic" << theBest->getHeuristic();


                    for(it=openPath.begin(); it!=openPath.end(); it++) {
                        temp = *it;
                        if(temp->position == neighbor->position)
                            break;
                    }

                    if(it == openPath.end()) {
                        openPath.push_back(neighbor);
                    } else {
                        qDebug() << "++++++\n\n\n\nachou " << neighbor->position.getX() << neighbor->position.getY();
                        temp->setParent(node);
                        temp->setG(g);
                    }
                }
            }
        }

        //qDebug() << "thebest: x" << theBest->position.getX() << " y" << theBest->position.getX() << "  heuristic" << theBest->getHeuristic();
        if(theBest != nullptr) {
            closedPath.push_back(theBest);
            qDebug() << "add" << theBest->position.getX() << theBest->position.getY();
            openPath.remove(theBest);
        } else if(openPath.size() != 0) {
            qDebug() << "buscar proximo aberto"  ;
            return false;

            getNeighbors( getBest(openPath) );
        } else
            return false;


        if(theBest->position == endNode->position) return true;

        getNeighbors(closedPath.back());
    }

public:

    AStar() {
        labyrinth = nullptr;
    }

    AStar(Labyrinth* labyrinth) {
        this->labyrinth = labyrinth;

        startNode = new Node(nullptr, labyrinth->map->getStartPosition());
        endNode   = new Node(nullptr, labyrinth->map->getEndPosition());

        qDebug() << "startNode " << startNode->position.getX() << " " << startNode->position.getY();
        qDebug() << "endNode " << endNode->position.getX() << " " << endNode->position.getY();
    }

    list<Node*> searchPath() {
        closedPath.push_back(startNode);

        getNeighbors(closedPath.back());

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
        return closedPath;
    }
};

#endif // ASTAR_H
