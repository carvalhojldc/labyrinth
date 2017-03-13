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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
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
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QLabel *lb_costHorizontal;
    QLabel *lb_costVertical;
    QLabel *lb_costDiagonal;
    QSpinBox *sb_columns;
    QLabel *lb_columns;
    QSpinBox *sb_lines;
    QLabel *lb_lines;
    QDoubleSpinBox *sb_costDiagonal;
    QDoubleSpinBox *sb_costVertical;
    QDoubleSpinBox *sb_costHorizontal;
    QPushButton *pushButton;
    QGroupBox *gb_drawing;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *rb_start;
    QRadioButton *rb_end;
    QRadioButton *rb_wall;
    QRadioButton *rb_clearCell;
    QPushButton *pb_clearBoard;
    QPushButton *pb_start;
    QTableWidget *board;
    QMenuBar *menuBar;
    QMenu *menuAbout;
    QMenu *menuConfig;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(885, 753);
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
        centralWidget->setEnabled(true);
        gb_labyrinthConfig = new QGroupBox(centralWidget);
        gb_labyrinthConfig->setObjectName(QStringLiteral("gb_labyrinthConfig"));
        gb_labyrinthConfig->setGeometry(QRect(10, 14, 241, 551));
        verticalLayout = new QVBoxLayout(gb_labyrinthConfig);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_2 = new QGroupBox(gb_labyrinthConfig);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        lb_costHorizontal = new QLabel(groupBox_2);
        lb_costHorizontal->setObjectName(QStringLiteral("lb_costHorizontal"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lb_costHorizontal);

        lb_costVertical = new QLabel(groupBox_2);
        lb_costVertical->setObjectName(QStringLiteral("lb_costVertical"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lb_costVertical);

        lb_costDiagonal = new QLabel(groupBox_2);
        lb_costDiagonal->setObjectName(QStringLiteral("lb_costDiagonal"));

        formLayout->setWidget(4, QFormLayout::LabelRole, lb_costDiagonal);

        sb_columns = new QSpinBox(groupBox_2);
        sb_columns->setObjectName(QStringLiteral("sb_columns"));

        formLayout->setWidget(1, QFormLayout::FieldRole, sb_columns);

        lb_columns = new QLabel(groupBox_2);
        lb_columns->setObjectName(QStringLiteral("lb_columns"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lb_columns);

        sb_lines = new QSpinBox(groupBox_2);
        sb_lines->setObjectName(QStringLiteral("sb_lines"));

        formLayout->setWidget(0, QFormLayout::FieldRole, sb_lines);

        lb_lines = new QLabel(groupBox_2);
        lb_lines->setObjectName(QStringLiteral("lb_lines"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lb_lines);

        sb_costDiagonal = new QDoubleSpinBox(groupBox_2);
        sb_costDiagonal->setObjectName(QStringLiteral("sb_costDiagonal"));
        sb_costDiagonal->setSingleStep(0.5);

        formLayout->setWidget(4, QFormLayout::FieldRole, sb_costDiagonal);

        sb_costVertical = new QDoubleSpinBox(groupBox_2);
        sb_costVertical->setObjectName(QStringLiteral("sb_costVertical"));

        formLayout->setWidget(3, QFormLayout::FieldRole, sb_costVertical);

        sb_costHorizontal = new QDoubleSpinBox(groupBox_2);
        sb_costHorizontal->setObjectName(QStringLiteral("sb_costHorizontal"));

        formLayout->setWidget(2, QFormLayout::FieldRole, sb_costHorizontal);


        verticalLayout_3->addLayout(formLayout);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_3->addWidget(pushButton);


        verticalLayout->addWidget(groupBox_2);

        gb_drawing = new QGroupBox(gb_labyrinthConfig);
        gb_drawing->setObjectName(QStringLiteral("gb_drawing"));
        gb_drawing->setEnabled(true);
        verticalLayout_2 = new QVBoxLayout(gb_drawing);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        rb_start = new QRadioButton(gb_drawing);
        rb_start->setObjectName(QStringLiteral("rb_start"));

        verticalLayout_2->addWidget(rb_start);

        rb_end = new QRadioButton(gb_drawing);
        rb_end->setObjectName(QStringLiteral("rb_end"));

        verticalLayout_2->addWidget(rb_end);

        rb_wall = new QRadioButton(gb_drawing);
        rb_wall->setObjectName(QStringLiteral("rb_wall"));

        verticalLayout_2->addWidget(rb_wall);

        rb_clearCell = new QRadioButton(gb_drawing);
        rb_clearCell->setObjectName(QStringLiteral("rb_clearCell"));

        verticalLayout_2->addWidget(rb_clearCell);

        pb_clearBoard = new QPushButton(gb_drawing);
        pb_clearBoard->setObjectName(QStringLiteral("pb_clearBoard"));

        verticalLayout_2->addWidget(pb_clearBoard);


        verticalLayout->addWidget(gb_drawing);

        pb_start = new QPushButton(gb_labyrinthConfig);
        pb_start->setObjectName(QStringLiteral("pb_start"));
        pb_start->setEnabled(true);

        verticalLayout->addWidget(pb_start);

        board = new QTableWidget(centralWidget);
        board->setObjectName(QStringLiteral("board"));
        board->setGeometry(QRect(260, 30, 581, 581));
        board->setSelectionMode(QAbstractItemView::NoSelection);
        board->setShowGrid(true);
        board->setGridStyle(Qt::DashDotDotLine);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 885, 22));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuConfig = new QMenu(menuBar);
        menuConfig->setObjectName(QStringLiteral("menuConfig"));
        MainWindow->setMenuBar(menuBar);
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CJL Labyrinth - A*", Q_NULLPTR));
        actionLicense->setText(QApplication::translate("MainWindow", "License", Q_NULLPTR));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        actionImportLabyrinth->setText(QApplication::translate("MainWindow", "Abrir labirinto", Q_NULLPTR));
        actionSaveLabyrinth->setText(QApplication::translate("MainWindow", "Salvar labirinto", Q_NULLPTR));
        gb_labyrinthConfig->setTitle(QApplication::translate("MainWindow", "Configura\303\247\303\243o do labirinto", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Dimens\303\243o e custo", Q_NULLPTR));
        lb_costHorizontal->setText(QApplication::translate("MainWindow", "Custo horizontal", Q_NULLPTR));
        lb_costVertical->setText(QApplication::translate("MainWindow", "Custo vertical", Q_NULLPTR));
        lb_costDiagonal->setText(QApplication::translate("MainWindow", "Custo diagonal", Q_NULLPTR));
        lb_columns->setText(QApplication::translate("MainWindow", "Colunas", Q_NULLPTR));
        lb_lines->setText(QApplication::translate("MainWindow", "Linhas", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Gerar ", Q_NULLPTR));
        gb_drawing->setTitle(QApplication::translate("MainWindow", "Desenho do labirinto", Q_NULLPTR));
        rb_start->setText(QApplication::translate("MainWindow", "Partida", Q_NULLPTR));
        rb_end->setText(QApplication::translate("MainWindow", "Chegada", Q_NULLPTR));
        rb_wall->setText(QApplication::translate("MainWindow", "Obst\303\241culo", Q_NULLPTR));
        rb_clearCell->setText(QApplication::translate("MainWindow", "Apagar posi\303\247\303\243o", Q_NULLPTR));
        pb_clearBoard->setText(QApplication::translate("MainWindow", "Apagar labirinto", Q_NULLPTR));
        pb_start->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("MainWindow", "Sobre", Q_NULLPTR));
        menuConfig->setTitle(QApplication::translate("MainWindow", "Labirinto", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
