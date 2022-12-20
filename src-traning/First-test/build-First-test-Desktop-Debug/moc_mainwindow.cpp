/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../First-test/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[64];
    char stringdata0[1403];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 29), // "send_main_window_size_changed"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 14), // "send_file_name"
QT_MOC_LITERAL(4, 57, 5), // "char*"
QT_MOC_LITERAL(5, 63, 14), // "send_red_color"
QT_MOC_LITERAL(6, 78, 16), // "send_green_color"
QT_MOC_LITERAL(7, 95, 15), // "send_blue_color"
QT_MOC_LITERAL(8, 111, 19), // "send_red_color_line"
QT_MOC_LITERAL(9, 131, 21), // "send_green_color_line"
QT_MOC_LITERAL(10, 153, 20), // "send_blue_color_line"
QT_MOC_LITERAL(11, 174, 21), // "send_red_color_vertex"
QT_MOC_LITERAL(12, 196, 23), // "send_green_color_vertex"
QT_MOC_LITERAL(13, 220, 22), // "send_blue_color_vertex"
QT_MOC_LITERAL(14, 243, 15), // "send_line_width"
QT_MOC_LITERAL(15, 259, 16), // "send_vertex_size"
QT_MOC_LITERAL(16, 276, 16), // "send_vertex_type"
QT_MOC_LITERAL(17, 293, 20), // "send_perspect_status"
QT_MOC_LITERAL(18, 314, 21), // "send_dash_line_signal"
QT_MOC_LITERAL(19, 336, 18), // "send_save_jpg_file"
QT_MOC_LITERAL(20, 355, 18), // "send_save_bmp_file"
QT_MOC_LITERAL(21, 374, 18), // "send_save_gif_file"
QT_MOC_LITERAL(22, 393, 29), // "on_MainWindow_iconSizeChanged"
QT_MOC_LITERAL(23, 423, 8), // "iconSize"
QT_MOC_LITERAL(24, 432, 24), // "on_InputObject_2_clicked"
QT_MOC_LITERAL(25, 457, 19), // "on_PBDraw_2_clicked"
QT_MOC_LITERAL(26, 477, 26), // "on_SBRedColor_valueChanged"
QT_MOC_LITERAL(27, 504, 4), // "arg1"
QT_MOC_LITERAL(28, 509, 28), // "on_SBGreenColor_valueChanged"
QT_MOC_LITERAL(29, 538, 27), // "on_SBBlueColor_valueChanged"
QT_MOC_LITERAL(30, 566, 30), // "on_SBRedColorLine_valueChanged"
QT_MOC_LITERAL(31, 597, 32), // "on_SBGreenColorLine_valueChanged"
QT_MOC_LITERAL(32, 630, 31), // "on_SBBlueColorLine_valueChanged"
QT_MOC_LITERAL(33, 662, 32), // "on_SBRedColorVertex_valueChanged"
QT_MOC_LITERAL(34, 695, 34), // "on_SBGreenColorVertex_valueCh..."
QT_MOC_LITERAL(35, 730, 33), // "on_SBBlueColorVertex_valueCha..."
QT_MOC_LITERAL(36, 764, 27), // "on_SBLineWidth_valueChanged"
QT_MOC_LITERAL(37, 792, 28), // "on_SBVertexSize_valueChanged"
QT_MOC_LITERAL(38, 821, 34), // "on_CBVertexType_currentTextCh..."
QT_MOC_LITERAL(39, 856, 24), // "on_CBPerspective_toggled"
QT_MOC_LITERAL(40, 881, 7), // "checked"
QT_MOC_LITERAL(41, 889, 21), // "on_CBDashLine_toggled"
QT_MOC_LITERAL(42, 911, 19), // "on_PBToZero_clicked"
QT_MOC_LITERAL(43, 931, 21), // "on_PBJpgPhoto_clicked"
QT_MOC_LITERAL(44, 953, 21), // "on_PBBmpPhoto_clicked"
QT_MOC_LITERAL(45, 975, 21), // "on_PBGifMovie_clicked"
QT_MOC_LITERAL(46, 997, 23), // "on_xSlider_valueChanged"
QT_MOC_LITERAL(47, 1021, 5), // "value"
QT_MOC_LITERAL(48, 1027, 23), // "on_ySlider_valueChanged"
QT_MOC_LITERAL(49, 1051, 23), // "on_zSlider_valueChanged"
QT_MOC_LITERAL(50, 1075, 28), // "on_MultipSlider_valueChanged"
QT_MOC_LITERAL(51, 1104, 27), // "on_xMoveSlider_valueChanged"
QT_MOC_LITERAL(52, 1132, 27), // "on_yMoveSlider_valueChanged"
QT_MOC_LITERAL(53, 1160, 27), // "on_zMoveSlider_valueChanged"
QT_MOC_LITERAL(54, 1188, 22), // "on_SBxRot_valueChanged"
QT_MOC_LITERAL(55, 1211, 22), // "on_SByRot_valueChanged"
QT_MOC_LITERAL(56, 1234, 22), // "on_SBzRot_valueChanged"
QT_MOC_LITERAL(57, 1257, 25), // "on_DSBMultip_valueChanged"
QT_MOC_LITERAL(58, 1283, 24), // "on_DSBxMove_valueChanged"
QT_MOC_LITERAL(59, 1308, 24), // "on_DSByMove_valueChanged"
QT_MOC_LITERAL(60, 1333, 24), // "on_DSBzMove_valueChanged"
QT_MOC_LITERAL(61, 1358, 19), // "get_vertexes_amount"
QT_MOC_LITERAL(62, 1378, 6), // "amount"
QT_MOC_LITERAL(63, 1385, 17) // "get_facets_amount"

    },
    "MainWindow\0send_main_window_size_changed\0"
    "\0send_file_name\0char*\0send_red_color\0"
    "send_green_color\0send_blue_color\0"
    "send_red_color_line\0send_green_color_line\0"
    "send_blue_color_line\0send_red_color_vertex\0"
    "send_green_color_vertex\0send_blue_color_vertex\0"
    "send_line_width\0send_vertex_size\0"
    "send_vertex_type\0send_perspect_status\0"
    "send_dash_line_signal\0send_save_jpg_file\0"
    "send_save_bmp_file\0send_save_gif_file\0"
    "on_MainWindow_iconSizeChanged\0iconSize\0"
    "on_InputObject_2_clicked\0on_PBDraw_2_clicked\0"
    "on_SBRedColor_valueChanged\0arg1\0"
    "on_SBGreenColor_valueChanged\0"
    "on_SBBlueColor_valueChanged\0"
    "on_SBRedColorLine_valueChanged\0"
    "on_SBGreenColorLine_valueChanged\0"
    "on_SBBlueColorLine_valueChanged\0"
    "on_SBRedColorVertex_valueChanged\0"
    "on_SBGreenColorVertex_valueChanged\0"
    "on_SBBlueColorVertex_valueChanged\0"
    "on_SBLineWidth_valueChanged\0"
    "on_SBVertexSize_valueChanged\0"
    "on_CBVertexType_currentTextChanged\0"
    "on_CBPerspective_toggled\0checked\0"
    "on_CBDashLine_toggled\0on_PBToZero_clicked\0"
    "on_PBJpgPhoto_clicked\0on_PBBmpPhoto_clicked\0"
    "on_PBGifMovie_clicked\0on_xSlider_valueChanged\0"
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
    "on_DSBzMove_valueChanged\0get_vertexes_amount\0"
    "amount\0get_facets_amount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      56,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      19,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  294,    2, 0x06 /* Public */,
       3,    1,  297,    2, 0x06 /* Public */,
       5,    1,  300,    2, 0x06 /* Public */,
       6,    1,  303,    2, 0x06 /* Public */,
       7,    1,  306,    2, 0x06 /* Public */,
       8,    1,  309,    2, 0x06 /* Public */,
       9,    1,  312,    2, 0x06 /* Public */,
      10,    1,  315,    2, 0x06 /* Public */,
      11,    1,  318,    2, 0x06 /* Public */,
      12,    1,  321,    2, 0x06 /* Public */,
      13,    1,  324,    2, 0x06 /* Public */,
      14,    1,  327,    2, 0x06 /* Public */,
      15,    1,  330,    2, 0x06 /* Public */,
      16,    1,  333,    2, 0x06 /* Public */,
      17,    1,  336,    2, 0x06 /* Public */,
      18,    1,  339,    2, 0x06 /* Public */,
      19,    1,  342,    2, 0x06 /* Public */,
      20,    1,  345,    2, 0x06 /* Public */,
      21,    1,  348,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      22,    1,  351,    2, 0x08 /* Private */,
      24,    0,  354,    2, 0x08 /* Private */,
      25,    0,  355,    2, 0x08 /* Private */,
      26,    1,  356,    2, 0x08 /* Private */,
      28,    1,  359,    2, 0x08 /* Private */,
      29,    1,  362,    2, 0x08 /* Private */,
      30,    1,  365,    2, 0x08 /* Private */,
      31,    1,  368,    2, 0x08 /* Private */,
      32,    1,  371,    2, 0x08 /* Private */,
      33,    1,  374,    2, 0x08 /* Private */,
      34,    1,  377,    2, 0x08 /* Private */,
      35,    1,  380,    2, 0x08 /* Private */,
      36,    1,  383,    2, 0x08 /* Private */,
      37,    1,  386,    2, 0x08 /* Private */,
      38,    1,  389,    2, 0x08 /* Private */,
      39,    1,  392,    2, 0x08 /* Private */,
      41,    1,  395,    2, 0x08 /* Private */,
      42,    0,  398,    2, 0x08 /* Private */,
      43,    0,  399,    2, 0x08 /* Private */,
      44,    0,  400,    2, 0x08 /* Private */,
      45,    0,  401,    2, 0x08 /* Private */,
      46,    1,  402,    2, 0x08 /* Private */,
      48,    1,  405,    2, 0x08 /* Private */,
      49,    1,  408,    2, 0x08 /* Private */,
      50,    1,  411,    2, 0x08 /* Private */,
      51,    1,  414,    2, 0x08 /* Private */,
      52,    1,  417,    2, 0x08 /* Private */,
      53,    1,  420,    2, 0x08 /* Private */,
      54,    1,  423,    2, 0x08 /* Private */,
      55,    1,  426,    2, 0x08 /* Private */,
      56,    1,  429,    2, 0x08 /* Private */,
      57,    1,  432,    2, 0x08 /* Private */,
      58,    1,  435,    2, 0x08 /* Private */,
      59,    1,  438,    2, 0x08 /* Private */,
      60,    1,  441,    2, 0x08 /* Private */,
      61,    1,  444,    2, 0x0a /* Public */,
      63,    1,  447,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QSize,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QSize,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void, QMetaType::Bool,   40,
    QMetaType::Void, QMetaType::Bool,   40,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   47,
    QMetaType::Void, QMetaType::Int,   47,
    QMetaType::Void, QMetaType::Int,   47,
    QMetaType::Void, QMetaType::Int,   47,
    QMetaType::Void, QMetaType::Int,   47,
    QMetaType::Void, QMetaType::Int,   47,
    QMetaType::Void, QMetaType::Int,   47,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::Double,   27,
    QMetaType::Void, QMetaType::Double,   27,
    QMetaType::Void, QMetaType::Double,   27,
    QMetaType::Void, QMetaType::Double,   27,
    QMetaType::Void, QMetaType::Int,   62,
    QMetaType::Void, QMetaType::Int,   62,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_main_window_size_changed((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 1: _t->send_file_name((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 2: _t->send_red_color((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->send_green_color((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->send_blue_color((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->send_red_color_line((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->send_green_color_line((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->send_blue_color_line((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->send_red_color_vertex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->send_green_color_vertex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->send_blue_color_vertex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->send_line_width((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->send_vertex_size((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->send_vertex_type((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->send_perspect_status((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->send_dash_line_signal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->send_save_jpg_file((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 17: _t->send_save_bmp_file((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 18: _t->send_save_gif_file((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 19: _t->on_MainWindow_iconSizeChanged((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 20: _t->on_InputObject_2_clicked(); break;
        case 21: _t->on_PBDraw_2_clicked(); break;
        case 22: _t->on_SBRedColor_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->on_SBGreenColor_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_SBBlueColor_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->on_SBRedColorLine_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_SBGreenColorLine_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->on_SBBlueColorLine_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_SBRedColorVertex_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->on_SBGreenColorVertex_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->on_SBBlueColorVertex_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->on_SBLineWidth_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->on_SBVertexSize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->on_CBVertexType_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 34: _t->on_CBPerspective_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 35: _t->on_CBDashLine_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: _t->on_PBToZero_clicked(); break;
        case 37: _t->on_PBJpgPhoto_clicked(); break;
        case 38: _t->on_PBBmpPhoto_clicked(); break;
        case 39: _t->on_PBGifMovie_clicked(); break;
        case 40: _t->on_xSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->on_ySlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->on_zSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: _t->on_MultipSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: _t->on_xMoveSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: _t->on_yMoveSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 46: _t->on_zMoveSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 47: _t->on_SBxRot_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 48: _t->on_SByRot_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 49: _t->on_SBzRot_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 50: _t->on_DSBMultip_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 51: _t->on_DSBxMove_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 52: _t->on_DSByMove_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 53: _t->on_DSBzMove_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 54: _t->get_vertexes_amount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 55: _t->get_facets_amount((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(const QSize );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_main_window_size_changed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_file_name)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_red_color)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_green_color)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_blue_color)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_red_color_line)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_green_color_line)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_blue_color_line)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_red_color_vertex)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_green_color_vertex)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_blue_color_vertex)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_line_width)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_vertex_size)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_vertex_type)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_perspect_status)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_dash_line_signal)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_save_jpg_file)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_save_bmp_file)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_save_gif_file)) {
                *result = 18;
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
        if (_id < 56)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 56;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 56)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 56;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::send_main_window_size_changed(const QSize _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::send_file_name(char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::send_red_color(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::send_green_color(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::send_blue_color(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::send_red_color_line(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::send_green_color_line(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::send_blue_color_line(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::send_red_color_vertex(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::send_green_color_vertex(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MainWindow::send_blue_color_vertex(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void MainWindow::send_line_width(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void MainWindow::send_vertex_size(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void MainWindow::send_vertex_type(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void MainWindow::send_perspect_status(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void MainWindow::send_dash_line_signal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void MainWindow::send_save_jpg_file(char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void MainWindow::send_save_bmp_file(char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void MainWindow::send_save_gif_file(char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
