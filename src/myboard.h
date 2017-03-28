#ifndef MYBOARD_H
#define MYBOARD_H

#include <QTableWidget>
#include "map.h"

class Board {
private:
    Map* map;
    QTableWidget* board;
    Colors colors;

    int lines, columns;

    bool setValue(int lines, int columns) {
        ui->board->item(line,column)->setBackgroundColor(colors.start);
    }

    bool UI_createCell(int sLine, int eLine, int sColumn, int eColumn) {
        for(int l=sLine; l<eLine; l++) {
            for(int c=sLine; c<eColumn; c++) {
                this->board->setItem(l, c, new QTableWidgetItem(0));
                this->board->item(line,column)->setBackgroundColor(colors.start);
            }
        }
    }

    bool UI_setNewSize(int lines, int columns) {
        if(lines )
    }

public:
    Board(Map* map, QTableWidget* board) {
        this->map = map;
        this->board = board;

        lines = map->getNLines();
        columns = map->getNColumns();

        this->board->setRowCount(lines);
        this->board->setColumnCount(columns);

        UI_createCell(0, lines, 0, columns);
    }

    bool resizeMyBoard(int lines, int columns) {
        map->setNewSize(lines, columns);
        UI_setNewSize(lines, columns);
    }
};

#endif // MYBOARD_H
