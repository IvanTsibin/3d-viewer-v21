/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSlider *xSlider;
    QSlider *ySlider;
    QSlider *zSlider;
    QSlider *colorSlider;
    QSlider *xMoveSlider;
    QSlider *yMoveSlider;
    QSlider *zMoveSlider;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menuBar;
    QMenu *menuTest_First;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1161, 799);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 821, 721));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(840, 50, 171, 591));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        xSlider = new QSlider(layoutWidget);
        xSlider->setObjectName(QString::fromUtf8("xSlider"));
        xSlider->setMinimum(0);
        xSlider->setMaximum(2880);
        xSlider->setSingleStep(16);
        xSlider->setPageStep(320);
        xSlider->setSliderPosition(0);
        xSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(xSlider);

        ySlider = new QSlider(layoutWidget);
        ySlider->setObjectName(QString::fromUtf8("ySlider"));
        ySlider->setMinimum(0);
        ySlider->setMaximum(2880);
        ySlider->setSliderPosition(0);
        ySlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(ySlider);

        zSlider = new QSlider(layoutWidget);
        zSlider->setObjectName(QString::fromUtf8("zSlider"));
        zSlider->setMinimum(0);
        zSlider->setMaximum(2880);
        zSlider->setSliderPosition(0);
        zSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(zSlider);


        horizontalLayout_2->addLayout(horizontalLayout);

        colorSlider = new QSlider(layoutWidget);
        colorSlider->setObjectName(QString::fromUtf8("colorSlider"));
        colorSlider->setValue(99);
        colorSlider->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(colorSlider);

        xMoveSlider = new QSlider(centralWidget);
        xMoveSlider->setObjectName(QString::fromUtf8("xMoveSlider"));
        xMoveSlider->setGeometry(QRect(1030, 50, 16, 591));
        xMoveSlider->setMinimum(-50);
        xMoveSlider->setMaximum(50);
        xMoveSlider->setOrientation(Qt::Vertical);
        yMoveSlider = new QSlider(centralWidget);
        yMoveSlider->setObjectName(QString::fromUtf8("yMoveSlider"));
        yMoveSlider->setGeometry(QRect(1070, 50, 16, 591));
        yMoveSlider->setMinimum(-50);
        yMoveSlider->setMaximum(50);
        yMoveSlider->setOrientation(Qt::Vertical);
        zMoveSlider = new QSlider(centralWidget);
        zMoveSlider->setObjectName(QString::fromUtf8("zMoveSlider"));
        zMoveSlider->setGeometry(QRect(1120, 50, 16, 591));
        zMoveSlider->setMinimum(-50);
        zMoveSlider->setMaximum(50);
        zMoveSlider->setOrientation(Qt::Vertical);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(840, 30, 41, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(890, 30, 41, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(940, 30, 41, 17));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1010, 30, 51, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1050, 10, 51, 17));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1100, 30, 51, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1161, 22));
        menuTest_First = new QMenu(menuBar);
        menuTest_First->setObjectName(QString::fromUtf8("menuTest_First"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuTest_First->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "xRot", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "yRot", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "zRot", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "xMove", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "yMove", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "zMove", nullptr));
        menuTest_First->setTitle(QApplication::translate("MainWindow", "Test-First", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
