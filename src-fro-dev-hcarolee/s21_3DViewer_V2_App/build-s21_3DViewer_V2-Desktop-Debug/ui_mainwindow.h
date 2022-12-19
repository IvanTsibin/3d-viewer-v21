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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_18;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *InputObject_2;
    QVBoxLayout *verticalLayout_13;
    QVBoxLayout *verticalLayout_14;
    QLabel *ObjFilePath;
    QLabel *ObjFileName;
    QVBoxLayout *verticalLayout_15;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_18;
    QLabel *LBAmountOfVertexes_2;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_19;
    QLabel *LBAmountOfFacets_2;
    QHBoxLayout *horizontalLayout_22;
    QHBoxLayout *horizontalLayout_23;
    QPushButton *PBDraw_2;
    QVBoxLayout *verticalLayout_16;
    QPushButton *PBGifMovie;
    QPushButton *PBJpgPhoto;
    QPushButton *PBBmpPhoto;
    QVBoxLayout *verticalLayout_17;
    QHBoxLayout *horizontalLayout_24;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_20;
    QHBoxLayout *horizontalLayout_25;
    QSpinBox *SBRedColor;
    QSpinBox *SBGreenColor;
    QSpinBox *SBBlueColor;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_21;
    QHBoxLayout *horizontalLayout_26;
    QSpinBox *SBRedColorLine;
    QSpinBox *SBGreenColorLine;
    QSpinBox *SBBlueColorLine;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_22;
    QHBoxLayout *horizontalLayout_27;
    QSpinBox *SBRedColorVertex;
    QSpinBox *SBGreenColorVertex;
    QSpinBox *SBBlueColorVertex;
    QHBoxLayout *horizontalLayout_28;
    QHBoxLayout *horizontalLayout_29;
    QCheckBox *CBPerspective;
    QPushButton *PBToZero;
    QCheckBox *CBDashLine;
    QHBoxLayout *horizontalLayout_30;
    QVBoxLayout *verticalLayout_21;
    QLabel *label_11;
    QSpinBox *SBLineWidth;
    QVBoxLayout *verticalLayout_22;
    QLabel *label_23;
    QComboBox *CBVertexType;
    QVBoxLayout *verticalLayout_23;
    QLabel *label_24;
    QSpinBox *SBVertexSize;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *SBxRot;
    QSpinBox *SByRot;
    QSpinBox *SBzRot;
    QDoubleSpinBox *DSBMultip;
    QDoubleSpinBox *DSBxMove;
    QDoubleSpinBox *DSByMove;
    QDoubleSpinBox *DSBzMove;
    QHBoxLayout *horizontalLayout;
    QSlider *xSlider;
    QSlider *ySlider;
    QSlider *zSlider;
    QSlider *MultipSlider;
    QSlider *xMoveSlider;
    QSlider *yMoveSlider;
    QSlider *zMoveSlider;
    QLabel *label_8;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1309, 864);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMaximumSize(QSize(2560, 1440));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        InputObject_2 = new QPushButton(centralWidget);
        InputObject_2->setObjectName(QString::fromUtf8("InputObject_2"));

        horizontalLayout_19->addWidget(InputObject_2);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        ObjFilePath = new QLabel(centralWidget);
        ObjFilePath->setObjectName(QString::fromUtf8("ObjFilePath"));
        QFont font;
        font.setPointSize(8);
        ObjFilePath->setFont(font);
        ObjFilePath->setAlignment(Qt::AlignCenter);
        ObjFilePath->setWordWrap(true);

        verticalLayout_14->addWidget(ObjFilePath);

        ObjFileName = new QLabel(centralWidget);
        ObjFileName->setObjectName(QString::fromUtf8("ObjFileName"));
        QFont font1;
        font1.setPointSize(12);
        ObjFileName->setFont(font1);
        ObjFileName->setAlignment(Qt::AlignCenter);
        ObjFileName->setWordWrap(true);

        verticalLayout_14->addWidget(ObjFileName);


        verticalLayout_13->addLayout(verticalLayout_14);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_20->addWidget(label_18);

        LBAmountOfVertexes_2 = new QLabel(centralWidget);
        LBAmountOfVertexes_2->setObjectName(QString::fromUtf8("LBAmountOfVertexes_2"));

        horizontalLayout_20->addWidget(LBAmountOfVertexes_2);


        verticalLayout_15->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_21->addWidget(label_19);

        LBAmountOfFacets_2 = new QLabel(centralWidget);
        LBAmountOfFacets_2->setObjectName(QString::fromUtf8("LBAmountOfFacets_2"));

        horizontalLayout_21->addWidget(LBAmountOfFacets_2);


        verticalLayout_15->addLayout(horizontalLayout_21);


        verticalLayout_13->addLayout(verticalLayout_15);


        horizontalLayout_19->addLayout(verticalLayout_13);


        horizontalLayout_18->addLayout(horizontalLayout_19);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        PBDraw_2 = new QPushButton(centralWidget);
        PBDraw_2->setObjectName(QString::fromUtf8("PBDraw_2"));

        horizontalLayout_23->addWidget(PBDraw_2);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        PBGifMovie = new QPushButton(centralWidget);
        PBGifMovie->setObjectName(QString::fromUtf8("PBGifMovie"));
        PBGifMovie->setFont(font);

        verticalLayout_16->addWidget(PBGifMovie);

        PBJpgPhoto = new QPushButton(centralWidget);
        PBJpgPhoto->setObjectName(QString::fromUtf8("PBJpgPhoto"));
        PBJpgPhoto->setFont(font);

        verticalLayout_16->addWidget(PBJpgPhoto);

        PBBmpPhoto = new QPushButton(centralWidget);
        PBBmpPhoto->setObjectName(QString::fromUtf8("PBBmpPhoto"));
        PBBmpPhoto->setFont(font);

        verticalLayout_16->addWidget(PBBmpPhoto);


        horizontalLayout_23->addLayout(verticalLayout_16);


        horizontalLayout_22->addLayout(horizontalLayout_23);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        verticalLayout_18->addWidget(label_20);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        SBRedColor = new QSpinBox(centralWidget);
        SBRedColor->setObjectName(QString::fromUtf8("SBRedColor"));
        SBRedColor->setFont(font);
        SBRedColor->setMaximum(255);
        SBRedColor->setValue(50);

        horizontalLayout_25->addWidget(SBRedColor);

        SBGreenColor = new QSpinBox(centralWidget);
        SBGreenColor->setObjectName(QString::fromUtf8("SBGreenColor"));
        SBGreenColor->setFont(font);
        SBGreenColor->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SBGreenColor->setMinimum(0);
        SBGreenColor->setMaximum(255);
        SBGreenColor->setValue(50);

        horizontalLayout_25->addWidget(SBGreenColor);

        SBBlueColor = new QSpinBox(centralWidget);
        SBBlueColor->setObjectName(QString::fromUtf8("SBBlueColor"));
        SBBlueColor->setFont(font);
        SBBlueColor->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SBBlueColor->setMinimum(0);
        SBBlueColor->setMaximum(255);
        SBBlueColor->setValue(50);

        horizontalLayout_25->addWidget(SBBlueColor);


        verticalLayout_18->addLayout(horizontalLayout_25);


        horizontalLayout_24->addLayout(verticalLayout_18);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        QFont font2;
        font2.setPointSize(10);
        label_21->setFont(font2);

        verticalLayout_19->addWidget(label_21);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        SBRedColorLine = new QSpinBox(centralWidget);
        SBRedColorLine->setObjectName(QString::fromUtf8("SBRedColorLine"));
        SBRedColorLine->setFont(font);
        SBRedColorLine->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SBRedColorLine->setMinimum(0);
        SBRedColorLine->setMaximum(255);
        SBRedColorLine->setValue(50);

        horizontalLayout_26->addWidget(SBRedColorLine);

        SBGreenColorLine = new QSpinBox(centralWidget);
        SBGreenColorLine->setObjectName(QString::fromUtf8("SBGreenColorLine"));
        SBGreenColorLine->setFont(font);
        SBGreenColorLine->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SBGreenColorLine->setMinimum(0);
        SBGreenColorLine->setMaximum(255);
        SBGreenColorLine->setValue(180);

        horizontalLayout_26->addWidget(SBGreenColorLine);

        SBBlueColorLine = new QSpinBox(centralWidget);
        SBBlueColorLine->setObjectName(QString::fromUtf8("SBBlueColorLine"));
        SBBlueColorLine->setFont(font);
        SBBlueColorLine->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SBBlueColorLine->setMinimum(0);
        SBBlueColorLine->setMaximum(255);
        SBBlueColorLine->setValue(160);

        horizontalLayout_26->addWidget(SBBlueColorLine);


        verticalLayout_19->addLayout(horizontalLayout_26);


        horizontalLayout_24->addLayout(verticalLayout_19);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        label_22 = new QLabel(centralWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font2);

        verticalLayout_20->addWidget(label_22);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        SBRedColorVertex = new QSpinBox(centralWidget);
        SBRedColorVertex->setObjectName(QString::fromUtf8("SBRedColorVertex"));
        SBRedColorVertex->setFont(font);
        SBRedColorVertex->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SBRedColorVertex->setMinimum(0);
        SBRedColorVertex->setMaximum(255);
        SBRedColorVertex->setValue(50);

        horizontalLayout_27->addWidget(SBRedColorVertex);

        SBGreenColorVertex = new QSpinBox(centralWidget);
        SBGreenColorVertex->setObjectName(QString::fromUtf8("SBGreenColorVertex"));
        SBGreenColorVertex->setFont(font);
        SBGreenColorVertex->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SBGreenColorVertex->setMinimum(0);
        SBGreenColorVertex->setMaximum(255);
        SBGreenColorVertex->setValue(180);

        horizontalLayout_27->addWidget(SBGreenColorVertex);

        SBBlueColorVertex = new QSpinBox(centralWidget);
        SBBlueColorVertex->setObjectName(QString::fromUtf8("SBBlueColorVertex"));
        SBBlueColorVertex->setFont(font);
        SBBlueColorVertex->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SBBlueColorVertex->setMinimum(0);
        SBBlueColorVertex->setMaximum(255);
        SBBlueColorVertex->setValue(160);

        horizontalLayout_27->addWidget(SBBlueColorVertex);


        verticalLayout_20->addLayout(horizontalLayout_27);


        horizontalLayout_24->addLayout(verticalLayout_20);


        verticalLayout_17->addLayout(horizontalLayout_24);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(6);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        CBPerspective = new QCheckBox(centralWidget);
        CBPerspective->setObjectName(QString::fromUtf8("CBPerspective"));
        CBPerspective->setFont(font);
        CBPerspective->setChecked(true);

        horizontalLayout_29->addWidget(CBPerspective);

        PBToZero = new QPushButton(centralWidget);
        PBToZero->setObjectName(QString::fromUtf8("PBToZero"));
        PBToZero->setFont(font);

        horizontalLayout_29->addWidget(PBToZero);

        CBDashLine = new QCheckBox(centralWidget);
        CBDashLine->setObjectName(QString::fromUtf8("CBDashLine"));
        CBDashLine->setFont(font);

        horizontalLayout_29->addWidget(CBDashLine);


        horizontalLayout_28->addLayout(horizontalLayout_29);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setSpacing(6);
        verticalLayout_21->setObjectName(QString::fromUtf8("verticalLayout_21"));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_21->addWidget(label_11);

        SBLineWidth = new QSpinBox(centralWidget);
        SBLineWidth->setObjectName(QString::fromUtf8("SBLineWidth"));
        SBLineWidth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SBLineWidth->setMinimum(1);
        SBLineWidth->setMaximum(10);

        verticalLayout_21->addWidget(SBLineWidth);


        horizontalLayout_30->addLayout(verticalLayout_21);

        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setSpacing(6);
        verticalLayout_22->setObjectName(QString::fromUtf8("verticalLayout_22"));
        label_23 = new QLabel(centralWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setFont(font);
        label_23->setAlignment(Qt::AlignCenter);

        verticalLayout_22->addWidget(label_23);

        CBVertexType = new QComboBox(centralWidget);
        CBVertexType->addItem(QString());
        CBVertexType->addItem(QString());
        CBVertexType->addItem(QString());
        CBVertexType->setObjectName(QString::fromUtf8("CBVertexType"));
        CBVertexType->setFont(font);

        verticalLayout_22->addWidget(CBVertexType);


        horizontalLayout_30->addLayout(verticalLayout_22);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setSpacing(6);
        verticalLayout_23->setObjectName(QString::fromUtf8("verticalLayout_23"));
        label_24 = new QLabel(centralWidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setFont(font);
        label_24->setAlignment(Qt::AlignCenter);

        verticalLayout_23->addWidget(label_24);

        SBVertexSize = new QSpinBox(centralWidget);
        SBVertexSize->setObjectName(QString::fromUtf8("SBVertexSize"));
        SBVertexSize->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SBVertexSize->setMinimum(1);
        SBVertexSize->setMaximum(45);
        SBVertexSize->setValue(5);

        verticalLayout_23->addWidget(SBVertexSize);


        horizontalLayout_30->addLayout(verticalLayout_23);


        horizontalLayout_28->addLayout(horizontalLayout_30);


        verticalLayout_17->addLayout(horizontalLayout_28);


        horizontalLayout_22->addLayout(verticalLayout_17);


        horizontalLayout_18->addLayout(horizontalLayout_22);


        verticalLayout_2->addLayout(horizontalLayout_18);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(15);

        horizontalLayout_4->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_7);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_4);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_5);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        SBxRot = new QSpinBox(centralWidget);
        SBxRot->setObjectName(QString::fromUtf8("SBxRot"));
        SBxRot->setMaximum(360);

        horizontalLayout_3->addWidget(SBxRot);

        SByRot = new QSpinBox(centralWidget);
        SByRot->setObjectName(QString::fromUtf8("SByRot"));
        SByRot->setMaximum(360);

        horizontalLayout_3->addWidget(SByRot);

        SBzRot = new QSpinBox(centralWidget);
        SBzRot->setObjectName(QString::fromUtf8("SBzRot"));
        SBzRot->setMaximum(360);

        horizontalLayout_3->addWidget(SBzRot);

        DSBMultip = new QDoubleSpinBox(centralWidget);
        DSBMultip->setObjectName(QString::fromUtf8("DSBMultip"));
        DSBMultip->setMinimum(0.050000000000000);
        DSBMultip->setMaximum(10.000000000000000);
        DSBMultip->setSingleStep(0.050000000000000);
        DSBMultip->setValue(1.000000000000000);

        horizontalLayout_3->addWidget(DSBMultip);

        DSBxMove = new QDoubleSpinBox(centralWidget);
        DSBxMove->setObjectName(QString::fromUtf8("DSBxMove"));
        DSBxMove->setDecimals(2);
        DSBxMove->setMinimum(-1.000000000000000);
        DSBxMove->setMaximum(1.000000000000000);
        DSBxMove->setSingleStep(0.010000000000000);

        horizontalLayout_3->addWidget(DSBxMove);

        DSByMove = new QDoubleSpinBox(centralWidget);
        DSByMove->setObjectName(QString::fromUtf8("DSByMove"));
        DSByMove->setDecimals(2);
        DSByMove->setMinimum(-1.000000000000000);
        DSByMove->setMaximum(1.000000000000000);
        DSByMove->setSingleStep(0.010000000000000);

        horizontalLayout_3->addWidget(DSByMove);

        DSBzMove = new QDoubleSpinBox(centralWidget);
        DSBzMove->setObjectName(QString::fromUtf8("DSBzMove"));
        DSBzMove->setDecimals(2);
        DSBzMove->setMinimum(-1.000000000000000);
        DSBzMove->setMaximum(1.000000000000000);
        DSBzMove->setSingleStep(0.010000000000000);
        DSBzMove->setValue(0.000000000000000);

        horizontalLayout_3->addWidget(DSBzMove);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        xSlider = new QSlider(centralWidget);
        xSlider->setObjectName(QString::fromUtf8("xSlider"));
        xSlider->setMinimum(0);
        xSlider->setMaximum(5760);
        xSlider->setSingleStep(16);
        xSlider->setPageStep(320);
        xSlider->setSliderPosition(0);
        xSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(xSlider);

        ySlider = new QSlider(centralWidget);
        ySlider->setObjectName(QString::fromUtf8("ySlider"));
        ySlider->setMinimum(0);
        ySlider->setMaximum(5760);
        ySlider->setSliderPosition(0);
        ySlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(ySlider);

        zSlider = new QSlider(centralWidget);
        zSlider->setObjectName(QString::fromUtf8("zSlider"));
        zSlider->setMinimum(0);
        zSlider->setMaximum(5760);
        zSlider->setSliderPosition(0);
        zSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(zSlider);

        MultipSlider = new QSlider(centralWidget);
        MultipSlider->setObjectName(QString::fromUtf8("MultipSlider"));
        MultipSlider->setMinimum(-95);
        MultipSlider->setMaximum(900);
        MultipSlider->setSingleStep(5);
        MultipSlider->setPageStep(20);
        MultipSlider->setValue(0);
        MultipSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(MultipSlider);

        xMoveSlider = new QSlider(centralWidget);
        xMoveSlider->setObjectName(QString::fromUtf8("xMoveSlider"));
        xMoveSlider->setMinimum(-100);
        xMoveSlider->setMaximum(100);
        xMoveSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(xMoveSlider);

        yMoveSlider = new QSlider(centralWidget);
        yMoveSlider->setObjectName(QString::fromUtf8("yMoveSlider"));
        yMoveSlider->setMinimum(-100);
        yMoveSlider->setMaximum(100);
        yMoveSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(yMoveSlider);

        zMoveSlider = new QSlider(centralWidget);
        zMoveSlider->setObjectName(QString::fromUtf8("zMoveSlider"));
        zMoveSlider->setMinimum(-100);
        zMoveSlider->setMaximum(100);
        zMoveSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(zMoveSlider);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_4);


        gridLayout_2->addLayout(verticalLayout_2, 1, 0, 1, 1);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font3;
        font3.setPointSize(14);
        label_8->setFont(font3);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        InputObject_2->setText(QApplication::translate("MainWindow", "InputObject", nullptr));
        ObjFilePath->setText(QApplication::translate("MainWindow", "home directory", nullptr));
        ObjFileName->setText(QApplication::translate("MainWindow", "cube-2.obj", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "Amount of vertexes", nullptr));
        LBAmountOfVertexes_2->setText(QApplication::translate("MainWindow", "8", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "Amount of Facets", nullptr));
        LBAmountOfFacets_2->setText(QApplication::translate("MainWindow", "12", nullptr));
        PBDraw_2->setText(QApplication::translate("MainWindow", "Draw", nullptr));
        PBGifMovie->setText(QApplication::translate("MainWindow", "Start Gif", nullptr));
        PBJpgPhoto->setText(QApplication::translate("MainWindow", "jpg photo", nullptr));
        PBBmpPhoto->setText(QApplication::translate("MainWindow", "bmp photo", nullptr));
        label_20->setText(QApplication::translate("MainWindow", " Red    Green    Blue", nullptr));
        label_21->setText(QApplication::translate("MainWindow", " Red    Green    Blue - lines", nullptr));
        label_22->setText(QApplication::translate("MainWindow", " Red    Green    Blue - vertex", nullptr));
        CBPerspective->setText(QApplication::translate("MainWindow", "Perspective", nullptr));
        PBToZero->setText(QApplication::translate("MainWindow", "ToZero", nullptr));
        CBDashLine->setText(QApplication::translate("MainWindow", "DashLine", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Line's width", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "Vertex Type", nullptr));
        CBVertexType->setItemText(0, QApplication::translate("MainWindow", "none", nullptr));
        CBVertexType->setItemText(1, QApplication::translate("MainWindow", "circle", nullptr));
        CBVertexType->setItemText(2, QApplication::translate("MainWindow", "square", nullptr));

        label_24->setText(QApplication::translate("MainWindow", "Vertex Size", nullptr));
        label->setText(QApplication::translate("MainWindow", "xRot", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "yRot", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "zRot", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Multip", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "xMove", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "yMove", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "zMove", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "3D Viewer V 2.0  School-21 Novosibirsk", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
