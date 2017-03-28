#include "map.h"

int* Map::allocColumns(int size)
{ return (int*)malloc(size*sizeof(int)); }

int** Map::allocLines(int size)
{ return (int**)malloc(size*sizeof(int*)); }

int** Map::allocMatrix(int lines, int columns) {
    int **matrix = allocLines(lines);

    for(int line=0; line<lines; line++) {
        matrix[line] = allocColumns(columns);
        zeroColumns(matrix[line], 0, columns);
    }

    return matrix;
}

int* Map::resizeColumns(int column, int newSize)
{ return (int*)realloc(matrix[column], newSize*sizeof(int)); }

int** Map::resizeLines(int newSize)
{ return (int**)realloc(matrix, newSize*sizeof(int*)); }

bool Map::validatePosition(int line, int column) {
    if(matrix == NULL || line<0 || column<0 || \
            this->lines<line || this->columns<column)
        return false;

    return true;
}

void Map::zeroColumns(int* Line, int start, int end) {
    for(int column=start; column<end; column++) {
        Line[column] = 0;
    }
}

Map::Map() {
    matrix  = nullptr;
    lines   = 0;
    columns = 0;
}

Map::Map( int lines, int columns) {
    this->matrix  = allocMatrix(lines, columns);
    this->lines   = lines;
    this->columns = columns;
}

Map::~Map() {
    clear();
}

void Map::clear() {
    for(int line=0; line<lines; line++)
        free(matrix[line]);

    free(matrix);

    matrix  = NULL;
    lines   = 0;
    columns = 0;
}

void Map::setBoardColor(Position position, int color) {

    QString sColor;

    switch (color) {
    case CELL_END:
        sColor = colors.end;
        break;
    case CELL_FREE:
        sColor = colors.free;
        break;
    case CELL_START:
        sColor = colors.start;
        break;
    case CELL_WALL:
        sColor = colors.wall;
        break;
    case CELL_PATH:
        sColor = colors.path;
        break;
    case CELL_OPEN_LIST:
        sColor = colors.openList;
        break;
    case CELL_CLOSED_LIST:
        sColor = colors.closedList;
        break;
    }

    this->board->item(position.getX(), position.getY())->setBackgroundColor(sColor);
}

bool Map::set(int line, int column, int value) {
    if(validatePosition(line,column) == false)
        return false;

    matrix[line][column] = value;
    //setBoardColor(line, column, value);

    if(value == CELL_START) {
        startPosition.setPosition(line, column);
    } else if(value == CELL_END) {
        endPosition.setPosition(line, column);
    } else {
        Position temp(line, column);

        if(temp == startPosition)
            startPosition.setPosition(-1,-1);
        else if(temp == endPosition)
            endPosition.setPosition(-1,-1);
    }

    return true;
}

int Map::get(int line, int column) {
    if(validatePosition(line,column) == false)
        return 0;

    return matrix[line][column];
}

int Map::getNLines(void) const
{ return lines; }

int Map::getNColumns(void) const
{ return columns; }

void Map::setNewSize(int lines, int columns) {
    if(this->lines != lines && this->columns != columns) {
        matrix = resizeLines(lines);

        for(int line=0; line<lines; line++) {
            if(line<this->lines){
                matrix[line] = resizeColumns(line, columns);
                zeroColumns(matrix[line], this->columns, columns);

            } else {
                matrix[line] = allocColumns(columns);
                zeroColumns(matrix[line], 0, columns);
            }
        }
        this->lines = lines;
        this->columns = columns;
    }
    else if(this->lines != lines) {
        matrix = resizeLines(lines);

        if(this->lines < lines) {
            for(int line=this->lines; line<lines; line++) {
                matrix[line] = allocColumns(this->columns);
                zeroColumns(matrix[line], 0, columns);
            }
        }
        this->lines = lines;
    }
    else if(this->columns != columns) {
        for(int line=0; line<this->lines; line++) {
            matrix[line] = resizeColumns(line, columns);
            zeroColumns(matrix[line], this->columns, columns);
        }
        this->columns = columns;
    }
}

void Map::setBoard(QTableWidget *board) {
    this->board = board;

    qDebug() << "teste da board";
    //this->board->item(0,0)->setBackground(Qt::red);

    //this->board->item(0, 0)\
                            ->setBackgroundColor(Qt::red);
}

Position Map::getStartPosition()
{ return startPosition; }

Position Map::getEndPosition()
{ return endPosition; }

