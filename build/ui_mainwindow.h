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
    QPushButton *pb_ImportLabyrinth;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *lb_lines;
    QSpinBox *sb_lines;
    QLabel *lb_columns;
    QSpinBox *sb_columns;
    QLabel *lb_costHorizontal;
    QSpinBox *sb_costHorizontal;
    QLabel *lb_costVertical;
    QSpinBox *sb_costVertical;
    QPushButton *pushButton;
    QPushButton *pb_drawing;
    QGroupBox *gb_drawing;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *rb_start;
    QRadioButton *rb_end;
    QRadioButton *rb_wall;
    QRadioButton *radioButton;
    QPushButton *pushButton_2;
    QPushButton *pb_SaveLabyrinth;
    QSpacerItem *verticalSpacer;
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
        MainWindow->resize(789, 653);
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
        gb_labyrinthConfig->setGeometry(QRect(10, 10, 184, 591));
        verticalLayout = new QVBoxLayout(gb_labyrinthConfig);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pb_ImportLabyrinth = new QPushButton(gb_labyrinthConfig);
        pb_ImportLabyrinth->setObjectName(QStringLiteral("pb_ImportLabyrinth"));

        verticalLayout->addWidget(pb_ImportLabyrinth);

        groupBox_2 = new QGroupBox(gb_labyrinthConfig);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lb_lines = new QLabel(groupBox_2);
        lb_lines->setObjectName(QStringLiteral("lb_lines"));

        verticalLayout_3->addWidget(lb_lines);

        sb_lines = new QSpinBox(groupBox_2);
        sb_lines->setObjectName(QStringLiteral("sb_lines"));

        verticalLayout_3->addWidget(sb_lines);

        lb_columns = new QLabel(groupBox_2);
        lb_columns->setObjectName(QStringLiteral("lb_columns"));

        verticalLayout_3->addWidget(lb_columns);

        sb_columns = new QSpinBox(groupBox_2);
        sb_columns->setObjectName(QStringLiteral("sb_columns"));

        verticalLayout_3->addWidget(sb_columns);

        lb_costHorizontal = new QLabel(groupBox_2);
        lb_costHorizontal->setObjectName(QStringLiteral("lb_costHorizontal"));

        verticalLayout_3->addWidget(lb_costHorizontal);

        sb_costHorizontal = new QSpinBox(groupBox_2);
        sb_costHorizontal->setObjectName(QStringLiteral("sb_costHorizontal"));

        verticalLayout_3->addWidget(sb_costHorizontal);

        lb_costVertical = new QLabel(groupBox_2);
        lb_costVertical->setObjectName(QStringLiteral("lb_costVertical"));

        verticalLayout_3->addWidget(lb_costVertical);

        sb_costVertical = new QSpinBox(groupBox_2);
        sb_costVertical->setObjectName(QStringLiteral("sb_costVertical"));

        verticalLayout_3->addWidget(sb_costVertical);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        sb_costVertical->raise();
        lb_costVertical->raise();
        sb_costHorizontal->raise();
        lb_costHorizontal->raise();
        sb_columns->raise();
        lb_columns->raise();
        sb_lines->raise();
        lb_lines->raise();
        pushButton->raise();

        verticalLayout->addWidget(groupBox_2);

        pb_drawing = new QPushButton(gb_labyrinthConfig);
        pb_drawing->setObjectName(QStringLiteral("pb_drawing"));

        verticalLayout->addWidget(pb_drawing);

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

        radioButton = new QRadioButton(gb_drawing);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout_2->addWidget(radioButton);

        pushButton_2 = new QPushButton(gb_drawing);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);


        verticalLayout->addWidget(gb_drawing);

        pb_SaveLabyrinth = new QPushButton(gb_labyrinthConfig);
        pb_SaveLabyrinth->setObjectName(QStringLiteral("pb_SaveLabyrinth"));

        verticalLayout->addWidget(pb_SaveLabyrinth);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pb_start = new QPushButton(gb_labyrinthConfig);
        pb_start->setObjectName(QStringLiteral("pb_start"));
        pb_start->setEnabled(true);

        verticalLayout->addWidget(pb_start);

        board = new QTableWidget(centralWidget);
        board->setObjectName(QStringLiteral("board"));
        board->setGeometry(QRect(200, 30, 581, 581));
        board->setSelectionMode(QAbstractItemView::NoSelection);
        board->setShowGrid(false);
        board->setGridStyle(Qt::DashLine);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 789, 20));
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
        pb_ImportLabyrinth->setText(QApplication::translate("MainWindow", "Importar labirinto", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Dimens\303\265es e custos", Q_NULLPTR));
        lb_lines->setText(QApplication::translate("MainWindow", "Linhas", Q_NULLPTR));
        lb_columns->setText(QApplication::translate("MainWindow", "Colunas", Q_NULLPTR));
        lb_costHorizontal->setText(QApplication::translate("MainWindow", "Custo horizontal", Q_NULLPTR));
        lb_costVertical->setText(QApplication::translate("MainWindow", "Custo vertical", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Gerar ", Q_NULLPTR));
        pb_drawing->setText(QApplication::translate("MainWindow", "Modo desenho", Q_NULLPTR));
        gb_drawing->setTitle(QApplication::translate("MainWindow", "Desenho", Q_NULLPTR));
        rb_start->setText(QApplication::translate("MainWindow", "Partida", Q_NULLPTR));
        rb_end->setText(QApplication::translate("MainWindow", "Chegada", Q_NULLPTR));
        rb_wall->setText(QApplication::translate("MainWindow", "Barreira", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "Limpar posi\303\247\303\243o", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Lipar tudo", Q_NULLPTR));
        pb_SaveLabyrinth->setText(QApplication::translate("MainWindow", "Exportar labirinto", Q_NULLPTR));
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
