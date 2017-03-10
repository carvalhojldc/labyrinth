#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // var

    // for import/save labyrinth file
    userName = getenv("USER");
    userDir = "/home/" + userName;

    // end var
    // --------------

    // connect

    connect(ui->actionLicense, SIGNAL(triggered(bool)), this, SLOT(UI_license()));

    // for import/save labyrinth file
    connect(ui->actionImportLabyrinth, SIGNAL(triggered(bool)), this, SLOT(UI_ImportLabyrinth()));
    connect(ui->actionSaveLabyrinth, SIGNAL(triggered(bool)), this, SLOT(UI_SaveLabyrinth()));
    connect(ui->pb_ImportLabyrinth, SIGNAL(clicked(bool)), this, SLOT(UI_ImportLabyrinth()));
    connect(ui->pb_SaveLabyrinth, SIGNAL(clicked(bool)), this, SLOT(UI_SaveLabyrinth()));

    // end connect
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

#ifdef DEBUG
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

    line = in.readLine();
    listLine = line.split(" ");

    if( listLine.size() != 4 )
    {
        qDebug() << "validation_config";
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
                qDebug() << "validation_columns_size";
                return false;
            }

            // validation_elements
            for(int c=0; c<listLine.size(); c++)
            {
                if( listLine.at(c).toInt() < 0 || listLine.at(c).toInt() > 3 ) {
                    qDebug() << "validation_elements";
                    return false;
                }
            }
        }

        // validation_lines_size
        if( countLines != lines ) {
            qDebug() << "validation_lines_size";
            return false;
        }
    }
}

bool MainWindow::UI_ReadLabyrinthFile(QString importLabyrinthFile)
{
    QString line;
    QStringList listLine;
    QFile labyrinthFile(importLabyrinthFile);

    if( ! labyrinthFile.open(QIODevice::ReadOnly) )
    {
        QMessageBox::critical(0,
            "Error: opening labyrinth",
            labyrinthFile.errorString());
        return false;
    }
/*
    if( validation_ReadLabyrinthFile(labyrinthFile) == false) {
        error_ReadLabyrinthFile(importLabyrinthFile);
        return false;
    }
*/
    QTextStream in(&labyrinthFile);

    line = in.readLine();
    listLine = line.split(" ");

    this->lines = listLine.at(0).toInt();
    this->columns = listLine.at(1).toInt();
    // peso 1 = listLine.at(2).toInt();
    // peso 2 = listLine.at(3).toInt();

    for(int l=0; l < this->lines; l++) {
        line = in.readLine();
        listLine = line.split(" ");

        for(int c = 0; c < this->columns; c++) {
            //data[l][c] = listLine.at(c).toInt();
            qDebug() << listLine.at(c);
        }
    }

    qDebug() << "sucesso";
    labyrinthFile.close();
    return true;
}

void MainWindow::UI_SaveLabyrinth()
{
    saveLabyrinthFile = QFileDialog::getSaveFileName(
            this,
            tr("Save Labyrinth"),
            userDir);

#ifdef DEBUG
    qDebug() << "saveLabyrinthFile = " << saveLabyrinthFile;
#endif

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

    license->exec();
}
