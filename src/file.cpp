#include "file.h"

File::File()
{

}

void File::readLabyrinthFile(QString importLabyrinthFile) {
    QString line;
    QStringList listLine;

    QFile labyrinthFile(importLabyrinthFile);

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

    Matrix *labyrinthTemp = new Matrix(numberLines, numberColumns);
    //int labyrinthTemp[numberLines][numberColumns];

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
            labyrinthTemp[countLines][c] = positionValue;
        }
    }

    if( countLines != numberLines ) {
        qDebug() << "error:labyrinth:validation_lines_size";
        return false;
    }
    // end all_validataion
    // ---------------------------

    //deleteLabyrinth();

    this->costHorizontal = costHorizontal;
    this->costVertical = costVertical;
    this->costDiagonal = getDiagonal(this->costHorizontal, this->costVertical);

    //allocateLabyrinth();

    //UI_clearBoard();
    //UI_resizeBoard(numberLines, numberColumns);

    for(int l=0; l < this->lines; l++) {
        for(int c=0; c < this->columns; c++) {
            UI_setCellValue(l,c,labyrinthTemp[l][c]);
        }
    }

    UI_updateUI();

    labyrinthFile.close();

    return true;
}

Matrix* File::importLabyrinth() {
    importLabyrinthFile = QFileDialog::getOpenFileName(
            this,
            tr("Import Labyrinth"),
            userDir,
            "Text File (*.txt)");

    if( importLabyrinthFile.isEmpty() == true ) return;

    if( UI_ReadLabyrinthFile(importLabyrinthFile) == false ) {
        QMessageBox::critical(
            0,
            "Erro na leitura",
            "Configuração inválida no arquivo \n" + importLabyrinthFile);
    }

    return
}
