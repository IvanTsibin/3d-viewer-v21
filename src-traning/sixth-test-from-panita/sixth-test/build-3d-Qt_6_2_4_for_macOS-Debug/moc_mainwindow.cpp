/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../3d/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[38];
    char stringdata0[442];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 37), // "on_BackgroundColor_currentTex..."
QT_MOC_LITERAL(49, 0), // ""
QT_MOC_LITERAL(50, 4), // "arg1"
QT_MOC_LITERAL(55, 24), // "on_EdgeSize_valueChanged"
QT_MOC_LITERAL(80, 39), // "on_BackgroundColor_3_currentT..."
QT_MOC_LITERAL(120, 27), // "on_VerticeSize_valueChanged"
QT_MOC_LITERAL(148, 39), // "on_BackgroundColor_4_currentT..."
QT_MOC_LITERAL(188, 21), // "on_CleanColor_clicked"
QT_MOC_LITERAL(210, 21), // "on_ChooseFile_clicked"
QT_MOC_LITERAL(232, 30), // "on_EdgeType_currentTextChanged"
QT_MOC_LITERAL(263, 33), // "on_VerticeType_currentTextCha..."
QT_MOC_LITERAL(297, 21), // "on_Screenshot_clicked"
QT_MOC_LITERAL(319, 23), // "on_Screenshot_2_clicked"
QT_MOC_LITERAL(343, 14), // "on_Gif_clicked"
QT_MOC_LITERAL(358, 25), // "on_XMovement_valueChanged"
QT_MOC_LITERAL(384, 5), // "value"
QT_MOC_LITERAL(390, 25), // "on_YMovement_valueChanged"
QT_MOC_LITERAL(416, 25) // "on_ZMovement_valueChanged"

    },
    "MainWindow\0on_BackgroundColor_currentTextChanged\0"
    "\0arg1\0on_EdgeSize_valueChanged\0"
    "on_BackgroundColor_3_currentTextChanged\0"
    "on_VerticeSize_valueChanged\0"
    "on_BackgroundColor_4_currentTextChanged\0"
    "on_CleanColor_clicked\0on_ChooseFile_clicked\0"
    "on_EdgeType_currentTextChanged\0"
    "on_VerticeType_currentTextChanged\0"
    "on_Screenshot_clicked\0on_Screenshot_2_clicked\0"
    "on_Gif_clicked\0on_XMovement_valueChanged\0"
    "value\0on_YMovement_valueChanged\0"
    "on_ZMovement_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x08,    1 /* Private */,
       4,    1,  107,    2, 0x08,    3 /* Private */,
       5,    1,  110,    2, 0x08,    5 /* Private */,
       6,    1,  113,    2, 0x08,    7 /* Private */,
       7,    1,  116,    2, 0x08,    9 /* Private */,
       8,    0,  119,    2, 0x08,   11 /* Private */,
       9,    0,  120,    2, 0x08,   12 /* Private */,
      10,    1,  121,    2, 0x08,   13 /* Private */,
      11,    1,  124,    2, 0x08,   15 /* Private */,
      12,    0,  127,    2, 0x08,   17 /* Private */,
      13,    0,  128,    2, 0x08,   18 /* Private */,
      14,    0,  129,    2, 0x08,   19 /* Private */,
      15,    1,  130,    2, 0x08,   20 /* Private */,
      17,    1,  133,    2, 0x08,   22 /* Private */,
      18,    1,  136,    2, 0x08,   24 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_BackgroundColor_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->on_EdgeSize_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 2: _t->on_BackgroundColor_3_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->on_VerticeSize_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 4: _t->on_BackgroundColor_4_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->on_CleanColor_clicked(); break;
        case 6: _t->on_ChooseFile_clicked(); break;
        case 7: _t->on_EdgeType_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->on_VerticeType_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->on_Screenshot_clicked(); break;
        case 10: _t->on_Screenshot_2_clicked(); break;
        case 11: _t->on_Gif_clicked(); break;
        case 12: _t->on_XMovement_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->on_YMovement_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->on_ZMovement_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
