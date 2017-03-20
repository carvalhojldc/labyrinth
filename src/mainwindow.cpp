#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // var

    // for import/save labyrinth file
    this->userName = qgetenv("USER");
    if(this->userName.isEmpty())
        this->userName = qgetenv("USERNAME");
    this->userDir = "/home/" + this->userName;

    startPosition.line   = 0;
    startPosition.column = 0;
    startPosition.active = false;

    endPosition.line   = 1;
    endPosition.column = 1;
    endPosition.active = false;

    labyrinth = new Labyrinth(10, 10, 1, 2, getDiagonal(1, 2));

    // end var
    // --------------

    // connect

    // for menu
    connect(ui->actionImportLabyrinth, SIGNAL(triggered(bool)), this, SLOT(UI_ImportLabyrinth()));
    connect(ui->actionSaveLabyrinth,   SIGNAL(triggered(bool)), this, SLOT(UI_SaveLabyrinth()));
    connect(ui->actionLicense,         SIGNAL(triggered(bool)), this, SLOT(UI_license()));
    connect(ui->actionHelp,            SIGNAL(triggered(bool)), this, SLOT(UI_help()));

    connect(ui->pb_clearBoard, SIGNAL(clicked(bool)), this, SLOT(UI_clearBoard()));
    connect(ui->pb_newBoard,   SIGNAL(clicked(bool)), this, SLOT(UI_newBoard()));

    connect(ui->board, SIGNAL(cellClicked(int,int)), this, SLOT(UI_changeCell(int,int)));

    connect(ui->sb_costHorizontal, SIGNAL(valueChanged(double)), this, SLOT(UI_newCostDiagonal()));
    connect(ui->sb_costVertical,   SIGNAL(valueChanged(double)), this, SLOT(UI_newCostDiagonal()));

    connect(ui->sb_costDiagonal,   SIGNAL(valueChanged(double)), this, SLOT(UI_changeButtonUpdate()));
    connect(ui->sb_columns,        SIGNAL(valueChanged(int)), this, SLOT(UI_changeButtonUpdate()));
    connect(ui->sb_lines,          SIGNAL(valueChanged(int)), this, SLOT(UI_changeButtonUpdate()));

    connect(ui->cb_costDiagonal, SIGNAL(clicked(bool)), this, SLOT(UI_EditCostDiagonal(bool)));

    connect(ui->pb_start, SIGNAL(clicked(bool)), this, SLOT(start()));

    // end connect
    // --------------

    // UI
    UI_setConfig();
    UI_setBoard();
    UI_updateUI();

    // end UI
    // --------------
}

MainWindow::~MainWindow()
{
    delete ui;

    delete labyrinth;
}

void MainWindow::UI_license()
{
    QString licenseText = program + "\
\n\n\
Copyright (C) 2017 - João Leite de Carvalho (carvalhojldc@gmail.com)\n\n\
This program is free software: you can redistribute it and/or modify \
it under the terms of the GNU General Public License as published by \
the Free Software Foundation, either version 3 of the License, or \
(at your option) any later version.\n\n\
This program is distributed in the hope that it will be useful, \
but WITHOUT ANY WARRANTY; without even the implied warranty of \
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the \
GNU General Public License for more details.\n\n\
You should have received a copy of the GNU General Public License \
along with this program. If not, see \n<http://www.gnu.org/licenses/>.";

    QMessageBox *license = new QMessageBox(this);

    license->setText(licenseText);
    license->setWindowTitle("License");

    license->exec();
}

void MainWindow::UI_help()
{
    QString helpText = program + "\
\n\n\
Este programa tem como objetivo aplicar o\n\
algoritmo A* na resolução de rotas.\n\n\
Defina um ponto de partida, um ponto final\n\
e crie o labirinto a ser resolvido.\n\n\
https://carvalhojldc.github.com/labyrinth\n\n\
João Leite de Carvalho - carvalhojldc@gmail.com";

    QMessageBox *help = new QMessageBox(this);

    help->setText(helpText);
    help->setWindowTitle("Help");

    help->exec();
}

void MainWindow::UI_updateUI()
{
    ui->sb_lines->setValue( labyrinth->map->getNLines() );
    ui->sb_columns->setValue( labyrinth->map->getNColumns() );
    ui->sb_costHorizontal->setValue( labyrinth->getCostHorizontal() );
    ui->sb_costVertical->setValue( labyrinth->getCostVertical() );
    ui->sb_costDiagonal->setValue( labyrinth->getCostDiagonal() );

    ui->pb_newBoard->setDisabled(true);
    ui->pb_newBoard->setStyleSheet("background-color: none");
}

void MainWindow::UI_setConfig()
{
    ui->actionImportLabyrinth->setIcon(this->style()->standardIcon(QStyle::SP_FileIcon));
    ui->actionSaveLabyrinth->setIcon(this->style()->standardIcon(QStyle::SP_DialogSaveButton));
    ui->actionHelp->setIcon(this->style()->standardIcon(QStyle::SP_DialogHelpButton));
    ui->actionLicense->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));

    ui->pb_newBoard->setIcon(this->style()->standardIcon(QStyle::SP_BrowserReload));
    ui->pb_clearBoard->setIcon(this->style()->standardIcon(QStyle::SP_TrashIcon));
    ui->pb_start->setIcon(this->style()->standardIcon(QStyle::SP_DialogYesButton));

    ui->rb_wall->setIcon(QIcon("../icons/colors/" + colors.wall + ".png"));
    ui->rb_start->setIcon(QIcon("../icons/colors/" + colors.start + ".png"));
    ui->rb_end->setIcon(QIcon("../icons/colors/" + colors.end + ".png"));
    ui->rb_clearCell->setIcon(QIcon("../icons/colors/" + colors.free + ".png"));

    ui->cb_costDiagonal->setChecked(true);
    ui->sb_costDiagonal->setEnabled(false);
}

void MainWindow::UI_setBoard()
{
    int lines = labyrinth->map->getNLines();
    int columns = labyrinth->map->getNColumns();

    ui->board->setRowCount(lines);
    ui->board->setColumnCount(columns);

    UI_createCellsBoard(0, lines, 0, columns);

    ui->board->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->board->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::UI_changeButtonUpdate()
{
    ui->pb_newBoard->setDisabled(false);
    ui->pb_newBoard->setStyleSheet("background-color: red");
}

void MainWindow::UI_clearBoard()
{
    for(int l=0; l<labyrinth->map->getNLines(); l++) {
        for(int c=0; c<labyrinth->map->getNColumns(); c++) {
            UI_setCellValue(l,c,CELL_FREE);
        }
    }
}

void MainWindow::UI_setCellValue(int line, int column, int value)
{
    switch (value) {
        case CELL_START:
            ui->board->item(line,column)->setBackgroundColor(colors.start);
            labyrinth->map->set(line, column, CELL_START);

            if(startPosition.active) {
                ui->board->item(startPosition.line, startPosition.column)\
                        ->setBackgroundColor(colors.free);

                labyrinth->map->set(startPosition.line, startPosition.column, CELL_FREE);
            }

            disableEndCell(line, column);

            startPosition.line   = line;
            startPosition.column = column;
            startPosition.active = true;
            break;

        case CELL_END:
            ui->board->item(line,column)->setBackgroundColor(colors.end);
            labyrinth->map->set(line, column, CELL_END);

            if(endPosition.active) {
                ui->board->item(endPosition.line, endPosition.column)\
                        ->setBackgroundColor(colors.free);

                labyrinth->map->set(endPosition.line, endPosition.column, CELL_FREE);
            }
            disableStartCell(line, column);

            endPosition.line   = line;
            endPosition.column = column;
            endPosition.active = true;
            break;

        case CELL_FREE:
            ui->board->item(line,column)->setBackgroundColor(colors.free);
            labyrinth->map->set(line, column, CELL_FREE);

            disableStartCell(line, column);
            disableEndCell(line, column);
            break;

        case CELL_WALL:
            ui->board->item(line,column)->setBackgroundColor(colors.wall);
            labyrinth->map->set(line, column, CELL_WALL);

            disableStartCell(line, column);
            disableEndCell(line, column);
            break;
    }
}

void MainWindow::UI_createCellsBoard(int startLine, int endLine, \
            int startColumn, int endColumn)
{
    for(int l=startLine; l<endLine; l++) {
        for(int c=startColumn; c<endColumn; c++) {
            ui->board->setItem(l, c, new QTableWidgetItem(0));
            UI_setCellValue(l, c, CELL_FREE);
        }
    }
}

void MainWindow::UI_resizeBoard(int lines, int columns)
{
    int oldLines = labyrinth->map->getNLines();
    int oldColumns = labyrinth->map->getNColumns();

    labyrinth->map->setNewSize(lines, columns);

    if(lines != oldLines) {
        ui->board->setRowCount(lines);

        // resize
        if(lines > oldLines)
            UI_createCellsBoard(oldLines, lines, 0, oldColumns);

        if(startPosition.line > lines)
            startPosition.active = false;
        else if(endPosition.line > lines)
            endPosition.active = false;
    }

    if(columns != oldColumns) {
        ui->board->setColumnCount(columns);

        // resize
        if(columns > oldColumns)
            UI_createCellsBoard(0, oldLines, oldColumns, columns);

        if(startPosition.column > columns)
            startPosition.active = false;
        else if(endPosition.column > columns)
            endPosition.active = false;
    }
}

void MainWindow::UI_newBoard()
{
    labyrinth->setCostDiagonal( ui->sb_costHorizontal->value() );
    labyrinth->setCostVertical( ui->sb_costVertical->value() );
    labyrinth->setCostDiagonal( ui->sb_costDiagonal->value() );

    UI_resizeBoard(ui->sb_lines->value(), ui->sb_columns->value());

    ui->pb_newBoard->setDisabled(true);
    ui->pb_newBoard->setStyleSheet("background-color: none");
}

void MainWindow::disableStartCell(int line, int column)
{
    if(line == startPosition.line && column == startPosition.column)
        startPosition.active = false;
}

void MainWindow::disableEndCell(int line, int column)
{
    if(line == endPosition.line && column == endPosition.column)
        endPosition.active = false;
}

void MainWindow::UI_changeCell(int line, int column)
{
    if(ui->rb_start->isChecked() && ((this->startPosition.line != line \
            || this->startPosition.column != column) || this->startPosition.active == false) )
        UI_setCellValue(line,column, CELL_START);
    else if(ui->rb_end->isChecked() && (this->endPosition.line != line \
            || this->endPosition.column != column) )
        UI_setCellValue(line, column, CELL_END);
    else if(ui->rb_wall->isChecked())
        UI_setCellValue(line, column, CELL_WALL);
    else if(ui->rb_clearCell->isChecked())
        UI_setCellValue(line, column, CELL_FREE);
}

bool MainWindow::UI_ReadLabyrinthFile(QString importLabyrinthFile)
{
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

    labyrinth->setCostHorizontal(costHorizontal);
    labyrinth->setCostVertical(costHorizontal);
    labyrinth->setCostDiagonal(getDiagonal(costHorizontal, costVertical));

    //allocateLabyrinth();

    UI_clearBoard();
    UI_resizeBoard(numberLines, numberColumns);

    for(int l=0; l < labyrinth->map->getNLines(); l++) {
        for(int c=0; c < labyrinth->map->getNColumns(); c++) {
            UI_setCellValue(l,c,labyrinthTemp[l][c]);
        }
    }

    UI_updateUI();

    labyrinthFile.close();

    return true;
}

void MainWindow::UI_ImportLabyrinth()
{
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
}

bool MainWindow::UI_WriteLabyrinthFile(QString saveLabyrinthFile)
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
        << labyrinth->getCostDiagonal() << endl;


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

void MainWindow::UI_SaveLabyrinth()
{
    saveLabyrinthFile = QFileDialog::getSaveFileName(
            this,
            tr("Save Labyrinth"),
            userDir,
            "Text File (*.txt)");

    if(saveLabyrinthFile.isEmpty()) return;

    if (! saveLabyrinthFile.endsWith(".txt", Qt::CaseInsensitive) )
        saveLabyrinthFile += ".txt";

    UI_WriteLabyrinthFile(saveLabyrinthFile);
}

void MainWindow::UI_newCostDiagonal()
{
    if(ui->cb_costDiagonal->isChecked() == true) {
        float costHorizontal = ui->sb_costHorizontal->value();
        float costVertical = ui->sb_costVertical->value();
        float costDiagonal = getDiagonal(costHorizontal, costVertical);

        ui->sb_costDiagonal->setValue(costDiagonal);
    }
}

void MainWindow::UI_EditCostDiagonal(bool value)
{
    ui->sb_costDiagonal->setDisabled(value);
}

float MainWindow::getDiagonal(float a, float b)
{
    float cost;
    float d = 100;

    cost = sqrt( pow(a,2) + pow(b,2) );

    cost = int(cost*d);
    return cost/d;
}


void MainWindow::start()
{
    //this->costDiagonal   = ui->sb_costDiagonal->value();
    //this->costVertical   = ui->sb_costVertical->value();
    //this->costHorizontal = ui->sb_costHorizontal->value();

    qDebug() << "run";
}

float MainWindow::euclideanDistance(int line, int column)
{
    // d(position,end) = sqrt( (xp-xe)^2 + (xp-xe)^2 )

    float px = pow(line - endPosition.line, 2);
    float py = pow(column - endPosition.column, 2);

    return sqrt(px+py);
}

void MainWindow::a_star()
{

    // Distance measurement
    float hl;

    // cost of movement
    float gl;

    // heuristic ( fl = gl + hl)
    float fl;

    //list<int> openPaths;
    //list<int> closePaths;


}
