/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mainwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    MainWidget *openGLWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *BackgroundColor;
    QLabel *label_2;
    QComboBox *BackgroundColor_3;
    QLabel *label_3;
    QComboBox *BackgroundColor_4;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QComboBox *ProectionType;
    QLabel *label_5;
    QComboBox *EdgeType;
    QLabel *label_6;
    QComboBox *VerticeType;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QDoubleSpinBox *VerticeSize;
    QLabel *label_8;
    QDoubleSpinBox *EdgeSize;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_9;
    QScrollBar *XMovement;
    QLabel *label_10;
    QScrollBar *YMovement;
    QLabel *label_11;
    QScrollBar *ZMovement;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_12;
    QScrollBar *XRotation;
    QLabel *yrot;
    QScrollBar *YRotation;
    QLabel *label_14;
    QScrollBar *ZRotation;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *CleanPos;
    QPushButton *CleanColor;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_15;
    QLabel *label_18;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *VerticeNum;
    QLabel *EdgeNum;
    QPushButton *Gif;
    QPushButton *Screenshot;
    QLabel *pathToFile;
    QPushButton *ChooseFile;
    QPushButton *Screenshot_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1288, 763);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 255, 184);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        openGLWidget = new MainWidget(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(50, 20, 691, 651));
        openGLWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(1020, 20, 231, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(label);

        BackgroundColor = new QComboBox(verticalLayoutWidget);
        BackgroundColor->addItem(QString());
        BackgroundColor->addItem(QString());
        BackgroundColor->addItem(QString());
        BackgroundColor->addItem(QString());
        BackgroundColor->addItem(QString());
        BackgroundColor->addItem(QString());
        BackgroundColor->setObjectName(QString::fromUtf8("BackgroundColor"));
        BackgroundColor->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(BackgroundColor);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_2);

        BackgroundColor_3 = new QComboBox(verticalLayoutWidget);
        BackgroundColor_3->addItem(QString());
        BackgroundColor_3->addItem(QString());
        BackgroundColor_3->addItem(QString());
        BackgroundColor_3->addItem(QString());
        BackgroundColor_3->addItem(QString());
        BackgroundColor_3->addItem(QString());
        BackgroundColor_3->setObjectName(QString::fromUtf8("BackgroundColor_3"));
        BackgroundColor_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(BackgroundColor_3);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_3);

        BackgroundColor_4 = new QComboBox(verticalLayoutWidget);
        BackgroundColor_4->addItem(QString());
        BackgroundColor_4->addItem(QString());
        BackgroundColor_4->addItem(QString());
        BackgroundColor_4->addItem(QString());
        BackgroundColor_4->addItem(QString());
        BackgroundColor_4->addItem(QString());
        BackgroundColor_4->setObjectName(QString::fromUtf8("BackgroundColor_4"));
        BackgroundColor_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(BackgroundColor_4);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(1020, 260, 231, 201));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(label_4);

        ProectionType = new QComboBox(verticalLayoutWidget_2);
        ProectionType->addItem(QString());
        ProectionType->setObjectName(QString::fromUtf8("ProectionType"));
        ProectionType->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(ProectionType);

        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(label_5);

        EdgeType = new QComboBox(verticalLayoutWidget_2);
        EdgeType->addItem(QString());
        EdgeType->addItem(QString());
        EdgeType->setObjectName(QString::fromUtf8("EdgeType"));
        EdgeType->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(EdgeType);

        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(label_6);

        VerticeType = new QComboBox(verticalLayoutWidget_2);
        VerticeType->addItem(QString());
        VerticeType->addItem(QString());
        VerticeType->setObjectName(QString::fromUtf8("VerticeType"));
        VerticeType->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(VerticeType);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(1020, 490, 231, 121));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_3->addWidget(label_7);

        VerticeSize = new QDoubleSpinBox(verticalLayoutWidget_3);
        VerticeSize->setObjectName(QString::fromUtf8("VerticeSize"));
        VerticeSize->setMinimumSize(QSize(229, 20));
        VerticeSize->setAutoFillBackground(false);
        VerticeSize->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        VerticeSize->setWrapping(false);
        VerticeSize->setFrame(true);
        VerticeSize->setMinimum(1.000000000000000);
        VerticeSize->setValue(1.000000000000000);

        verticalLayout_3->addWidget(VerticeSize);

        label_8 = new QLabel(verticalLayoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_3->addWidget(label_8);

        EdgeSize = new QDoubleSpinBox(verticalLayoutWidget_3);
        EdgeSize->setObjectName(QString::fromUtf8("EdgeSize"));
        EdgeSize->setMinimumSize(QSize(229, 20));
        EdgeSize->setMaximumSize(QSize(229, 20));
        EdgeSize->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        EdgeSize->setMinimum(1.000000000000000);

        verticalLayout_3->addWidget(EdgeSize);

        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(770, 410, 231, 201));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(verticalLayoutWidget_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_5->addWidget(label_9);

        XMovement = new QScrollBar(verticalLayoutWidget_4);
        XMovement->setObjectName(QString::fromUtf8("XMovement"));
        XMovement->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        XMovement->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(XMovement);

        label_10 = new QLabel(verticalLayoutWidget_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_5->addWidget(label_10);

        YMovement = new QScrollBar(verticalLayoutWidget_4);
        YMovement->setObjectName(QString::fromUtf8("YMovement"));
        YMovement->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        YMovement->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(YMovement);

        label_11 = new QLabel(verticalLayoutWidget_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_5->addWidget(label_11);

        ZMovement = new QScrollBar(verticalLayoutWidget_4);
        ZMovement->setObjectName(QString::fromUtf8("ZMovement"));
        ZMovement->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        ZMovement->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(ZMovement);

        verticalLayoutWidget_5 = new QWidget(centralwidget);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(770, 180, 231, 201));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(verticalLayoutWidget_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_6->addWidget(label_12);

        XRotation = new QScrollBar(verticalLayoutWidget_5);
        XRotation->setObjectName(QString::fromUtf8("XRotation"));
        XRotation->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        XRotation->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(XRotation);

        yrot = new QLabel(verticalLayoutWidget_5);
        yrot->setObjectName(QString::fromUtf8("yrot"));
        yrot->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_6->addWidget(yrot);

        YRotation = new QScrollBar(verticalLayoutWidget_5);
        YRotation->setObjectName(QString::fromUtf8("YRotation"));
        YRotation->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        YRotation->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(YRotation);

        label_14 = new QLabel(verticalLayoutWidget_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_6->addWidget(label_14);

        ZRotation = new QScrollBar(verticalLayoutWidget_5);
        ZRotation->setObjectName(QString::fromUtf8("ZRotation"));
        ZRotation->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        ZRotation->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(ZRotation);

        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(770, 390, 151, 16));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(770, 160, 151, 16));
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        CleanPos = new QPushButton(centralwidget);
        CleanPos->setObjectName(QString::fromUtf8("CleanPos"));
        CleanPos->setGeometry(QRect(770, 620, 100, 32));
        CleanPos->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(222, 220, 223);\n"
"color: rgb(253, 251, 255);"));
        CleanColor = new QPushButton(centralwidget);
        CleanColor->setObjectName(QString::fromUtf8("CleanColor"));
        CleanColor->setGeometry(QRect(1020, 620, 100, 32));
        CleanColor->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(253, 251, 255);"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(770, 70, 61, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout->addWidget(label_15, 1, 0, 1, 1);

        label_18 = new QLabel(gridLayoutWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout->addWidget(label_18, 0, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(830, 70, 101, 80));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        VerticeNum = new QLabel(gridLayoutWidget_2);
        VerticeNum->setObjectName(QString::fromUtf8("VerticeNum"));
        VerticeNum->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(VerticeNum, 1, 0, 1, 1);

        EdgeNum = new QLabel(gridLayoutWidget_2);
        EdgeNum->setObjectName(QString::fromUtf8("EdgeNum"));
        EdgeNum->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(EdgeNum, 0, 0, 1, 1);

        Gif = new QPushButton(centralwidget);
        Gif->setObjectName(QString::fromUtf8("Gif"));
        Gif->setGeometry(QRect(50, 670, 100, 32));
        Gif->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(222, 220, 223);\n"
"color: rgb(253, 251, 255);"));
        Screenshot = new QPushButton(centralwidget);
        Screenshot->setObjectName(QString::fromUtf8("Screenshot"));
        Screenshot->setGeometry(QRect(150, 670, 100, 32));
        Screenshot->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(222, 220, 223);\n"
"color: rgb(253, 251, 255);"));
        pathToFile = new QLabel(centralwidget);
        pathToFile->setObjectName(QString::fromUtf8("pathToFile"));
        pathToFile->setGeometry(QRect(255, 674, 391, 21));
        pathToFile->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        ChooseFile = new QPushButton(centralwidget);
        ChooseFile->setObjectName(QString::fromUtf8("ChooseFile"));
        ChooseFile->setGeometry(QRect(641, 670, 100, 32));
        ChooseFile->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(222, 220, 223);\n"
"color: rgb(253, 251, 255);"));
        Screenshot_2 = new QPushButton(centralwidget);
        Screenshot_2->setObjectName(QString::fromUtf8("Screenshot_2"));
        Screenshot_2->setGeometry(QRect(150, 700, 100, 32));
        Screenshot_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(222, 220, 223);\n"
"color: rgb(253, 251, 255);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1288, 24));
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
        label->setText(QApplication::translate("MainWindow", "background color", nullptr));
        BackgroundColor->setItemText(0, QApplication::translate("MainWindow", "white", nullptr));
        BackgroundColor->setItemText(1, QApplication::translate("MainWindow", "black", nullptr));
        BackgroundColor->setItemText(2, QApplication::translate("MainWindow", "yellow", nullptr));
        BackgroundColor->setItemText(3, QApplication::translate("MainWindow", "green", nullptr));
        BackgroundColor->setItemText(4, QApplication::translate("MainWindow", "blue", nullptr));
        BackgroundColor->setItemText(5, QApplication::translate("MainWindow", "red", nullptr));

        label_2->setText(QApplication::translate("MainWindow", "edge color", nullptr));
        BackgroundColor_3->setItemText(0, QApplication::translate("MainWindow", "red", nullptr));
        BackgroundColor_3->setItemText(1, QApplication::translate("MainWindow", "black", nullptr));
        BackgroundColor_3->setItemText(2, QApplication::translate("MainWindow", "white", nullptr));
        BackgroundColor_3->setItemText(3, QApplication::translate("MainWindow", "yellow", nullptr));
        BackgroundColor_3->setItemText(4, QApplication::translate("MainWindow", "green", nullptr));
        BackgroundColor_3->setItemText(5, QApplication::translate("MainWindow", "blue", nullptr));

        label_3->setText(QApplication::translate("MainWindow", "vertice color", nullptr));
        BackgroundColor_4->setItemText(0, QApplication::translate("MainWindow", "red", nullptr));
        BackgroundColor_4->setItemText(1, QApplication::translate("MainWindow", "black", nullptr));
        BackgroundColor_4->setItemText(2, QApplication::translate("MainWindow", "white", nullptr));
        BackgroundColor_4->setItemText(3, QApplication::translate("MainWindow", "yellow", nullptr));
        BackgroundColor_4->setItemText(4, QApplication::translate("MainWindow", "green", nullptr));
        BackgroundColor_4->setItemText(5, QApplication::translate("MainWindow", "blue", nullptr));

        label_4->setText(QApplication::translate("MainWindow", "proection type", nullptr));
        ProectionType->setItemText(0, QApplication::translate("MainWindow", "verital", nullptr));

        label_5->setText(QApplication::translate("MainWindow", "edge type", nullptr));
        EdgeType->setItemText(0, QApplication::translate("MainWindow", "line", nullptr));
        EdgeType->setItemText(1, QApplication::translate("MainWindow", "dashed", nullptr));

        label_6->setText(QApplication::translate("MainWindow", "vertice type", nullptr));
        VerticeType->setItemText(0, QApplication::translate("MainWindow", "spheres", nullptr));
        VerticeType->setItemText(1, QApplication::translate("MainWindow", "cubes", nullptr));

        label_7->setText(QApplication::translate("MainWindow", "vertice size", nullptr));
#ifndef QT_NO_WHATSTHIS
        VerticeSize->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label_8->setText(QApplication::translate("MainWindow", "edge size", nullptr));
#ifndef QT_NO_TOOLTIP
        EdgeSize->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>1</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        EdgeSize->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label_9->setText(QApplication::translate("MainWindow", "x", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "y", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "z", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "x", nullptr));
        yrot->setText(QApplication::translate("MainWindow", "y", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "z", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "move", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "rotate", nullptr));
        CleanPos->setText(QApplication::translate("MainWindow", "clean", nullptr));
        CleanColor->setText(QApplication::translate("MainWindow", "clean", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "vertices", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "edges", nullptr));
        VerticeNum->setText(QApplication::translate("MainWindow", "0", nullptr));
        EdgeNum->setText(QApplication::translate("MainWindow", "0", nullptr));
        Gif->setText(QApplication::translate("MainWindow", "gif", nullptr));
        Screenshot->setText(QApplication::translate("MainWindow", "screen.jpeg", nullptr));
        pathToFile->setText(QApplication::translate("MainWindow", "blablabla.obj", nullptr));
        ChooseFile->setText(QApplication::translate("MainWindow", "choose file", nullptr));
        Screenshot_2->setText(QApplication::translate("MainWindow", "screen.bmp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
