#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>

#include <QDebug>

#define DEBUG
#define DEBUG_IMPORT_LABYRINTH
#define DEBUG_READ_LABYRINTH

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
    bool UI_ReadLabyrinthFile(QString);
    void UI_ImportLabyrinth();
    bool UI_SaveLabyrinth();
    void UI_license();
    void UI_help();

private:
    Ui::MainWindow *ui;

    // for import/save labyrinth file
    QString userName;
    QString userDir;
    QString importLabyrinthFile;
    QString saveLabyrinthFile;

    // labyrinth configuration
    int lines, columns;
    int costHorizontal, costVertical;


};

#endif // MAINWINDOW_H
