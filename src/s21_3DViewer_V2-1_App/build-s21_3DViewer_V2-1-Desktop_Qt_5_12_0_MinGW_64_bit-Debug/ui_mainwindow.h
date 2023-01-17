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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
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
    QAction *ALoadModel;
    QAction *ASaveSettings;
    QAction *AExit;
    QAction *ASaveFreeGif;
    QAction *ASaveYRotGif;
    QAction *ASaveJpg;
    QAction *ASaveBmp;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QPushButton *InputObject_2;
    QPushButton *PBDraw_2;
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
    QVBoxLayout *verticalLayout_5;
    QPushButton *PBGifMovie;
    QPushButton *PByRotGif;
    QVBoxLayout *verticalLayout_6;
    QPushButton *PBJpgPhoto;
    QPushButton *PBBmpPhoto;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_18;
    QPushButton *PBSceneColor;
    QLabel *LSceneColor;
    QVBoxLayout *verticalLayout_3;
    QPushButton *PBLightColor;
    QLabel *LLightColor;
    QVBoxLayout *verticalLayout_19;
    QPushButton *PBLineColor;
    QLabel *LLineColor;
    QVBoxLayout *verticalLayout_20;
    QPushButton *PBVertexColor;
    QLabel *LVertexColor;
    QVBoxLayout *verticalLayout_2;
    QPushButton *PBFacetsColor;
    QLabel *LFacetsColor;
    QHBoxLayout *horizontalLayout_28;
    QHBoxLayout *horizontalLayout_29;
    QCheckBox *CBPerspective;
    QCheckBox *CBFacets;
    QCheckBox *CBNormalGuro;
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
    QLabel *label_9;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *SBxRot;
    QSpinBox *SByRot;
    QSpinBox *SBzRot;
    QDoubleSpinBox *DSBMultip;
    QDoubleSpinBox *DSBxMove;
    QDoubleSpinBox *DSByMove;
    QDoubleSpinBox *DSBzMove;
    QDoubleSpinBox *DSBxLight;
    QDoubleSpinBox *DSByLight;
    QHBoxLayout *horizontalLayout;
    QSlider *xSlider;
    QSlider *ySlider;
    QSlider *zSlider;
    QSlider *MultipSlider;
    QSlider *xMoveSlider;
    QSlider *yMoveSlider;
    QSlider *zMoveSlider;
    QSlider *xLightSlider;
    QSlider *yLightSlider;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSave;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1259, 864);
        ALoadModel = new QAction(MainWindow);
        ALoadModel->setObjectName(QString::fromUtf8("ALoadModel"));
        ASaveSettings = new QAction(MainWindow);
        ASaveSettings->setObjectName(QString::fromUtf8("ASaveSettings"));
        AExit = new QAction(MainWindow);
        AExit->setObjectName(QString::fromUtf8("AExit"));
        ASaveFreeGif = new QAction(MainWindow);
        ASaveFreeGif->setObjectName(QString::fromUtf8("ASaveFreeGif"));
        ASaveYRotGif = new QAction(MainWindow);
        ASaveYRotGif->setObjectName(QString::fromUtf8("ASaveYRotGif"));
        ASaveJpg = new QAction(MainWindow);
        ASaveJpg->setObjectName(QString::fromUtf8("ASaveJpg"));
        ASaveBmp = new QAction(MainWindow);
        ASaveBmp->setObjectName(QString::fromUtf8("ASaveBmp"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMaximumSize(QSize(2560, 1440));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        InputObject_2 = new QPushButton(centralWidget);
        InputObject_2->setObjectName(QString::fromUtf8("InputObject_2"));

        verticalLayout_4->addWidget(InputObject_2);

        PBDraw_2 = new QPushButton(centralWidget);
        PBDraw_2->setObjectName(QString::fromUtf8("PBDraw_2"));

        verticalLayout_4->addWidget(PBDraw_2);


        horizontalLayout_6->addLayout(verticalLayout_4);

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


        horizontalLayout_6->addLayout(verticalLayout_13);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        PBGifMovie = new QPushButton(centralWidget);
        PBGifMovie->setObjectName(QString::fromUtf8("PBGifMovie"));
        PBGifMovie->setFont(font);

        verticalLayout_5->addWidget(PBGifMovie);

        PByRotGif = new QPushButton(centralWidget);
        PByRotGif->setObjectName(QString::fromUtf8("PByRotGif"));
        PByRotGif->setFont(font);

        verticalLayout_5->addWidget(PByRotGif);


        horizontalLayout_6->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        PBJpgPhoto = new QPushButton(centralWidget);
        PBJpgPhoto->setObjectName(QString::fromUtf8("PBJpgPhoto"));
        PBJpgPhoto->setFont(font);

        verticalLayout_6->addWidget(PBJpgPhoto);

        PBBmpPhoto = new QPushButton(centralWidget);
        PBBmpPhoto->setObjectName(QString::fromUtf8("PBBmpPhoto"));
        PBBmpPhoto->setFont(font);

        verticalLayout_6->addWidget(PBBmpPhoto);


        horizontalLayout_6->addLayout(verticalLayout_6);


        horizontalLayout_7->addLayout(horizontalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        PBSceneColor = new QPushButton(centralWidget);
        PBSceneColor->setObjectName(QString::fromUtf8("PBSceneColor"));

        verticalLayout_18->addWidget(PBSceneColor);

        LSceneColor = new QLabel(centralWidget);
        LSceneColor->setObjectName(QString::fromUtf8("LSceneColor"));
        LSceneColor->setAlignment(Qt::AlignCenter);

        verticalLayout_18->addWidget(LSceneColor);


        horizontalLayout_5->addLayout(verticalLayout_18);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        PBLightColor = new QPushButton(centralWidget);
        PBLightColor->setObjectName(QString::fromUtf8("PBLightColor"));

        verticalLayout_3->addWidget(PBLightColor);

        LLightColor = new QLabel(centralWidget);
        LLightColor->setObjectName(QString::fromUtf8("LLightColor"));
        LLightColor->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(LLightColor);


        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        PBLineColor = new QPushButton(centralWidget);
        PBLineColor->setObjectName(QString::fromUtf8("PBLineColor"));

        verticalLayout_19->addWidget(PBLineColor);

        LLineColor = new QLabel(centralWidget);
        LLineColor->setObjectName(QString::fromUtf8("LLineColor"));
        LLineColor->setAlignment(Qt::AlignCenter);

        verticalLayout_19->addWidget(LLineColor);


        horizontalLayout_5->addLayout(verticalLayout_19);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        PBVertexColor = new QPushButton(centralWidget);
        PBVertexColor->setObjectName(QString::fromUtf8("PBVertexColor"));

        verticalLayout_20->addWidget(PBVertexColor);

        LVertexColor = new QLabel(centralWidget);
        LVertexColor->setObjectName(QString::fromUtf8("LVertexColor"));
        LVertexColor->setAlignment(Qt::AlignCenter);

        verticalLayout_20->addWidget(LVertexColor);


        horizontalLayout_5->addLayout(verticalLayout_20);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        PBFacetsColor = new QPushButton(centralWidget);
        PBFacetsColor->setObjectName(QString::fromUtf8("PBFacetsColor"));

        verticalLayout_2->addWidget(PBFacetsColor);

        LFacetsColor = new QLabel(centralWidget);
        LFacetsColor->setObjectName(QString::fromUtf8("LFacetsColor"));
        LFacetsColor->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(LFacetsColor);


        horizontalLayout_5->addLayout(verticalLayout_2);


        verticalLayout_7->addLayout(horizontalLayout_5);

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

        CBFacets = new QCheckBox(centralWidget);
        CBFacets->setObjectName(QString::fromUtf8("CBFacets"));
        CBFacets->setFont(font);
        CBFacets->setChecked(true);

        horizontalLayout_29->addWidget(CBFacets);

        CBNormalGuro = new QCheckBox(centralWidget);
        CBNormalGuro->setObjectName(QString::fromUtf8("CBNormalGuro"));
        CBNormalGuro->setChecked(true);

        horizontalLayout_29->addWidget(CBNormalGuro);

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
        SBLineWidth->setMinimum(0);
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
        SBVertexSize->setMinimum(0);
        SBVertexSize->setMaximum(45);
        SBVertexSize->setValue(5);

        verticalLayout_23->addWidget(SBVertexSize);


        horizontalLayout_30->addLayout(verticalLayout_23);


        horizontalLayout_28->addLayout(horizontalLayout_30);


        verticalLayout_7->addLayout(horizontalLayout_28);


        horizontalLayout_7->addLayout(verticalLayout_7);


        gridLayout_2->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(30);

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

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_9);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_2->addWidget(label_10);


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

        DSBxLight = new QDoubleSpinBox(centralWidget);
        DSBxLight->setObjectName(QString::fromUtf8("DSBxLight"));
        DSBxLight->setDecimals(1);
        DSBxLight->setMinimum(-10.000000000000000);
        DSBxLight->setMaximum(10.000000000000000);
        DSBxLight->setSingleStep(0.100000000000000);

        horizontalLayout_3->addWidget(DSBxLight);

        DSByLight = new QDoubleSpinBox(centralWidget);
        DSByLight->setObjectName(QString::fromUtf8("DSByLight"));
        DSByLight->setDecimals(1);
        DSByLight->setMinimum(-10.000000000000000);
        DSByLight->setMaximum(10.000000000000000);
        DSByLight->setSingleStep(0.100000000000000);

        horizontalLayout_3->addWidget(DSByLight);


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

        xLightSlider = new QSlider(centralWidget);
        xLightSlider->setObjectName(QString::fromUtf8("xLightSlider"));
        xLightSlider->setMinimum(-1000);
        xLightSlider->setMaximum(1000);
        xLightSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(xLightSlider);

        yLightSlider = new QSlider(centralWidget);
        yLightSlider->setObjectName(QString::fromUtf8("yLightSlider"));
        yLightSlider->setMinimum(-1000);
        yLightSlider->setMaximum(1000);
        yLightSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(yLightSlider);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1259, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuSave = new QMenu(menuBar);
        menuSave->setObjectName(QString::fromUtf8("menuSave"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSave->menuAction());
        menuFile->addAction(ALoadModel);
        menuFile->addAction(AExit);
        menuSave->addAction(ASaveSettings);
        menuSave->addAction(ASaveFreeGif);
        menuSave->addAction(ASaveYRotGif);
        menuSave->addAction(ASaveJpg);
        menuSave->addAction(ASaveBmp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "3D Viewer V 2.1  School-21 Novosibirsk", nullptr));
        ALoadModel->setText(QApplication::translate("MainWindow", "Load Model", nullptr));
        ASaveSettings->setText(QApplication::translate("MainWindow", "Save settings", nullptr));
        AExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        ASaveFreeGif->setText(QApplication::translate("MainWindow", "Save free Gif", nullptr));
        ASaveYRotGif->setText(QApplication::translate("MainWindow", "Save y Rot Gif", nullptr));
        ASaveJpg->setText(QApplication::translate("MainWindow", "Save jpg", nullptr));
        ASaveBmp->setText(QApplication::translate("MainWindow", "save bmp", nullptr));
        InputObject_2->setText(QApplication::translate("MainWindow", "InputObject", nullptr));
        PBDraw_2->setText(QApplication::translate("MainWindow", "Draw", nullptr));
        ObjFilePath->setText(QApplication::translate("MainWindow", "home directory", nullptr));
        ObjFileName->setText(QApplication::translate("MainWindow", "cube-2.obj", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "Amount of vertexes", nullptr));
        LBAmountOfVertexes_2->setText(QApplication::translate("MainWindow", "8", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "Amount of Facets", nullptr));
        LBAmountOfFacets_2->setText(QApplication::translate("MainWindow", "12", nullptr));
        PBGifMovie->setText(QApplication::translate("MainWindow", "Start Gif", nullptr));
        PByRotGif->setText(QApplication::translate("MainWindow", "y Rot Gif", nullptr));
        PBJpgPhoto->setText(QApplication::translate("MainWindow", "jpg photo", nullptr));
        PBBmpPhoto->setText(QApplication::translate("MainWindow", "bmp photo", nullptr));
        PBSceneColor->setText(QApplication::translate("MainWindow", "Scene Color", nullptr));
        LSceneColor->setText(QApplication::translate("MainWindow", "Scene Color", nullptr));
        PBLightColor->setText(QApplication::translate("MainWindow", "Light Color", nullptr));
        LLightColor->setText(QApplication::translate("MainWindow", "Light Color", nullptr));
        PBLineColor->setText(QApplication::translate("MainWindow", "Line's Color", nullptr));
        LLineColor->setText(QApplication::translate("MainWindow", "Line's Color", nullptr));
        PBVertexColor->setText(QApplication::translate("MainWindow", "Vertex Color", nullptr));
        LVertexColor->setText(QApplication::translate("MainWindow", "Vertex Color", nullptr));
        PBFacetsColor->setText(QApplication::translate("MainWindow", "Facets Color", nullptr));
        LFacetsColor->setText(QApplication::translate("MainWindow", "Facets Color", nullptr));
        CBPerspective->setText(QApplication::translate("MainWindow", "Perspective", nullptr));
        CBFacets->setText(QApplication::translate("MainWindow", "Facets", nullptr));
        CBNormalGuro->setText(QApplication::translate("MainWindow", "Normal/Guro", nullptr));
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
        label_9->setText(QApplication::translate("MainWindow", "xLight", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "yLight", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuSave->setTitle(QApplication::translate("MainWindow", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
