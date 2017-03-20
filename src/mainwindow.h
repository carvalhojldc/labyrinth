#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidget>
#include <QStandardPaths>
#include <QtMath>

#include "labyrinth.h"

#include <QDebug>

struct Colors
{
    const QString start = "green";
    const QString end   = "blue";
    const QString wall  = "black";
    const QString free  = "white";
};

struct Position
{
    int line;
    int column;
    bool active;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void UI_license();
    void UI_help();

    void UI_updateUI();
    void UI_setConfig();
    void UI_setBoard();

    void UI_changeButtonUpdate();

    void UI_clearBoard();
    void UI_setCellValue(int line, int column, int value);
    void UI_createCellsBoard(int startLine, int endLine, int startColumn, int endColumn);

    void UI_resizeBoard(int lines, int columns);
    void UI_newBoard();

    void disableStartCell(int line, int column);
    void disableEndCell(int line, int column);
    void UI_changeCell(int,int);

    // read_write
    bool UI_ReadLabyrinthFile(QString);
    void UI_ImportLabyrinth();

    bool UI_WriteLabyrinthFile(QString);
    void UI_SaveLabyrinth();
    // end read_write

    void UI_newCostDiagonal();

    void UI_EditCostDiagonal(bool value);

    void start();

private:
    float getDiagonal(float a, float b);

    float euclideanDistance(int line, int column);
    void a_star();

private:
    Ui::MainWindow *ui;

    //File *acessFile;

    QString program = "CJL Labyrinth - A* v0.2.1 ";

    // for import/save labyrinth file
    QString userName;
    QString userDir;
    QString importLabyrinthFile;
    QString saveLabyrinthFile;

    Position startPosition, endPosition;

    Colors colors;

    Labyrinth* labyrinth;
};

#endif // MAINWINDOW_H
