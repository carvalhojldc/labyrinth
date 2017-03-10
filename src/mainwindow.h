#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>

#include <QDebug>

#define DEBUG

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
    void UI_ImportLabyrinth();
    void UI_SaveLabyrinth();
    bool UI_ReadLabyrinthFile(QString importLabyrinthFile);

private:
    Ui::MainWindow *ui;

    // for import/save labyrinth file
    QString userName;
    QString userDir;
    QString importLabyrinthFile;
    QString saveLabyrinthFile;

    // labyrinth confi
    int lines, columns;


};

#endif // MAINWINDOW_H
