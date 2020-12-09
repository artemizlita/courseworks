/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_5;
    QPushButton *pushButton;
    QGroupBox *groupBox_6;
    QGroupBox *groupBox_7;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_8;
    QGroupBox *groupBox_9;
    QGroupBox *groupBox_10;
    QGroupBox *groupBox_11;
    QLabel *label_9;
    QComboBox *comboBox;
    QGroupBox *groupBox_12;
    QTextEdit *textEdit_3;
    QLabel *label_10;
    QGroupBox *groupBox_13;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(640, 1258);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 161, 51));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 70, 221, 41));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setEnabled(false);
        groupBox_3->setGeometry(QRect(10, 1110, 271, 81));
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 91, 21));
        label->setTextFormat(Qt::AutoText);
        label->setMargin(0);
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 20, 16, 20));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 20, 91, 21));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 50, 21, 21));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 50, 51, 21));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(90, 50, 51, 21));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(80, 50, 16, 21));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(140, 50, 16, 21));
        textEdit = new QTextEdit(groupBox_3);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(110, 10, 21, 21));
        textEdit_2 = new QTextEdit(groupBox_3);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(140, 20, 21, 21));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setEnabled(false);
        groupBox_4->setGeometry(QRect(10, 220, 321, 51));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setEnabled(true);
        groupBox_5->setGeometry(QRect(270, 120, 61, 41));
        pushButton = new QPushButton(groupBox_5);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(10, 15, 41, 21));
        pushButton->setCheckable(false);
        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setEnabled(false);
        groupBox_6->setGeometry(QRect(10, 170, 321, 41));
        groupBox_7 = new QGroupBox(centralWidget);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setEnabled(true);
        groupBox_7->setGeometry(QRect(10, 280, 61, 41));
        pushButton_2 = new QPushButton(groupBox_7);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setGeometry(QRect(10, 15, 41, 21));
        groupBox_8 = new QGroupBox(centralWidget);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setEnabled(false);
        groupBox_8->setGeometry(QRect(90, 280, 241, 41));
        groupBox_9 = new QGroupBox(centralWidget);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(230, 70, 51, 41));
        groupBox_10 = new QGroupBox(centralWidget);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setGeometry(QRect(280, 70, 51, 41));
        groupBox_11 = new QGroupBox(centralWidget);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        groupBox_11->setGeometry(QRect(240, 10, 91, 51));
        label_9 = new QLabel(groupBox_11);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(1, 15, 31, 21));
        comboBox = new QComboBox(groupBox_11);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 15, 56, 26));
        groupBox_12 = new QGroupBox(centralWidget);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        groupBox_12->setGeometry(QRect(170, 10, 71, 51));
        textEdit_3 = new QTextEdit(groupBox_12);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(15, 15, 50, 25));
        label_10 = new QLabel(groupBox_12);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(1, 10, 20, 30));
        groupBox_13 = new QGroupBox(centralWidget);
        groupBox_13->setObjectName(QStringLiteral("groupBox_13"));
        groupBox_13->setGeometry(QRect(10, 120, 241, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "cx", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Ax", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Restrictions", 0));
        label->setText(QApplication::translate("MainWindow", "d(k,j)=min{(x(k,j))", 0));
        label_2->setText(QApplication::translate("MainWindow", ",", 0));
        label_3->setText(QApplication::translate("MainWindow", "},j=1,...,n; p>=1", 0));
        label_4->setText(QApplication::translate("MainWindow", "(", 0));
        label_5->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_6->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_7->setText(QApplication::translate("MainWindow", ";", 0));
        label_8->setText(QApplication::translate("MainWindow", ")", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "x(0)", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "x(n)", 0));
        pushButton->setText(QApplication::translate("MainWindow", "count", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "simplex method results", 0));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "x(n)", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "count", 0));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "affing-scaling method results", 0));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "signs", 0));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "b", 0));
        groupBox_11->setTitle(QApplication::translate("MainWindow", "max(min)", 0));
        label_9->setText(QApplication::translate("MainWindow", "->", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "max", 0)
         << QApplication::translate("MainWindow", "min", 0)
        );
        groupBox_12->setTitle(QApplication::translate("MainWindow", "free c", 0));
        label_10->setText(QApplication::translate("MainWindow", "+", 0));
        groupBox_13->setTitle(QApplication::translate("MainWindow", "Condition: x >= 0", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
