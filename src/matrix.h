#ifndef MATRIX_H
#define MATRIX_H

#include <cstdlib>

class Matrix {

private:
	int lines, columns;
	int **matrix;

	int* allocColumns(int size) {
		return (int*)malloc(size*sizeof(int));
	}

	int** allocLines(int size) {
		return (int**)malloc(size*sizeof(int*));
	}

	int* resizeColumns(int column, int newSize) {
		return (int*)realloc(matrix[column], newSize*sizeof(int));
	}

	int** resizeLines(int newSize) {
		return (int**)realloc(matrix, newSize*sizeof(int*));
	}

	bool validatePosition(int line, int column) {
		if(matrix == NULL || line<0 || column<0 || \
				this->lines<line || this->columns<column)
			return false;

		return true;
	}

	void zeroColumns(int* Line, int start, int end) {
		for(int column=start; column<end; column++) {
			Line[column] = 0;
		}
	}

public:

	Matrix() {
		matrix = NULL;

		this->lines = 0;
		this->columns = 0;
	}

	Matrix(int lines, int columns) {
		matrix = allocLines(lines);

		for(int line=0; line<lines; line++) {
			matrix[line] = allocColumns(columns);
			zeroColumns(matrix[line], 0, columns);
		}

		this->lines = lines;
		this->columns = columns;
	}

	~Matrix() {
		for(int line=0; line<this->lines; line++) {
			free(matrix[line]);
		}
		free(matrix);
	}

	bool set(int line, int column, int value) {
		if(validatePosition(line,column) == false)
		    return false;

		matrix[line][column] = value;

		return true;
	}

	int at(int line, int column) {
		if(validatePosition(line,column) == false)
		    return 0;

		return matrix[line][column];
	}

    void newSize(int newLines, int newColumns) {

		if(this->lines != newLines && this->columns != newColumns)
		{
		    matrix = resizeLines(newLines);

		    for(int line=0; line<newLines; line++) {
		        if(line<this->lines){
		            matrix[line] = resizeColumns(line, newColumns);

					zeroColumns(matrix[line], this->columns, newColumns);

		        } else {
		            matrix[line] = allocColumns(newColumns);

					zeroColumns(matrix[line], 0, newColumns);
		        }
		    }

		    this->lines = newLines;
		    this->columns = newColumns;
		}
		else if(this->lines != newLines)
		{
		    matrix = resizeLines(newLines);

		    if(this->lines < newLines)
		    {
		        for(int line=this->lines; line<newLines; line++) {
		            matrix[line] = allocColumns(this->columns);

					zeroColumns(matrix[line], 0, newColumns);
		        }
		    }

		    this->lines = newLines;
		}
		else if(this->columns != newColumns)
		{
		    for(int line=0; line<this->lines; line++) {
		        matrix[line] = resizeColumns(line, newColumns);

				zeroColumns(matrix[line], this->columns, newColumns);
		    }

		    this->columns = newColumns;
		}
	}
};

#endif // MATRIX_H
