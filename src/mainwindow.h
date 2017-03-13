#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidget>

#include <QDebug>

#define DEBUG
#define DEBUG_IMPORT_LABYRINTH
#define DEBUG_READ_LABYRINTH

#define CELL_FREE  0
#define CELL_WALL  1
#define CELL_START 2
#define CELL_END   3

struct Position {
    int line;
    int column;
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
    bool UI_ReadLabyrinthFile(QString);
    bool UI_ImportLabyrinth();
    bool UI_WriteLabyrinthFile(QString);
    bool UI_SaveLabyrinth();
    void UI_license();
    void UI_help();

    void UI_Drawing();

    void UI_changeType(int,int);

private:
    Ui::MainWindow *ui;

    void allocateLabyrinth();
    void deleteLabyrinth();

    // for import/save labyrinth file
    QString userName;
    QString userDir;
    QString importLabyrinthFile;
    QString saveLabyrinthFile;

    // labyrinth configuration
    int lines, columns, \
        costHorizontal, costVertical;
    int **labyrinth;

    Position startPosition, endPosition;

    bool drawingMode;

    QString programTitle = "CJL Labyrinth - A*";

};

#endif // MAINWINDOW_H
