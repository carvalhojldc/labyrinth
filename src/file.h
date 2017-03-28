#ifndef FILE_H
#define FILE_H

#include <QFile>
#include "labyrinth.h"

#include <QDebug>

class File {

public:

    float getDiagonal(float a, float b)
    {
        float cost;
        float d = 100;

        cost = sqrt( pow(a,2) + pow(b,2) );

        cost = int(cost*d);
        return cost/d;
    }

    bool writeLabyrinthFile(Labyrinth* labyrinth, QString saveLabyrinthFile)
    {
        QFile labyrinthFile(saveLabyrinthFile);

        if( ! labyrinthFile.open(QIODevice::WriteOnly) ) {
            QMessageBox::critical(
                0,
                "Error: create labyrinth",
                labyrinthFile.errorString());
            return false;
        }

        QTextStream out( &labyrinthFile );

        int lines = labyrinth->map->getNLines();
        int columns = labyrinth->map->getNColumns();

        out << lines << ' '
            << columns << ' '
            << labyrinth->getCostHorizontal() << ' '
            << labyrinth->getCostVertical() << endl;


        for(int l = 0; l<lines; l++) {
            for(int c = 0; c<columns; c++) {
                out << labyrinth->map->get(l,c);

                if(c != columns-1)
                    out << ' ';

            }
            out << endl;
        }

        labyrinthFile.close();

        QMessageBox::information(
                    0,
                    "Success",
                    "Labyrinth saved");

        return true;
    }

    bool readLabyrinthFile(Labyrinth* labyrinth, QString file)
    {
        QString line;
        QStringList listLine;

        QFile labyrinthFile(file);

        if( ! labyrinthFile.open(QIODevice::ReadOnly) ) {
            QMessageBox::critical(
                0,
                "Error: opening labyrinth",
                labyrinthFile.errorString());

            return false;
        }

        QTextStream in(&labyrinthFile);

        line = in.readLine();
        listLine = line.split(" ");

        // validation
        if( listLine.size() != 4 ) {
            qDebug() << "error:labyrinth:validation_config";
            return false;
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
                return false;
            }

            line = in.readLine();
            listLine = line.split(" ");

            if( listLine.size() != numberColumns ) {
                qDebug() << "error:labyrinth:validation_columns_size";
                return false;
            }

            for(int c=0; c<listLine.size(); c++) {
                positionValue = listLine.at(c).toInt();
                if( positionValue < 0 || positionValue > 3 ) {
                    qDebug() << "error:labyrinth:validation_elements";
                    return false;
                }
            }
        }

        if( countLines != numberLines ) {
            qDebug() << "error:labyrinth:validation_lines_size";
            return false;
        }
         labyrinthFile.close();
        // end all_validataion
        // ---------------------------

        labyrinth->map->setNewSize(numberLines, numberColumns);

        for(int line=0; line<numberLines; line++) {
            for(int column=0; column<numberColumns; column++) {
                labyrinth->map->set(line, column, labyrinthTemp[line][column]);
            }
        }

        labyrinth->setCostDiagonal( getDiagonal(costVertical, costHorizontal) );
        labyrinth->setCostVertical(costVertical);
        labyrinth->setCostHorizontal(costHorizontal);

        return true;
    }
};

#endif // FILE_H
