#ifndef MATRIX_H
#define MATRIX_H

#include <QTableWidget>
#include <cstdlib>
#include "position.h"

#include <QDebug>

struct Colors {
    const QString start = "green";
    const QString end   = "blue";
    const QString wall  = "black";
    const QString free  = "white";
};

#define CELL_FREE  0
#define CELL_WALL  1
#define CELL_START 2
#define CELL_END   3

class Map {

private:
	int lines, columns;
    int **matrix;
    QTableWidget *board;
    Colors colors;

    Position startPosition, \
             endPosition;

    int* allocColumns(int size);

    int** allocLines(int size);

	int** allocMatrix(int lines, int columns);

    int* resizeColumns(int column, int newSize);

    int** resizeLines(int newSize);

    bool validatePosition(int line, int column);

    void zeroColumns(int* Line, int start, int end);

public:

    Map();

    Map(int lines, int columns);

    ~Map();

    void clear();

    bool set(int line, int column, int value);

    int get(int line, int column);

    int getNLines(void) const;

    int getNColumns(void) const;

    void setNewSize(int newLines, int newColumns);

    void setBoard(QTableWidget *board);

    Position getStartPosition();
    Position getEndPosition();
};

#endif // MATRIX_H
