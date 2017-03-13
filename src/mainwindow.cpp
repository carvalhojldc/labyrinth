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
#ifdef linux
    this->userDir = "/home/" + this->userName;
#elif _WIN32 || _WIN64
    this->userDir = "C:\Users\" + this->userName;
#endif

    this->lines          = 10;
    this->columns        = 10;
    this->costHorizontal = 1;
    this->costVertical   = 2;
    this->costDiagonal   = getCostDiagonal();

    this->labyrinth = nullptr;
    allocateLabyrinth();

    this->startPosition.line = 0;
    this->startPosition.column = 0;
    this->endPosition.line = this->startPosition.line+1;
    this->endPosition.column = this->startPosition.column+1;

    // end var
    // --------------

    // connect

    // for menu
    connect(ui->actionImportLabyrinth, SIGNAL(triggered(bool)), this, SLOT(UI_ImportLabyrinth()));
    connect(ui->actionSaveLabyrinth,   SIGNAL(triggered(bool)), this, SLOT(UI_SaveLabyrinth()));
    connect(ui->actionLicense,         SIGNAL(triggered(bool)), this, SLOT(UI_license()));
    connect(ui->actionHelp,            SIGNAL(triggered(bool)), this, SLOT(UI_help()));

    connect(ui->board, SIGNAL(cellClicked(int,int)), this, SLOT(UI_changeType(int,int)));

    // end connect
    // --------------

    // UI
    UI_setConfig();
    UI_setBoard();

    // end UI
    // --------------
}

MainWindow::~MainWindow()
{
    delete ui;

    deleteLabyrinth();
}

void MainWindow::UI_setConfig()
{
    ui->sb_lines->setValue( this->lines );
    ui->sb_columns->setValue( this->columns );
    ui->sb_costHorizontal->setValue( this->costHorizontal );
    ui->sb_costVertical->setValue( this->costVertical );
    ui->sb_costDiagonal->setValue( this->costDiagonal );

    ui->rb_wall->setIcon(QIcon("../icons/colors/" + colors.wall + ".png"));
    ui->rb_start->setIcon(QIcon("../icons/colors/" + colors.start + ".png"));
    ui->rb_end->setIcon(QIcon("../icons/colors/" + colors.end + ".png"));
}

void MainWindow::UI_setBoard()
{
    ui->board->setRowCount(this->lines);
    ui->board->setColumnCount(this->columns);
    ui->board->verticalHeader()->setVisible(false);
    ui->board->horizontalHeader()->setVisible(false);
    ui->board->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->board->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // ui->board->horizontalHeader()->setStretchLastSection( true );
     //ui->board->verticalHeader()->setStretchLastSection( true );

    for(int l=0; l<this->lines; l++)
    {
        for(int c=0; c<this->columns; c++)
        {
            ui->board->setItem(l, c, new QTableWidgetItem(0));
            ui->board->item(l, c)->setData(0,CELL_FREE);
        }
    }

    //ui->board->item(this->startPosition.line,this->startPosition.column)->data(0) = CELL_START;
    //ui->board->item(this->startPosition.line,this->startPosition.column)->setBackgroundColor(Qt::green);

    //ui->board->item(this->endPosition.line,this->endPosition.column)->data(0) = CELL_END;
    //ui->board->item(this->endPosition.line,this->endPosition.column)->setBackgroundColor(Qt::blue);
}

void MainWindow::UI_license()
{
    QString licenseText = programTitle + "\
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
    QString helpText = programTitle + "\
\n\n\
Este programa tem como objetivo aplicar o\n\
algoritmo A* na resolução de rotas.\n\n\
Defina um ponto de partida, um ponto final\n\
e crie o labirinto a ser resolvido.\n\n\
Como usar:\n\
* Um clique para definir o ponto de partida;\n\
* Dois cliques para definir uma barreira;\n\
* Três cliques para definir o ponto final;\n\
* Quatro cliques para deixar a posição em branco.\n\n\
Clique em \"Start\" para resolver o labirinto.\n\n\
https://carvalhojldc.github.com/labyrinth\n\n\
João Leite de Carvalho - carvalhojldc@gmail.com";

    QMessageBox *help = new QMessageBox(this);

    help->setText(helpText);
    help->setWindowTitle("Help");

    help->exec();
}

bool MainWindow::UI_ReadLabyrinthFile(QString importLabyrinthFile)
{
    QString line;
    QStringList listLine;

    QFile labyrinthFile(importLabyrinthFile);

    if( ! labyrinthFile.open(QIODevice::ReadOnly) )
    {
        QMessageBox::critical(
            0,
            "Error: opening labyrinth",
            labyrinthFile.errorString());

        return false;
    }

    QTextStream in(&labyrinthFile);

    line = in.readLine();
    listLine = line.split(" ");

    if( listLine.size() != 4 )
    {
        qDebug() << "error:labyrinth:validation_config";
        return false;
    }
    else
    {
        int countLines;
        int positionValue;
        int numberLines    = listLine.at(0).toInt();
        int numberColumns  = listLine.at(1).toInt();
        int costHorizontal = listLine.at(2).toInt();
        int costVertical   = listLine.at(3).toInt();

        int labyrinth[numberLines][numberColumns];

        for(countLines=0; ! in.atEnd(); countLines++)
        {
            if( numberLines < countLines )
            {
                qDebug() << "error:labyrinth:validation_lines_size";
                return false;
            }

            line = in.readLine();
            listLine = line.split(" ");

            if( listLine.size() != numberColumns )
            {
                qDebug() << "error:labyrinth:validation_columns_size";
                return false;
            }

            for(int c=0; c<listLine.size(); c++)
            {
                positionValue = listLine.at(c).toInt();
                if( positionValue < 0 || positionValue > 3 )
                {
                    qDebug() << "error:labyrinth:validation_elements";
                    return false;
                }
                labyrinth[countLines][c] = positionValue;
            }
        }

        if( countLines != numberLines )
        {
            qDebug() << "error:labyrinth:validation_lines_size";
            return false;
        }
        // end all_validataion
        // ---------------------------

        deleteLabyrinth();

        this->lines = numberLines;
        this->columns = numberColumns;
        this->costHorizontal = costHorizontal;
        this->costVertical = costVertical;

        allocateLabyrinth();

        for(int l=0; l < this->lines; l++) {
            for(int c=0; c < this->columns; c++) {
                this->labyrinth[l][c] = labyrinth[l][c];
            }
        }

        UI_setConfig();
    }

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

    if( UI_ReadLabyrinthFile(importLabyrinthFile) == false )
    {
        QMessageBox::critical(
            0,
            "Erro na leitura",
            "Configuração inválida no arquivo \n" + importLabyrinthFile);
    }
}

bool MainWindow::UI_WriteLabyrinthFile(QString saveLabyrinthFile)
{
    QFile labyrinthFile(saveLabyrinthFile);

    if( ! labyrinthFile.open(QIODevice::WriteOnly) )
    {
        QMessageBox::critical(
            0,
            "Error: create labyrinth",
            labyrinthFile.errorString());
        return false;
    }

    QTextStream out( &labyrinthFile );

    out << this->lines << ' '
        << this->columns << ' '
        << this->costHorizontal << ' '
        << this->costVertical << endl;

    for(int l = 0; l<this->lines; l++)
    {
        for(int c = 0; c<this->columns-1; c++)
        {
            out << this->labyrinth[l][c] << ' ';
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
    {
        saveLabyrinthFile += ".txt";
    }

    UI_WriteLabyrinthFile(saveLabyrinthFile);
}

void MainWindow::UI_changeType(int line, int column)
{
    qDebug() << line << column;

    if(ui->rb_start->isChecked() && (this->startPosition.line != line \
            || this->startPosition.column != column) )
    {
        ui->board->item(line,column)->data(0) = CELL_START;
        ui->board->item(line,column)->setBackgroundColor(Qt::green);

        ui->board->item(this->startPosition.line, this->startPosition.column)->\
                setBackgroundColor(Qt::white);

        this->startPosition.line = line;
        this->startPosition.column = column;
    }
    else if(ui->rb_end->isChecked() && (this->endPosition.line != line \
            || this->endPosition.column != column) )
    {
        ui->board->item(this->endPosition.line, this->endPosition.column)->\
                setBackgroundColor(Qt::white);

        ui->board->item(line,column)->data(0) = CELL_END;
        ui->board->item(line,column)->setBackgroundColor(Qt::blue);

        this->endPosition.line = line;
        this->endPosition.column = column;
    }
    else if(ui->rb_wall->isChecked())
    {
        ui->board->item(line,column)->data(0) = CELL_WALL;
        ui->board->item(line,column)->setBackgroundColor(Qt::black);
    }
}

void MainWindow::allocateLabyrinth()
{
    if(this->labyrinth != NULL)
    {
        deleteLabyrinth();
    }

    this->labyrinth = new int*[this->lines];

    for(int l=0; l<this->lines; l++)
    {
        this->labyrinth[l] = new int[this->columns];
    }
}

void MainWindow::deleteLabyrinth()
{
    for(int l=0; l<this->lines; l++)
    {
        delete []this->labyrinth[l];
    }

    delete []this->labyrinth;

    this->labyrinth = nullptr;
}

float MainWindow::getCostDiagonal()
{
    float cost;
    int d = 10;

    cost = sqrt( pow(this->costHorizontal,2) \
                 + pow(this->costVertical,2) );

    cost = int(cost*d);
    return cost/d;
}
