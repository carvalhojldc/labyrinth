#ifndef FILE_H
#define FILE_H

#include <QDebug>
#include "labyrinth.h"

class File {

public:
    File() {
    }

    ~File() {
    }

    Labyrinth* readLabyrinthFile(QString file) {
        QString line;
        QStringList listLine;

        Labyrinth* labyrinth;
        Map* map;

        QFile labyrinthFile(file);

        if( ! labyrinthFile.open(QIODevice::ReadOnly) ) {
            QMessageBox::critical(
                0,
                "Error: opening labyrinth",
                labyrinthFile.errorString());

            return NULL;
        }

        QTextStream in(&labyrinthFile);

        line = in.readLine();
        listLine = line.split(" ");

        // validation
        if( listLine.size() != 4 ) {
            qDebug() << "error:labyrinth:validation_config";
            return NULL;
        }

        int countLines;
        int positionValue;
        int numberLines    = listLine.at(0).toInt();
        int numberColumns  = listLine.at(1).toInt();
        int costHorizontal = listLine.at(2).toInt();
        int costVertical   = listLine.at(3).toInt();

        int labyrinthTemp[numberLines][numberColumns];

        for(countLines=0; ! in.atEnd(); countLines++) {
            if( numberLines < countLines ) {
                qDebug() << "error:labyrinth:validation_lines_size";
                return NULL;
            }

            line = in.readLine();
            listLine = line.split(" ");

            if( listLine.size() != numberColumns ) {
                qDebug() << "error:labyrinth:validation_columns_size";
                return NULL;
            }

            for(int c=0; c<listLine.size(); c++) {
                positionValue = listLine.at(c).toInt();
                if( positionValue < 0 || positionValue > 3 ) {
                    qDebug() << "error:labyrinth:validation_elements";
                    return NULL;
                }
            }
        }

        if( countLines != numberLines ) {
            qDebug() << "error:labyrinth:validation_lines_size";
            return NULL;
        }
        // end all_validataion
        // ---------------------------

        map = new Map(numberLines, numberColumns);

        for(int line=0; line<numberLines; line++) {
            for(int column=0; column<numberColumns; column++) {
                map->set(line, column, labyrinthTemp[line][column]);
            }
        }

        labyrinth = new Labyrinth(map, costHorizontal, costVertical, 0);

        return labyrinth;
    }
};

#endif // FILE_H
