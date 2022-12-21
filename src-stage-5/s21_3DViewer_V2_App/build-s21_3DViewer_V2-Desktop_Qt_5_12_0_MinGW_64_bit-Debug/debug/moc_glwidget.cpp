/****************************************************************************
** Meta object code from reading C++ file 'glwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../s21_3DViewer_V2/glwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GLWidget_t {
    QByteArrayData data[75];
    char stringdata0[1069];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GLWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GLWidget_t qt_meta_stringdata_GLWidget = {
    {
QT_MOC_LITERAL(0, 0, 8), // "GLWidget"
QT_MOC_LITERAL(1, 9, 16), // "xRotationChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "angle"
QT_MOC_LITERAL(4, 33, 16), // "yRotationChanged"
QT_MOC_LITERAL(5, 50, 16), // "zRotationChanged"
QT_MOC_LITERAL(6, 67, 12), // "xMoveChanged"
QT_MOC_LITERAL(7, 80, 6), // "x_move"
QT_MOC_LITERAL(8, 87, 12), // "yMoveChanged"
QT_MOC_LITERAL(9, 100, 6), // "y_move"
QT_MOC_LITERAL(10, 107, 12), // "zMoveChanged"
QT_MOC_LITERAL(11, 120, 6), // "z_move"
QT_MOC_LITERAL(12, 127, 13), // "multipChanged"
QT_MOC_LITERAL(13, 141, 6), // "multip"
QT_MOC_LITERAL(14, 148, 20), // "send_vertexes_amount"
QT_MOC_LITERAL(15, 169, 18), // "send_facets_amount"
QT_MOC_LITERAL(16, 188, 15), // "RedColorChanged"
QT_MOC_LITERAL(17, 204, 8), // "RedColor"
QT_MOC_LITERAL(18, 213, 17), // "GreenColorChanged"
QT_MOC_LITERAL(19, 231, 10), // "GreenColor"
QT_MOC_LITERAL(20, 242, 16), // "BlueColorChanged"
QT_MOC_LITERAL(21, 259, 9), // "BlueColor"
QT_MOC_LITERAL(22, 269, 19), // "RedColorLineChanged"
QT_MOC_LITERAL(23, 289, 12), // "RedColorLine"
QT_MOC_LITERAL(24, 302, 21), // "GreenColorLineChanged"
QT_MOC_LITERAL(25, 324, 14), // "GreenColorLine"
QT_MOC_LITERAL(26, 339, 20), // "BlueColorLineChanged"
QT_MOC_LITERAL(27, 360, 13), // "BlueColorLine"
QT_MOC_LITERAL(28, 374, 21), // "RedColorVertexChanged"
QT_MOC_LITERAL(29, 396, 14), // "RedColorVertex"
QT_MOC_LITERAL(30, 411, 23), // "GreenColorVertexChanged"
QT_MOC_LITERAL(31, 435, 16), // "GreenColorVertex"
QT_MOC_LITERAL(32, 452, 22), // "BlueColorVertexChanged"
QT_MOC_LITERAL(33, 475, 15), // "BlueColorVertex"
QT_MOC_LITERAL(34, 491, 16), // "LineWidthChanged"
QT_MOC_LITERAL(35, 508, 9), // "LineWidth"
QT_MOC_LITERAL(36, 518, 17), // "VertexSizeChanged"
QT_MOC_LITERAL(37, 536, 10), // "VertexSize"
QT_MOC_LITERAL(38, 547, 17), // "VertexTypeChanged"
QT_MOC_LITERAL(39, 565, 10), // "VertexType"
QT_MOC_LITERAL(40, 576, 17), // "PersectiveChanged"
QT_MOC_LITERAL(41, 594, 17), // "PerspectiveStatus"
QT_MOC_LITERAL(42, 612, 15), // "DashLineChanged"
QT_MOC_LITERAL(43, 628, 8), // "DashLine"
QT_MOC_LITERAL(44, 637, 12), // "setXRotation"
QT_MOC_LITERAL(45, 650, 12), // "setYRotation"
QT_MOC_LITERAL(46, 663, 12), // "setZRotation"
QT_MOC_LITERAL(47, 676, 9), // "setMultip"
QT_MOC_LITERAL(48, 686, 8), // "setXMove"
QT_MOC_LITERAL(49, 695, 8), // "setYMove"
QT_MOC_LITERAL(50, 704, 8), // "setZMove"
QT_MOC_LITERAL(51, 713, 7), // "cleanup"
QT_MOC_LITERAL(52, 721, 28), // "get_main_window_size_changed"
QT_MOC_LITERAL(53, 750, 8), // "iconSize"
QT_MOC_LITERAL(54, 759, 13), // "get_file_name"
QT_MOC_LITERAL(55, 773, 6), // "char[]"
QT_MOC_LITERAL(56, 780, 3), // "str"
QT_MOC_LITERAL(57, 784, 11), // "setRedColor"
QT_MOC_LITERAL(58, 796, 13), // "setGreenColor"
QT_MOC_LITERAL(59, 810, 12), // "setBlueColor"
QT_MOC_LITERAL(60, 823, 15), // "setRedColorLine"
QT_MOC_LITERAL(61, 839, 17), // "setGreenColorLine"
QT_MOC_LITERAL(62, 857, 16), // "setBlueColorLine"
QT_MOC_LITERAL(63, 874, 17), // "setRedColorVertex"
QT_MOC_LITERAL(64, 892, 19), // "setGreenColorVertex"
QT_MOC_LITERAL(65, 912, 18), // "setBlueColorVertex"
QT_MOC_LITERAL(66, 931, 12), // "setLineWidth"
QT_MOC_LITERAL(67, 944, 13), // "setVertexSize"
QT_MOC_LITERAL(68, 958, 13), // "setVertexType"
QT_MOC_LITERAL(69, 972, 20), // "setPerspectiveStatus"
QT_MOC_LITERAL(70, 993, 17), // "setDashLineSignal"
QT_MOC_LITERAL(71, 1011, 6), // "signal"
QT_MOC_LITERAL(72, 1018, 14), // "getSaveJpgFile"
QT_MOC_LITERAL(73, 1033, 14), // "getSaveBmpFile"
QT_MOC_LITERAL(74, 1048, 20) // "getSaveGifFileSignal"

    },
    "GLWidget\0xRotationChanged\0\0angle\0"
    "yRotationChanged\0zRotationChanged\0"
    "xMoveChanged\0x_move\0yMoveChanged\0"
    "y_move\0zMoveChanged\0z_move\0multipChanged\0"
    "multip\0send_vertexes_amount\0"
    "send_facets_amount\0RedColorChanged\0"
    "RedColor\0GreenColorChanged\0GreenColor\0"
    "BlueColorChanged\0BlueColor\0"
    "RedColorLineChanged\0RedColorLine\0"
    "GreenColorLineChanged\0GreenColorLine\0"
    "BlueColorLineChanged\0BlueColorLine\0"
    "RedColorVertexChanged\0RedColorVertex\0"
    "GreenColorVertexChanged\0GreenColorVertex\0"
    "BlueColorVertexChanged\0BlueColorVertex\0"
    "LineWidthChanged\0LineWidth\0VertexSizeChanged\0"
    "VertexSize\0VertexTypeChanged\0VertexType\0"
    "PersectiveChanged\0PerspectiveStatus\0"
    "DashLineChanged\0DashLine\0setXRotation\0"
    "setYRotation\0setZRotation\0setMultip\0"
    "setXMove\0setYMove\0setZMove\0cleanup\0"
    "get_main_window_size_changed\0iconSize\0"
    "get_file_name\0char[]\0str\0setRedColor\0"
    "setGreenColor\0setBlueColor\0setRedColorLine\0"
    "setGreenColorLine\0setBlueColorLine\0"
    "setRedColorVertex\0setGreenColorVertex\0"
    "setBlueColorVertex\0setLineWidth\0"
    "setVertexSize\0setVertexType\0"
    "setPerspectiveStatus\0setDashLineSignal\0"
    "signal\0getSaveJpgFile\0getSaveBmpFile\0"
    "getSaveGifFileSignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GLWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      50,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      23,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  264,    2, 0x06 /* Public */,
       4,    1,  267,    2, 0x06 /* Public */,
       5,    1,  270,    2, 0x06 /* Public */,
       6,    1,  273,    2, 0x06 /* Public */,
       8,    1,  276,    2, 0x06 /* Public */,
      10,    1,  279,    2, 0x06 /* Public */,
      12,    1,  282,    2, 0x06 /* Public */,
      14,    1,  285,    2, 0x06 /* Public */,
      15,    1,  288,    2, 0x06 /* Public */,
      16,    1,  291,    2, 0x06 /* Public */,
      18,    1,  294,    2, 0x06 /* Public */,
      20,    1,  297,    2, 0x06 /* Public */,
      22,    1,  300,    2, 0x06 /* Public */,
      24,    1,  303,    2, 0x06 /* Public */,
      26,    1,  306,    2, 0x06 /* Public */,
      28,    1,  309,    2, 0x06 /* Public */,
      30,    1,  312,    2, 0x06 /* Public */,
      32,    1,  315,    2, 0x06 /* Public */,
      34,    1,  318,    2, 0x06 /* Public */,
      36,    1,  321,    2, 0x06 /* Public */,
      38,    1,  324,    2, 0x06 /* Public */,
      40,    1,  327,    2, 0x06 /* Public */,
      42,    1,  330,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      44,    1,  333,    2, 0x0a /* Public */,
      45,    1,  336,    2, 0x0a /* Public */,
      46,    1,  339,    2, 0x0a /* Public */,
      47,    1,  342,    2, 0x0a /* Public */,
      48,    1,  345,    2, 0x0a /* Public */,
      49,    1,  348,    2, 0x0a /* Public */,
      50,    1,  351,    2, 0x0a /* Public */,
      51,    0,  354,    2, 0x0a /* Public */,
      52,    1,  355,    2, 0x0a /* Public */,
      54,    1,  358,    2, 0x0a /* Public */,
      57,    1,  361,    2, 0x0a /* Public */,
      58,    1,  364,    2, 0x0a /* Public */,
      59,    1,  367,    2, 0x0a /* Public */,
      60,    1,  370,    2, 0x0a /* Public */,
      61,    1,  373,    2, 0x0a /* Public */,
      62,    1,  376,    2, 0x0a /* Public */,
      63,    1,  379,    2, 0x0a /* Public */,
      64,    1,  382,    2, 0x0a /* Public */,
      65,    1,  385,    2, 0x0a /* Public */,
      66,    1,  388,    2, 0x0a /* Public */,
      67,    1,  391,    2, 0x0a /* Public */,
      68,    1,  394,    2, 0x0a /* Public */,
      69,    1,  397,    2, 0x0a /* Public */,
      70,    1,  400,    2, 0x0a /* Public */,
      72,    1,  403,    2, 0x0a /* Public */,
      73,    1,  406,    2, 0x0a /* Public */,
      74,    1,  409,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, QMetaType::Int,   41,
    QMetaType::Void, QMetaType::Int,   43,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QSize,   53,
    QMetaType::Void, 0x80000000 | 55,   56,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, QMetaType::Int,   41,
    QMetaType::Void, QMetaType::Int,   71,
    QMetaType::Void, 0x80000000 | 55,   56,
    QMetaType::Void, 0x80000000 | 55,   56,
    QMetaType::Void, 0x80000000 | 55,   56,

       0        // eod
};

void GLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GLWidget *_t = static_cast<GLWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->xRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->yRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->zRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->xMoveChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->yMoveChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->zMoveChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->multipChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->send_vertexes_amount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->send_facets_amount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->RedColorChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->GreenColorChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->BlueColorChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->RedColorLineChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->GreenColorLineChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->BlueColorLineChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->RedColorVertexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->GreenColorVertexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->BlueColorVertexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->LineWidthChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->VertexSizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->VertexTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->PersectiveChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->DashLineChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->setXRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->setYRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->setZRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->setMultip((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->setXMove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->setYMove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->setZMove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->cleanup(); break;
        case 31: _t->get_main_window_size_changed((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 32: _t->get_file_name((*reinterpret_cast< char(*)[]>(_a[1]))); break;
        case 33: _t->setRedColor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->setGreenColor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->setBlueColor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->setRedColorLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->setGreenColorLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->setBlueColorLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->setRedColorVertex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->setGreenColorVertex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->setBlueColorVertex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->setLineWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: _t->setVertexSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: _t->setVertexType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: _t->setPerspectiveStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 46: _t->setDashLineSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 47: _t->getSaveJpgFile((*reinterpret_cast< char(*)[]>(_a[1]))); break;
        case 48: _t->getSaveBmpFile((*reinterpret_cast< char(*)[]>(_a[1]))); break;
        case 49: _t->getSaveGifFileSignal((*reinterpret_cast< char(*)[]>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::xRotationChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::yRotationChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::zRotationChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::xMoveChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::yMoveChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::zMoveChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::multipChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::send_vertexes_amount)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::send_facets_amount)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::RedColorChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::GreenColorChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::BlueColorChanged)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::RedColorLineChanged)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::GreenColorLineChanged)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::BlueColorLineChanged)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::RedColorVertexChanged)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::GreenColorVertexChanged)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::BlueColorVertexChanged)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::LineWidthChanged)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::VertexSizeChanged)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::VertexTypeChanged)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::PersectiveChanged)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::DashLineChanged)) {
                *result = 22;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GLWidget::staticMetaObject = { {
    &QOpenGLWidget::staticMetaObject,
    qt_meta_stringdata_GLWidget.data,
    qt_meta_data_GLWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GLWidget.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QOpenGLFunctions"))
        return static_cast< QOpenGLFunctions*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int GLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 50)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 50;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 50)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 50;
    }
    return _id;
}

// SIGNAL 0
void GLWidget::xRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GLWidget::yRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GLWidget::zRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GLWidget::xMoveChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GLWidget::yMoveChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GLWidget::zMoveChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GLWidget::multipChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void GLWidget::send_vertexes_amount(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void GLWidget::send_facets_amount(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void GLWidget::RedColorChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void GLWidget::GreenColorChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void GLWidget::BlueColorChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void GLWidget::RedColorLineChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void GLWidget::GreenColorLineChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void GLWidget::BlueColorLineChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void GLWidget::RedColorVertexChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void GLWidget::GreenColorVertexChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void GLWidget::BlueColorVertexChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void GLWidget::LineWidthChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void GLWidget::VertexSizeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void GLWidget::VertexTypeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void GLWidget::PersectiveChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void GLWidget::DashLineChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
