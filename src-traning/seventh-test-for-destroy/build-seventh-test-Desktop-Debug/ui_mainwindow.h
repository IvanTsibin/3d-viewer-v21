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
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSlider *xRot;
    QSlider *yRot;
    QSlider *zRot;
    QSlider *ColorChange;
    QOpenGLWidget *openGLWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        xRot = new QSlider(centralwidget);
        xRot->setObjectName(QString::fromUtf8("xRot"));
        xRot->setGeometry(QRect(650, 10, 16, 541));
        xRot->setOrientation(Qt::Vertical);
        yRot = new QSlider(centralwidget);
        yRot->setObjectName(QString::fromUtf8("yRot"));
        yRot->setGeometry(QRect(690, 10, 16, 541));
        yRot->setOrientation(Qt::Vertical);
        zRot = new QSlider(centralwidget);
        zRot->setObjectName(QString::fromUtf8("zRot"));
        zRot->setGeometry(QRect(730, 10, 16, 541));
        zRot->setOrientation(Qt::Vertical);
        ColorChange = new QSlider(centralwidget);
        ColorChange->setObjectName(QString::fromUtf8("ColorChange"));
        ColorChange->setGeometry(QRect(760, 10, 16, 541));
        ColorChange->setOrientation(Qt::Vertical);
        openGLWidget = new QOpenGLWidget(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(10, 10, 621, 541));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
