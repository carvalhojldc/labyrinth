#include "astar.h"

bool AStar::inList(list<Node*> l, Position position) {
    list<Node*>::iterator it;
    for(it=l.begin(); it!=l.end(); it++) {
        if((*it)->position == position)
            return true;
    }
    return false;
}

bool AStar::isFree(Node* node, Position neighbor) {
    Node* parent = node->getParent();

    if( ( labyrinth->map->get(neighbor.getX(), neighbor.getY()) != CELL_WALL ) && \
        ( node->position != neighbor) && \
        ( parent == nullptr || parent->position != neighbor ) )
        return true;

    return false;
}

float AStar::getH(Position position) {
    float distance = 0;

    if(distanceType == MANHATTAN_DISTANCE) {
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

float AStar::getG(Position position, Node* parent) {
    if(position.getX() == parent->position.getX())
        return labyrinth->getCostHorizontal();
    else if(position.getY() == parent->position.getY())
        return labyrinth->getCostVertical();
    else
        return labyrinth->getCostDiagonal();
}

Node* AStar::getBest(list<Node*> l) {
    list<Node*>::iterator it;
    Node *best = l.front();

    for(it=l.begin(); it!=l.end(); it++) {
        if((*it) < best) best = (*it);
    }

    return best;
}

bool AStar::removeNodeList(list<Node*>& l, Node* node) {
    list<Node*>::iterator it;
    for(it=l.begin();it!=l.end(); it++) {
        if((*it)->position == node->position) {
            l.erase(it);
            return true;
        }
    }
    return false;
}

void AStar::addInOpenList(Node* node) {
    openPath.push_back(node);

    if(node->position != endNode->position && node->position != startNode->position)
        labyrinth->map->setBoardColor(node->position, CELL_OPEN_LIST);
}

void AStar::addInClosedList(Node* node) {
    closedPath.push_back(node);
    removeNodeList(openPath, node);

    if(node->position != endNode->position && node->position != startNode->position)
        labyrinth->map->setBoardColor(node->position, CELL_CLOSED_LIST);
}

bool AStar::getNeighbors(Node* node) {
    list<Node*>::iterator it;
    Node *theBest = nullptr;

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

            if(newNeighbor==endNode->position) {
                theBest = endNode;
                theBest->setParent(node);
                break;
            }

            if( isFree(node, newNeighbor) && !inList(closedPath, newNeighbor) )
            {
                Node *neighbor = new Node(node, newNeighbor, \
                                getG(newNeighbor, node), \
                                getH(newNeighbor) );

                if(theBest == nullptr)
                    theBest = neighbor;
                else if(neighbor->getHeuristic() < theBest->getHeuristic())
                    theBest = neighbor;

                for(it=openPath.begin(); it!=openPath.end(); it++) {
                    if((*it)->position == neighbor->position)
                        break;
                }

                if(it == openPath.end()) {
                    addInOpenList(neighbor);
                } else {
                    (*it)->setParent(node);
                    (*it)->setG( getG(newNeighbor, node) );
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

AStar::AStar() {
    labyrinth = nullptr;
}

AStar::AStar(Labyrinth* labyrinth) {
    this->labyrinth = labyrinth;

    distanceType = EUCLIDEAN_DISTANCE;

    startNode = new Node(nullptr, labyrinth->map->getStartPosition());
    endNode   = new Node(nullptr, labyrinth->map->getEndPosition());
}

list<Node*> AStar::getMyPath() const
{ return myPath; }

list<Node*> AStar::getClosedPath() const
{ return closedPath; }

list<Node*> AStar::getOpenPath() const
{ return openPath; }

void AStar::searchPath() {
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
}
