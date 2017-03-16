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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
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
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_5;
    QFrame *frame_2;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *lb_lines;
    QSpinBox *sb_lines;
    QLabel *lb_columns;
    QSpinBox *sb_columns;
    QLabel *lb_costHorizontal;
    QDoubleSpinBox *sb_costHorizontal;
    QLabel *lb_costVertical;
    QDoubleSpinBox *sb_costVertical;
    QLabel *lb_costDiagonal;
    QDoubleSpinBox *sb_costDiagonal;
    QPushButton *pb_newBoard;
    QCheckBox *cb_costDiagonal;
    QGroupBox *gb_drawing;
    QGridLayout *gridLayout;
    QRadioButton *rb_start;
    QRadioButton *rb_end;
    QRadioButton *rb_wall;
    QRadioButton *rb_clearCell;
    QPushButton *pb_clearBoard;
    QPushButton *pb_start;
    QSpacerItem *verticalSpacer;
    QTableWidget *board;
    QMenuBar *menuBar;
    QMenu *menuAbout;
    QMenu *menuConfig;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(915, 664);
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
        gridLayout_6 = new QGridLayout(centralWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(287, 457));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox_2 = new QGroupBox(frame_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMinimumSize(QSize(267, 258));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lb_lines = new QLabel(groupBox_2);
        lb_lines->setObjectName(QStringLiteral("lb_lines"));

        gridLayout_3->addWidget(lb_lines, 0, 0, 1, 1);

        sb_lines = new QSpinBox(groupBox_2);
        sb_lines->setObjectName(QStringLiteral("sb_lines"));

        gridLayout_3->addWidget(sb_lines, 0, 1, 1, 1);

        lb_columns = new QLabel(groupBox_2);
        lb_columns->setObjectName(QStringLiteral("lb_columns"));

        gridLayout_3->addWidget(lb_columns, 1, 0, 1, 1);

        sb_columns = new QSpinBox(groupBox_2);
        sb_columns->setObjectName(QStringLiteral("sb_columns"));

        gridLayout_3->addWidget(sb_columns, 1, 1, 1, 1);

        lb_costHorizontal = new QLabel(groupBox_2);
        lb_costHorizontal->setObjectName(QStringLiteral("lb_costHorizontal"));

        gridLayout_3->addWidget(lb_costHorizontal, 2, 0, 1, 1);

        sb_costHorizontal = new QDoubleSpinBox(groupBox_2);
        sb_costHorizontal->setObjectName(QStringLiteral("sb_costHorizontal"));

        gridLayout_3->addWidget(sb_costHorizontal, 2, 1, 1, 1);

        lb_costVertical = new QLabel(groupBox_2);
        lb_costVertical->setObjectName(QStringLiteral("lb_costVertical"));

        gridLayout_3->addWidget(lb_costVertical, 3, 0, 1, 1);

        sb_costVertical = new QDoubleSpinBox(groupBox_2);
        sb_costVertical->setObjectName(QStringLiteral("sb_costVertical"));

        gridLayout_3->addWidget(sb_costVertical, 3, 1, 1, 1);

        lb_costDiagonal = new QLabel(groupBox_2);
        lb_costDiagonal->setObjectName(QStringLiteral("lb_costDiagonal"));

        gridLayout_3->addWidget(lb_costDiagonal, 5, 0, 1, 1);

        sb_costDiagonal = new QDoubleSpinBox(groupBox_2);
        sb_costDiagonal->setObjectName(QStringLiteral("sb_costDiagonal"));
        sb_costDiagonal->setSingleStep(0.5);

        gridLayout_3->addWidget(sb_costDiagonal, 5, 1, 1, 1);

        pb_newBoard = new QPushButton(groupBox_2);
        pb_newBoard->setObjectName(QStringLiteral("pb_newBoard"));

        gridLayout_3->addWidget(pb_newBoard, 6, 0, 1, 2);

        cb_costDiagonal = new QCheckBox(groupBox_2);
        cb_costDiagonal->setObjectName(QStringLiteral("cb_costDiagonal"));

        gridLayout_3->addWidget(cb_costDiagonal, 4, 0, 1, 2);


        gridLayout_4->addWidget(groupBox_2, 0, 0, 1, 1);

        gb_drawing = new QGroupBox(frame_2);
        gb_drawing->setObjectName(QStringLiteral("gb_drawing"));
        gb_drawing->setEnabled(true);
        sizePolicy.setHeightForWidth(gb_drawing->sizePolicy().hasHeightForWidth());
        gb_drawing->setSizePolicy(sizePolicy);
        gb_drawing->setMinimumSize(QSize(267, 127));
        gridLayout = new QGridLayout(gb_drawing);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        rb_start = new QRadioButton(gb_drawing);
        rb_start->setObjectName(QStringLiteral("rb_start"));

        gridLayout->addWidget(rb_start, 0, 0, 1, 1);

        rb_end = new QRadioButton(gb_drawing);
        rb_end->setObjectName(QStringLiteral("rb_end"));

        gridLayout->addWidget(rb_end, 0, 1, 1, 1);

        rb_wall = new QRadioButton(gb_drawing);
        rb_wall->setObjectName(QStringLiteral("rb_wall"));

        gridLayout->addWidget(rb_wall, 1, 0, 1, 1);

        rb_clearCell = new QRadioButton(gb_drawing);
        rb_clearCell->setObjectName(QStringLiteral("rb_clearCell"));

        gridLayout->addWidget(rb_clearCell, 1, 1, 1, 1);

        pb_clearBoard = new QPushButton(gb_drawing);
        pb_clearBoard->setObjectName(QStringLiteral("pb_clearBoard"));

        gridLayout->addWidget(pb_clearBoard, 2, 0, 1, 2);


        gridLayout_4->addWidget(gb_drawing, 1, 0, 1, 1);

        pb_start = new QPushButton(frame_2);
        pb_start->setObjectName(QStringLiteral("pb_start"));
        pb_start->setEnabled(true);
        sizePolicy1.setHeightForWidth(pb_start->sizePolicy().hasHeightForWidth());
        pb_start->setSizePolicy(sizePolicy1);
        pb_start->setMinimumSize(QSize(267, 40));

        gridLayout_4->addWidget(pb_start, 2, 0, 1, 1);

        gb_drawing->raise();
        pb_start->raise();
        groupBox_2->raise();

        gridLayout_5->addWidget(frame_2, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_5, 0, 0, 1, 1);

        board = new QTableWidget(centralWidget);
        board->setObjectName(QStringLiteral("board"));
        sizePolicy1.setHeightForWidth(board->sizePolicy().hasHeightForWidth());
        board->setSizePolicy(sizePolicy1);
        board->setMinimumSize(QSize(600, 600));
        board->setEditTriggers(QAbstractItemView::NoEditTriggers);
        board->setSelectionMode(QAbstractItemView::NoSelection);
        board->horizontalHeader()->setVisible(false);
        board->horizontalHeader()->setDefaultSectionSize(100);
        board->horizontalHeader()->setMinimumSectionSize(20);
        board->verticalHeader()->setVisible(false);
        board->verticalHeader()->setMinimumSectionSize(20);

        gridLayout_2->addWidget(board, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 915, 20));
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
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Dimens\303\243o e custo", Q_NULLPTR));
        lb_lines->setText(QApplication::translate("MainWindow", "Linhas", Q_NULLPTR));
        lb_columns->setText(QApplication::translate("MainWindow", "Colunas", Q_NULLPTR));
        lb_costHorizontal->setText(QApplication::translate("MainWindow", "Custo horizontal", Q_NULLPTR));
        lb_costVertical->setText(QApplication::translate("MainWindow", "Custo vertical", Q_NULLPTR));
        lb_costDiagonal->setText(QApplication::translate("MainWindow", "Custo diagonal", Q_NULLPTR));
        pb_newBoard->setText(QApplication::translate("MainWindow", " Atualizar", Q_NULLPTR));
        cb_costDiagonal->setText(QApplication::translate("MainWindow", "Custo diagonal autom\303\241tico", Q_NULLPTR));
        gb_drawing->setTitle(QApplication::translate("MainWindow", "Desenho do labirinto", Q_NULLPTR));
        rb_start->setText(QApplication::translate("MainWindow", "Partida", Q_NULLPTR));
        rb_end->setText(QApplication::translate("MainWindow", "Chegada", Q_NULLPTR));
        rb_wall->setText(QApplication::translate("MainWindow", "Obst\303\241culo", Q_NULLPTR));
        rb_clearCell->setText(QApplication::translate("MainWindow", "Apagar posi\303\247\303\243o", Q_NULLPTR));
        pb_clearBoard->setText(QApplication::translate("MainWindow", " Apagar labirinto", Q_NULLPTR));
        pb_start->setText(QApplication::translate("MainWindow", "Resolver", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("MainWindow", "Sobre", Q_NULLPTR));
        menuConfig->setTitle(QApplication::translate("MainWindow", "Labirinto", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
