#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidget>
#include <QStandardPaths>

#include <QDebug>

#define DEBUG
#define DEBUG_IMPORT_LABYRINTH
#define DEBUG_READ_LABYRINTH

#define CELL_FREE  0
#define CELL_WALL  1
#define CELL_START 2
#define CELL_END   3

struct Colors
{
    const QString start = "green";
    const QString end = "blue";
    const QString wall = "black";
    const QString free = "white";
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
    void UI_setConfig();
    void UI_setBoard();

    void UI_license();
    void UI_help();

    // read_write
    bool UI_ReadLabyrinthFile(QString);
    void UI_ImportLabyrinth();

    bool UI_WriteLabyrinthFile(QString);
    void UI_SaveLabyrinth();
    // end read_write

    void UI_changeType(int,int);

    void UI_cleanBoard();

private:
    Ui::MainWindow *ui;

    QString programTitle = "CJL Labyrinth - A*";

    void allocateLabyrinth();
    void deleteLabyrinth();

    float getCostDiagonal();

    // for import/save labyrinth file
    QString userName;
    QString userDir;
    QString importLabyrinthFile;
    QString saveLabyrinthFile;

    // labyrinth configuration
    int lines, columns, \
        costHorizontal, costVertical;
    float costDiagonal;
    int **labyrinth;

    Position startPosition, endPosition;

    Colors colors;

};

#endif // MAINWINDOW_H
