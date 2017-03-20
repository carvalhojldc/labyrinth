#ifndef MATRIX_H
#define MATRIX_H

#include <cstdlib>

class Map {

private:
	int lines, columns;
    int **matrix;

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
};

#endif // MATRIX_H
