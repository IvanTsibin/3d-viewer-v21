/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../s21_3DViewer_V2-1/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[77];
    char stringdata0[1578];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 25), // "SendMainWindowSizeChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "SendFileName"
QT_MOC_LITERAL(4, 51, 5), // "char*"
QT_MOC_LITERAL(5, 57, 14), // "SendSceneColor"
QT_MOC_LITERAL(6, 72, 13), // "SendLineColor"
QT_MOC_LITERAL(7, 86, 15), // "SendVertexColor"
QT_MOC_LITERAL(8, 102, 15), // "SendFacetsColor"
QT_MOC_LITERAL(9, 118, 14), // "SendLightColor"
QT_MOC_LITERAL(10, 133, 13), // "SendLineWidth"
QT_MOC_LITERAL(11, 147, 14), // "SendVertexSize"
QT_MOC_LITERAL(12, 162, 14), // "SendVertexType"
QT_MOC_LITERAL(13, 177, 18), // "SendPerspectStatus"
QT_MOC_LITERAL(14, 196, 16), // "SendFacetsStatus"
QT_MOC_LITERAL(15, 213, 18), // "SendDashLineSignal"
QT_MOC_LITERAL(16, 232, 21), // "SendSavePictureSignal"
QT_MOC_LITERAL(17, 254, 20), // "SendNormalGuroSignal"
QT_MOC_LITERAL(18, 275, 22), // "SendRequestForSettings"
QT_MOC_LITERAL(19, 298, 27), // "SendRequestForSavedSettings"
QT_MOC_LITERAL(20, 326, 22), // "SendSaveSettingsSignal"
QT_MOC_LITERAL(21, 349, 29), // "on_MainWindow_iconSizeChanged"
QT_MOC_LITERAL(22, 379, 8), // "iconSize"
QT_MOC_LITERAL(23, 388, 24), // "on_InputObject_2_clicked"
QT_MOC_LITERAL(24, 413, 19), // "on_PBDraw_2_clicked"
QT_MOC_LITERAL(25, 433, 27), // "on_SBLineWidth_valueChanged"
QT_MOC_LITERAL(26, 461, 4), // "arg1"
QT_MOC_LITERAL(27, 466, 28), // "on_SBVertexSize_valueChanged"
QT_MOC_LITERAL(28, 495, 34), // "on_CBVertexType_currentTextCh..."
QT_MOC_LITERAL(29, 530, 24), // "on_CBPerspective_toggled"
QT_MOC_LITERAL(30, 555, 7), // "checked"
QT_MOC_LITERAL(31, 563, 19), // "on_CBFacets_toggled"
QT_MOC_LITERAL(32, 583, 21), // "on_CBDashLine_toggled"
QT_MOC_LITERAL(33, 605, 19), // "on_PBToZero_clicked"
QT_MOC_LITERAL(34, 625, 21), // "on_PBJpgPhoto_clicked"
QT_MOC_LITERAL(35, 647, 21), // "on_PBBmpPhoto_clicked"
QT_MOC_LITERAL(36, 669, 21), // "on_PBGifMovie_clicked"
QT_MOC_LITERAL(37, 691, 20), // "on_PByRotGif_clicked"
QT_MOC_LITERAL(38, 712, 23), // "on_xSlider_valueChanged"
QT_MOC_LITERAL(39, 736, 5), // "value"
QT_MOC_LITERAL(40, 742, 23), // "on_ySlider_valueChanged"
QT_MOC_LITERAL(41, 766, 23), // "on_zSlider_valueChanged"
QT_MOC_LITERAL(42, 790, 28), // "on_MultipSlider_valueChanged"
QT_MOC_LITERAL(43, 819, 27), // "on_xMoveSlider_valueChanged"
QT_MOC_LITERAL(44, 847, 27), // "on_yMoveSlider_valueChanged"
QT_MOC_LITERAL(45, 875, 27), // "on_zMoveSlider_valueChanged"
QT_MOC_LITERAL(46, 903, 22), // "on_SBxRot_valueChanged"
QT_MOC_LITERAL(47, 926, 22), // "on_SByRot_valueChanged"
QT_MOC_LITERAL(48, 949, 22), // "on_SBzRot_valueChanged"
QT_MOC_LITERAL(49, 972, 25), // "on_DSBMultip_valueChanged"
QT_MOC_LITERAL(50, 998, 24), // "on_DSBxMove_valueChanged"
QT_MOC_LITERAL(51, 1023, 24), // "on_DSByMove_valueChanged"
QT_MOC_LITERAL(52, 1048, 24), // "on_DSBzMove_valueChanged"
QT_MOC_LITERAL(53, 1073, 28), // "on_xLightSlider_valueChanged"
QT_MOC_LITERAL(54, 1102, 28), // "on_yLightSlider_valueChanged"
QT_MOC_LITERAL(55, 1131, 25), // "on_DSBxLight_valueChanged"
QT_MOC_LITERAL(56, 1157, 25), // "on_DSByLight_valueChanged"
QT_MOC_LITERAL(57, 1183, 23), // "on_CBNormalGuro_toggled"
QT_MOC_LITERAL(58, 1207, 21), // "SetUpColorLablesColor"
QT_MOC_LITERAL(59, 1229, 23), // "on_ALoadModel_triggered"
QT_MOC_LITERAL(60, 1253, 25), // "on_ASaveFreeGif_triggered"
QT_MOC_LITERAL(61, 1279, 25), // "on_ASaveYRotGif_triggered"
QT_MOC_LITERAL(62, 1305, 21), // "on_ASaveJpg_triggered"
QT_MOC_LITERAL(63, 1327, 21), // "on_ASaveBmp_triggered"
QT_MOC_LITERAL(64, 1349, 23), // "on_PBSceneColor_clicked"
QT_MOC_LITERAL(65, 1373, 22), // "on_PBLineColor_clicked"
QT_MOC_LITERAL(66, 1396, 24), // "on_PBVertexColor_clicked"
QT_MOC_LITERAL(67, 1421, 24), // "on_PBFacetsColor_clicked"
QT_MOC_LITERAL(68, 1446, 23), // "on_PBLightColor_clicked"
QT_MOC_LITERAL(69, 1470, 17), // "GetVertexesAmount"
QT_MOC_LITERAL(70, 1488, 6), // "amount"
QT_MOC_LITERAL(71, 1495, 15), // "GetFacetsAmount"
QT_MOC_LITERAL(72, 1511, 18), // "SavePictureViaType"
QT_MOC_LITERAL(73, 1530, 4), // "type"
QT_MOC_LITERAL(74, 1535, 25), // "GetSettingsFromController"
QT_MOC_LITERAL(75, 1561, 11), // "Settings_t*"
QT_MOC_LITERAL(76, 1573, 4) // "set_"

    },
    "MainWindow\0SendMainWindowSizeChanged\0"
    "\0SendFileName\0char*\0SendSceneColor\0"
    "SendLineColor\0SendVertexColor\0"
    "SendFacetsColor\0SendLightColor\0"
    "SendLineWidth\0SendVertexSize\0"
    "SendVertexType\0SendPerspectStatus\0"
    "SendFacetsStatus\0SendDashLineSignal\0"
    "SendSavePictureSignal\0SendNormalGuroSignal\0"
    "SendRequestForSettings\0"
    "SendRequestForSavedSettings\0"
    "SendSaveSettingsSignal\0"
    "on_MainWindow_iconSizeChanged\0iconSize\0"
    "on_InputObject_2_clicked\0on_PBDraw_2_clicked\0"
    "on_SBLineWidth_valueChanged\0arg1\0"
    "on_SBVertexSize_valueChanged\0"
    "on_CBVertexType_currentTextChanged\0"
    "on_CBPerspective_toggled\0checked\0"
    "on_CBFacets_toggled\0on_CBDashLine_toggled\0"
    "on_PBToZero_clicked\0on_PBJpgPhoto_clicked\0"
    "on_PBBmpPhoto_clicked\0on_PBGifMovie_clicked\0"
    "on_PByRotGif_clicked\0on_xSlider_valueChanged\0"
    "value\0on_ySlider_valueChanged\0"
    "on_zSlider_valueChanged\0"
    "on_MultipSlider_valueChanged\0"
    "on_xMoveSlider_valueChanged\0"
    "on_yMoveSlider_valueChanged\0"
    "on_zMoveSlider_valueChanged\0"
    "on_SBxRot_valueChanged\0on_SByRot_valueChanged\0"
    "on_SBzRot_valueChanged\0on_DSBMultip_valueChanged\0"
    "on_DSBxMove_valueChanged\0"
    "on_DSByMove_valueChanged\0"
    "on_DSBzMove_valueChanged\0"
    "on_xLightSlider_valueChanged\0"
    "on_yLightSlider_valueChanged\0"
    "on_DSBxLight_valueChanged\0"
    "on_DSByLight_valueChanged\0"
    "on_CBNormalGuro_toggled\0SetUpColorLablesColor\0"
    "on_ALoadModel_triggered\0"
    "on_ASaveFreeGif_triggered\0"
    "on_ASaveYRotGif_triggered\0"
    "on_ASaveJpg_triggered\0on_ASaveBmp_triggered\0"
    "on_PBSceneColor_clicked\0on_PBLineColor_clicked\0"
    "on_PBVertexColor_clicked\0"
    "on_PBFacetsColor_clicked\0"
    "on_PBLightColor_clicked\0GetVertexesAmount\0"
    "amount\0GetFacetsAmount\0SavePictureViaType\0"
    "type\0GetSettingsFromController\0"
    "Settings_t*\0set_"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      66,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      18,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  344,    2, 0x06 /* Public */,
       3,    1,  347,    2, 0x06 /* Public */,
       5,    1,  350,    2, 0x06 /* Public */,
       6,    1,  353,    2, 0x06 /* Public */,
       7,    1,  356,    2, 0x06 /* Public */,
       8,    1,  359,    2, 0x06 /* Public */,
       9,    1,  362,    2, 0x06 /* Public */,
      10,    1,  365,    2, 0x06 /* Public */,
      11,    1,  368,    2, 0x06 /* Public */,
      12,    1,  371,    2, 0x06 /* Public */,
      13,    1,  374,    2, 0x06 /* Public */,
      14,    1,  377,    2, 0x06 /* Public */,
      15,    1,  380,    2, 0x06 /* Public */,
      16,    2,  383,    2, 0x06 /* Public */,
      17,    1,  388,    2, 0x06 /* Public */,
      18,    0,  391,    2, 0x06 /* Public */,
      19,    0,  392,    2, 0x06 /* Public */,
      20,    0,  393,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      21,    1,  394,    2, 0x08 /* Private */,
      23,    0,  397,    2, 0x08 /* Private */,
      24,    0,  398,    2, 0x08 /* Private */,
      25,    1,  399,    2, 0x08 /* Private */,
      27,    1,  402,    2, 0x08 /* Private */,
      28,    1,  405,    2, 0x08 /* Private */,
      29,    1,  408,    2, 0x08 /* Private */,
      31,    1,  411,    2, 0x08 /* Private */,
      32,    1,  414,    2, 0x08 /* Private */,
      33,    0,  417,    2, 0x08 /* Private */,
      34,    0,  418,    2, 0x08 /* Private */,
      35,    0,  419,    2, 0x08 /* Private */,
      36,    0,  420,    2, 0x08 /* Private */,
      37,    0,  421,    2, 0x08 /* Private */,
      38,    1,  422,    2, 0x08 /* Private */,
      40,    1,  425,    2, 0x08 /* Private */,
      41,    1,  428,    2, 0x08 /* Private */,
      42,    1,  431,    2, 0x08 /* Private */,
      43,    1,  434,    2, 0x08 /* Private */,
      44,    1,  437,    2, 0x08 /* Private */,
      45,    1,  440,    2, 0x08 /* Private */,
      46,    1,  443,    2, 0x08 /* Private */,
      47,    1,  446,    2, 0x08 /* Private */,
      48,    1,  449,    2, 0x08 /* Private */,
      49,    1,  452,    2, 0x08 /* Private */,
      50,    1,  455,    2, 0x08 /* Private */,
      51,    1,  458,    2, 0x08 /* Private */,
      52,    1,  461,    2, 0x08 /* Private */,
      53,    1,  464,    2, 0x08 /* Private */,
      54,    1,  467,    2, 0x08 /* Private */,
      55,    1,  470,    2, 0x08 /* Private */,
      56,    1,  473,    2, 0x08 /* Private */,
      57,    1,  476,    2, 0x08 /* Private */,
      58,    0,  479,    2, 0x08 /* Private */,
      59,    0,  480,    2, 0x08 /* Private */,
      60,    0,  481,    2, 0x08 /* Private */,
      61,    0,  482,    2, 0x08 /* Private */,
      62,    0,  483,    2, 0x08 /* Private */,
      63,    0,  484,    2, 0x08 /* Private */,
      64,    0,  485,    2, 0x08 /* Private */,
      65,    0,  486,    2, 0x08 /* Private */,
      66,    0,  487,    2, 0x08 /* Private */,
      67,    0,  488,    2, 0x08 /* Private */,
      68,    0,  489,    2, 0x08 /* Private */,
      69,    1,  490,    2, 0x0a /* Public */,
      71,    1,  493,    2, 0x0a /* Public */,
      72,    1,  496,    2, 0x0a /* Public */,
      74,    1,  499,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QSize,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QSize,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Double,   26,
    QMetaType::Void, QMetaType::Double,   26,
    QMetaType::Void, QMetaType::Double,   26,
    QMetaType::Void, QMetaType::Double,   26,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, QMetaType::Double,   26,
    QMetaType::Void, QMetaType::Double,   26,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   70,
    QMetaType::Void, QMetaType::Int,   70,
    QMetaType::Void, QMetaType::Int,   73,
    QMetaType::Void, 0x80000000 | 75,   76,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendMainWindowSizeChanged((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 1: _t->SendFileName((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 2: _t->SendSceneColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 3: _t->SendLineColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 4: _t->SendVertexColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 5: _t->SendFacetsColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 6: _t->SendLightColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 7: _t->SendLineWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->SendVertexSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->SendVertexType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->SendPerspectStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->SendFacetsStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->SendDashLineSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->SendSavePictureSignal((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->SendNormalGuroSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->SendRequestForSettings(); break;
        case 16: _t->SendRequestForSavedSettings(); break;
        case 17: _t->SendSaveSettingsSignal(); break;
        case 18: _t->on_MainWindow_iconSizeChanged((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 19: _t->on_InputObject_2_clicked(); break;
        case 20: _t->on_PBDraw_2_clicked(); break;
        case 21: _t->on_SBLineWidth_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_SBVertexSize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->on_CBVertexType_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 24: _t->on_CBPerspective_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->on_CBFacets_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->on_CBDashLine_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->on_PBToZero_clicked(); break;
        case 28: _t->on_PBJpgPhoto_clicked(); break;
        case 29: _t->on_PBBmpPhoto_clicked(); break;
        case 30: _t->on_PBGifMovie_clicked(); break;
        case 31: _t->on_PByRotGif_clicked(); break;
        case 32: _t->on_xSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->on_ySlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->on_zSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->on_MultipSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->on_xMoveSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->on_yMoveSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->on_zMoveSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->on_SBxRot_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->on_SByRot_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->on_SBzRot_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->on_DSBMultip_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 43: _t->on_DSBxMove_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 44: _t->on_DSByMove_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 45: _t->on_DSBzMove_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 46: _t->on_xLightSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 47: _t->on_yLightSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 48: _t->on_DSBxLight_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 49: _t->on_DSByLight_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 50: _t->on_CBNormalGuro_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 51: _t->SetUpColorLablesColor(); break;
        case 52: _t->on_ALoadModel_triggered(); break;
        case 53: _t->on_ASaveFreeGif_triggered(); break;
        case 54: _t->on_ASaveYRotGif_triggered(); break;
        case 55: _t->on_ASaveJpg_triggered(); break;
        case 56: _t->on_ASaveBmp_triggered(); break;
        case 57: _t->on_PBSceneColor_clicked(); break;
        case 58: _t->on_PBLineColor_clicked(); break;
        case 59: _t->on_PBVertexColor_clicked(); break;
        case 60: _t->on_PBFacetsColor_clicked(); break;
        case 61: _t->on_PBLightColor_clicked(); break;
        case 62: _t->GetVertexesAmount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 63: _t->GetFacetsAmount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 64: _t->SavePictureViaType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 65: _t->GetSettingsFromController((*reinterpret_cast< Settings_t*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(const QSize );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendMainWindowSizeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendFileName)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendSceneColor)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendLineColor)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendVertexColor)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendFacetsColor)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendLightColor)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendLineWidth)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendVertexSize)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendVertexType)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendPerspectStatus)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendFacetsStatus)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendDashLineSignal)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(char * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendSavePictureSignal)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendNormalGuroSignal)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendRequestForSettings)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendRequestForSavedSettings)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendSaveSettingsSignal)) {
                *result = 17;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 66)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 66;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 66)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 66;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::SendMainWindowSizeChanged(const QSize _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::SendFileName(char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::SendSceneColor(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::SendLineColor(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::SendVertexColor(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::SendFacetsColor(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::SendLightColor(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::SendLineWidth(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::SendVertexSize(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::SendVertexType(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MainWindow::SendPerspectStatus(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void MainWindow::SendFacetsStatus(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void MainWindow::SendDashLineSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void MainWindow::SendSavePictureSignal(char * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void MainWindow::SendNormalGuroSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void MainWindow::SendRequestForSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void MainWindow::SendRequestForSavedSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void MainWindow::SendSaveSettingsSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
