#include "astar.h"

Node* AStar::inList(list<Node*> l, Position position) {
    list<Node*>::iterator it;
    for(it=l.begin(); it!=l.end(); it++)
        if((*it)->position == position)
            return (*it);

    return nullptr;
}

bool AStar::isFree(Position neighbor) {
    if( ( labyrinth->map->get(neighbor.getX(), neighbor.getY()) != CELL_WALL ) && \
        ( inList(closedPath, neighbor) == nullptr ) )
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

    for(it=l.begin(); it!=l.end(); it++)
        if( (*it)->getHeuristic() < best->getHeuristic() )
            best = (*it);

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
    Node *temp = nullptr;

    int startLine, endLine, \
        startColumn, endColumn;

    int myX = node->position.getX();
    int myY = node->position.getY();

    myX == 0 ? startLine = myX : startLine = myX-1;
    myX == labyrinth->map->getNLines()-1 ? endLine = myX : endLine = myX+1;
    myY == 0 ? startColumn = myY : startColumn = myY-1;
    myY == labyrinth->map->getNColumns()-1 ? endColumn = myY : endColumn = myY+1;

    //
    addInClosedList(node);

    for(int line=startLine; line<=endLine; line++) {
        for(int column=startColumn; column<=endColumn; column++) {

            Position newNeighbor(line,column);

            if( isFree(newNeighbor) )
            {
                temp = inList(openPath, newNeighbor);

                if(temp == nullptr) {
                    Node *neighbor = new Node(node, newNeighbor, \
                                getG(newNeighbor, node), getH(newNeighbor) );
                    addInOpenList(neighbor);
                } else if( temp->getG() > getG(newNeighbor, node) ) {
                    temp->setParent(node);
                    temp->setG( getG(newNeighbor, node) );
                }
            }
        }
    }

    if(openPath.size() != 0)
        theBest = getBest(openPath);
    else return false;

    if(theBest->position == endNode->position)
        return true;
    else getNeighbors(theBest);
}

AStar::AStar() {
    labyrinth = nullptr;
}

AStar::AStar(Labyrinth* labyrinth, int distanceType) {
    this->labyrinth = labyrinth;

    this->distanceType = distanceType;

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
    if(getNeighbors(startNode))
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
