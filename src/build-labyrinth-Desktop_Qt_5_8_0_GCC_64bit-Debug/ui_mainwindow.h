/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLicense;
    QAction *actionHelp;
    QAction *actionImportLabyrinth;
    QAction *actionSaveLabyrinth;
    QWidget *centralWidget;
    QGroupBox *gb_labyrinthConfig;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *lb_costVertical;
    QSpinBox *sb_costHorizontal;
    QSpinBox *sb_lines;
    QPushButton *pb_SaveLabyrinth;
    QSpacerItem *verticalSpacer;
    QSpinBox *sb_columns;
    QPushButton *pb_ImportLabyrinth;
    QPushButton *pb_start;
    QLabel *lb_columns;
    QLabel *lb_lines;
    QLabel *lb_costHorizontal;
    QSpacerItem *verticalSpacer_3;
    QSpinBox *sb_costVertical;
    QMenuBar *menuBar;
    QMenu *menuAbout;
    QMenu *menuConfig;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(772, 546);
        actionLicense = new QAction(MainWindow);
        actionLicense->setObjectName(QStringLiteral("actionLicense"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionImportLabyrinth = new QAction(MainWindow);
        actionImportLabyrinth->setObjectName(QStringLiteral("actionImportLabyrinth"));
        actionSaveLabyrinth = new QAction(MainWindow);
        actionSaveLabyrinth->setObjectName(QStringLiteral("actionSaveLabyrinth"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gb_labyrinthConfig = new QGroupBox(centralWidget);
        gb_labyrinthConfig->setObjectName(QStringLiteral("gb_labyrinthConfig"));
        gb_labyrinthConfig->setGeometry(QRect(10, 10, 181, 381));
        gridLayoutWidget = new QWidget(gb_labyrinthConfig);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 160, 345));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lb_costVertical = new QLabel(gridLayoutWidget);
        lb_costVertical->setObjectName(QStringLiteral("lb_costVertical"));

        gridLayout->addWidget(lb_costVertical, 9, 0, 1, 1);

        sb_costHorizontal = new QSpinBox(gridLayoutWidget);
        sb_costHorizontal->setObjectName(QStringLiteral("sb_costHorizontal"));

        gridLayout->addWidget(sb_costHorizontal, 8, 0, 1, 1);

        sb_lines = new QSpinBox(gridLayoutWidget);
        sb_lines->setObjectName(QStringLiteral("sb_lines"));

        gridLayout->addWidget(sb_lines, 1, 0, 1, 1);

        pb_SaveLabyrinth = new QPushButton(gridLayoutWidget);
        pb_SaveLabyrinth->setObjectName(QStringLiteral("pb_SaveLabyrinth"));

        gridLayout->addWidget(pb_SaveLabyrinth, 13, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 11, 0, 1, 1);

        sb_columns = new QSpinBox(gridLayoutWidget);
        sb_columns->setObjectName(QStringLiteral("sb_columns"));

        gridLayout->addWidget(sb_columns, 3, 0, 1, 1);

        pb_ImportLabyrinth = new QPushButton(gridLayoutWidget);
        pb_ImportLabyrinth->setObjectName(QStringLiteral("pb_ImportLabyrinth"));

        gridLayout->addWidget(pb_ImportLabyrinth, 12, 0, 1, 1);

        pb_start = new QPushButton(gridLayoutWidget);
        pb_start->setObjectName(QStringLiteral("pb_start"));

        gridLayout->addWidget(pb_start, 15, 0, 1, 1);

        lb_columns = new QLabel(gridLayoutWidget);
        lb_columns->setObjectName(QStringLiteral("lb_columns"));

        gridLayout->addWidget(lb_columns, 2, 0, 1, 1);

        lb_lines = new QLabel(gridLayoutWidget);
        lb_lines->setObjectName(QStringLiteral("lb_lines"));

        gridLayout->addWidget(lb_lines, 0, 0, 1, 1);

        lb_costHorizontal = new QLabel(gridLayoutWidget);
        lb_costHorizontal->setObjectName(QStringLiteral("lb_costHorizontal"));

        gridLayout->addWidget(lb_costHorizontal, 6, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 14, 0, 1, 1);

        sb_costVertical = new QSpinBox(gridLayoutWidget);
        sb_costVertical->setObjectName(QStringLiteral("sb_costVertical"));

        gridLayout->addWidget(sb_costVertical, 10, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 772, 22));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuConfig = new QMenu(menuBar);
        menuConfig->setObjectName(QStringLiteral("menuConfig"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuConfig->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuAbout->addAction(actionHelp);
        menuAbout->addAction(actionLicense);
        menuConfig->addAction(actionImportLabyrinth);
        menuConfig->addAction(actionSaveLabyrinth);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionLicense->setText(QApplication::translate("MainWindow", "License", Q_NULLPTR));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        actionImportLabyrinth->setText(QApplication::translate("MainWindow", "Importar labirinto", Q_NULLPTR));
        actionSaveLabyrinth->setText(QApplication::translate("MainWindow", "Salvar labirinto", Q_NULLPTR));
        gb_labyrinthConfig->setTitle(QApplication::translate("MainWindow", "Configura\303\247\303\243o do labirinto", Q_NULLPTR));
        lb_costVertical->setText(QApplication::translate("MainWindow", "Custo vertical", Q_NULLPTR));
        pb_SaveLabyrinth->setText(QApplication::translate("MainWindow", "Exportar labirinto", Q_NULLPTR));
        pb_ImportLabyrinth->setText(QApplication::translate("MainWindow", "Importar labirinto", Q_NULLPTR));
        pb_start->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        lb_columns->setText(QApplication::translate("MainWindow", "Colunas", Q_NULLPTR));
        lb_lines->setText(QApplication::translate("MainWindow", "Linhas", Q_NULLPTR));
        lb_costHorizontal->setText(QApplication::translate("MainWindow", "Custo horizontal", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("MainWindow", "Sobre", Q_NULLPTR));
        menuConfig->setTitle(QApplication::translate("MainWindow", "Labirinto", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
