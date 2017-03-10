#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // var
    this->lines = 5;
    this->columns = 9;
    this->costHorizontal = 1;
    this->costVertical = 2;

    // for import/save labyrinth file
    this->userName = getenv("USER");
    this->userDir = "/home/" + this->userName;

    // end var
    // --------------

    // connect

    connect(ui->actionLicense, SIGNAL(triggered(bool)), this, SLOT(UI_license()));
    connect(ui->actionHelp, SIGNAL(triggered(bool)), this, SLOT(UI_help()));

    // for import/save labyrinth file
    connect(ui->actionImportLabyrinth, SIGNAL(triggered(bool)), this, SLOT(UI_ImportLabyrinth()));
    connect(ui->actionSaveLabyrinth, SIGNAL(triggered(bool)), this, SLOT(UI_SaveLabyrinth()));
    connect(ui->pb_ImportLabyrinth, SIGNAL(clicked(bool)), this, SLOT(UI_ImportLabyrinth()));
    connect(ui->pb_SaveLabyrinth, SIGNAL(clicked(bool)), this, SLOT(UI_SaveLabyrinth()));

    // end connect
    // --------------

    // UI
    ui->sb_lines->setValue( this->lines );
    ui->sb_columns->setValue( this->columns );
    ui->sb_costHorizontal->setValue( this->costHorizontal );
    ui->sb_costVertical->setValue( this->costVertical );

    // end UI
    // --------------
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UI_ImportLabyrinth()
{
    importLabyrinthFile = QFileDialog::getOpenFileName(
            this,
            tr("Import Labyrinth"),
            userDir,
            "Text File (*.txt)");

#ifdef DEBUG_IMPORT_LABYRINTH
    qDebug() << "importLabyrinthFile : " << importLabyrinthFile;
#endif

    UI_ReadLabyrinthFile(importLabyrinthFile);
}

void error_ReadLabyrinthFile(QString importLabyrinthFile)
{
    QMessageBox::critical(
        0,
        "Erro na leitura",
        "Configuração inválida no arquivo \n" + importLabyrinthFile);
}


bool validation_ReadLabyrinthFile(QFile& labyrinthFile)
{
    QString line;
    QStringList listLine;

    QTextStream in(&labyrinthFile);

    // validation_file
    line = in.readLine();
    listLine = line.split(" ");

    if( listLine.size() != 4 )
    {
#ifdef DEBUG_READ_LABYRINTH
        qDebug() << "error:labyrinth:validation_config";
#endif
        return false;
    }
    else
    {
        int lines, columns;
        int countLines;

        lines = listLine.at(0).toInt();
        columns = listLine.at(1).toInt();

        for(countLines=0; ! in.atEnd(); countLines++)
        {
            line = in.readLine();
            listLine = line.split(" ");

            // validation_columns_size
            if( listLine.size() != columns )
            {
#ifdef DEBUG_READ_LABYRINTH
                qDebug() << "error:labyrinth:validation_columns_size";
#endif
                return false;
            }

            // validation_elements
            for(int c=0; c<listLine.size(); c++)
            {
                if( listLine.at(c).toInt() < 0 || listLine.at(c).toInt() > 3 ) {
#ifdef DEBUG_READ_LABYRINTH
                    qDebug() << "error:labyrinth:validation_elements";
#endif
                    return false;
                }
            }
        }

        // validation_lines_size
        if( countLines != lines ) {
#ifdef DEBUG_READ_LABYRINTH
            qDebug() << "error:labyrinth:validation_lines_size";
#endif
            return false;
        }
    }
    // end validation_faile

    in.seek(0);

    return true;
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

    if( ! validation_ReadLabyrinthFile(labyrinthFile) ) {
        error_ReadLabyrinthFile(importLabyrinthFile);
        return false;
    }

    QTextStream in(&labyrinthFile);

    line = in.readLine();
    listLine = line.split(" ");

    this->lines = listLine.at(0).toInt();
    this->columns = listLine.at(1).toInt();
    this->costHorizontal = listLine.at(2).toInt();
    this->costVertical = listLine.at(3).toInt();

    for(int l=0; l < this->lines; l++) {
        line = in.readLine();
        listLine = line.split(" ");

        for(int c = 0; c < this->columns; c++) {
            //data[l][c] = listLine.at(c).toInt();

            /*
                TODO

                salvar matrix de pontos

            */
        }
    }

    labyrinthFile.close();

    return true;
}

bool MainWindow::UI_SaveLabyrinth()
{
    saveLabyrinthFile = QFileDialog::getSaveFileName(
            this,
            tr("Save Labyrinth"),
            userDir);

#ifdef DEBUG
    qDebug() << "saveLabyrinthFile = " << saveLabyrinthFile;
#endif

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

    /*
     *  TODO
     *
     *  Salvar matrix de pontos
    */

    labyrinthFile.close();

    QMessageBox::information(
                0,
                "Success",
                "Labyrinth saved");

    return true;
}

void MainWindow::UI_license()
{
    QString licenseText = "\
Copyright (C) 2017 - João Leite de Carvalho (carvalhojldc@gmail.com)\n\n\
This program is free software: you can redistribute it and/or modify\
it under the terms of the GNU General Public License as published by\
the Free Software Foundation, either version 3 of the License, or\
(at your option) any later version.\n\n\
This program is distributed in the hope that it will be useful,\
but WITHOUT ANY WARRANTY; without even the implied warranty of\
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\
GNU General Public License for more details.\n\n\
You should have received a copy of the GNU General Public License\
along with this program. If not, see \n<http://www.gnu.org/licenses/>.";

    QMessageBox *license = new QMessageBox(this);

    license->setText(licenseText);
    license->setWindowTitle("License");

    license->exec();
}

void MainWindow::UI_help()
{
    QString helpText = "\
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
