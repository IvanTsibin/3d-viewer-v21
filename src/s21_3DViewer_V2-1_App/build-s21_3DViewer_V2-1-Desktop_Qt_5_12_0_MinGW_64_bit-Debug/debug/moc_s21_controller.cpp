/****************************************************************************
** Meta object code from reading C++ file 's21_controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../s21_3DViewer_V2-1/s21_controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 's21_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[63];
    char stringdata0[838];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Controller"
QT_MOC_LITERAL(1, 11, 22), // "SendSettingsToGLWidget"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 11), // "Settings_t*"
QT_MOC_LITERAL(4, 47, 16), // "XRotationChanged"
QT_MOC_LITERAL(5, 64, 5), // "angle"
QT_MOC_LITERAL(6, 70, 16), // "YRotationChanged"
QT_MOC_LITERAL(7, 87, 16), // "ZRotationChanged"
QT_MOC_LITERAL(8, 104, 13), // "MultipChanged"
QT_MOC_LITERAL(9, 118, 6), // "multip"
QT_MOC_LITERAL(10, 125, 21), // "SendSavePictureSignal"
QT_MOC_LITERAL(11, 147, 6), // "char[]"
QT_MOC_LITERAL(12, 154, 3), // "str"
QT_MOC_LITERAL(13, 158, 4), // "type"
QT_MOC_LITERAL(14, 163, 6), // "aspect"
QT_MOC_LITERAL(15, 170, 10), // "gifCounter"
QT_MOC_LITERAL(16, 181, 24), // "SendSettingsToMainWindow"
QT_MOC_LITERAL(17, 206, 27), // "SendLablesColorChangeSignal"
QT_MOC_LITERAL(18, 234, 32), // "SettingsFromGLWidgetToController"
QT_MOC_LITERAL(19, 267, 15), // "GetFacetsStatus"
QT_MOC_LITERAL(20, 283, 7), // "checked"
QT_MOC_LITERAL(21, 291, 12), // "SetXRotation"
QT_MOC_LITERAL(22, 304, 12), // "SetYRotation"
QT_MOC_LITERAL(23, 317, 12), // "SetZRotation"
QT_MOC_LITERAL(24, 330, 9), // "SetMultip"
QT_MOC_LITERAL(25, 340, 8), // "SetXMove"
QT_MOC_LITERAL(26, 349, 6), // "x_move"
QT_MOC_LITERAL(27, 356, 8), // "SetYMove"
QT_MOC_LITERAL(28, 365, 6), // "y_move"
QT_MOC_LITERAL(29, 372, 8), // "SetZMove"
QT_MOC_LITERAL(30, 381, 6), // "z_move"
QT_MOC_LITERAL(31, 388, 9), // "SetXLight"
QT_MOC_LITERAL(32, 398, 7), // "x_light"
QT_MOC_LITERAL(33, 406, 9), // "SetYLight"
QT_MOC_LITERAL(34, 416, 7), // "y_light"
QT_MOC_LITERAL(35, 424, 13), // "SetSceneColor"
QT_MOC_LITERAL(36, 438, 10), // "SceneColor"
QT_MOC_LITERAL(37, 449, 12), // "SetLineColor"
QT_MOC_LITERAL(38, 462, 9), // "LineColor"
QT_MOC_LITERAL(39, 472, 14), // "SetVertexColor"
QT_MOC_LITERAL(40, 487, 11), // "VertexColor"
QT_MOC_LITERAL(41, 499, 14), // "SetFacetsColor"
QT_MOC_LITERAL(42, 514, 11), // "FacetsColor"
QT_MOC_LITERAL(43, 526, 13), // "SetLightColor"
QT_MOC_LITERAL(44, 540, 10), // "LightColor"
QT_MOC_LITERAL(45, 551, 12), // "SetLineWidth"
QT_MOC_LITERAL(46, 564, 9), // "LineWidth"
QT_MOC_LITERAL(47, 574, 13), // "SetVertexSize"
QT_MOC_LITERAL(48, 588, 10), // "VertexSize"
QT_MOC_LITERAL(49, 599, 13), // "SetVertexType"
QT_MOC_LITERAL(50, 613, 10), // "VertexType"
QT_MOC_LITERAL(51, 624, 20), // "SetPerspectiveStatus"
QT_MOC_LITERAL(52, 645, 17), // "PerspectiveStatus"
QT_MOC_LITERAL(53, 663, 15), // "SetFacetsStatus"
QT_MOC_LITERAL(54, 679, 12), // "FacetsStatus"
QT_MOC_LITERAL(55, 692, 17), // "SetDashLineSignal"
QT_MOC_LITERAL(56, 710, 6), // "signal"
QT_MOC_LITERAL(57, 717, 12), // "SaveStartPos"
QT_MOC_LITERAL(58, 730, 20), // "GetSavePictureSignal"
QT_MOC_LITERAL(59, 751, 20), // "GetSaveYRotGifSignal"
QT_MOC_LITERAL(60, 772, 19), // "GetNormalGuroSignal"
QT_MOC_LITERAL(61, 792, 32), // "RequestFromMainWindowForSettings"
QT_MOC_LITERAL(62, 825, 12) // "ReadStartPos"

    },
    "Controller\0SendSettingsToGLWidget\0\0"
    "Settings_t*\0XRotationChanged\0angle\0"
    "YRotationChanged\0ZRotationChanged\0"
    "MultipChanged\0multip\0SendSavePictureSignal\0"
    "char[]\0str\0type\0aspect\0gifCounter\0"
    "SendSettingsToMainWindow\0"
    "SendLablesColorChangeSignal\0"
    "SettingsFromGLWidgetToController\0"
    "GetFacetsStatus\0checked\0SetXRotation\0"
    "SetYRotation\0SetZRotation\0SetMultip\0"
    "SetXMove\0x_move\0SetYMove\0y_move\0"
    "SetZMove\0z_move\0SetXLight\0x_light\0"
    "SetYLight\0y_light\0SetSceneColor\0"
    "SceneColor\0SetLineColor\0LineColor\0"
    "SetVertexColor\0VertexColor\0SetFacetsColor\0"
    "FacetsColor\0SetLightColor\0LightColor\0"
    "SetLineWidth\0LineWidth\0SetVertexSize\0"
    "VertexSize\0SetVertexType\0VertexType\0"
    "SetPerspectiveStatus\0PerspectiveStatus\0"
    "SetFacetsStatus\0FacetsStatus\0"
    "SetDashLineSignal\0signal\0SaveStartPos\0"
    "GetSavePictureSignal\0GetSaveYRotGifSignal\0"
    "GetNormalGuroSignal\0"
    "RequestFromMainWindowForSettings\0"
    "ReadStartPos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  194,    2, 0x06 /* Public */,
       4,    1,  197,    2, 0x06 /* Public */,
       6,    1,  200,    2, 0x06 /* Public */,
       7,    1,  203,    2, 0x06 /* Public */,
       8,    1,  206,    2, 0x06 /* Public */,
      10,    4,  209,    2, 0x06 /* Public */,
      16,    1,  218,    2, 0x06 /* Public */,
      17,    0,  221,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    1,  222,    2, 0x0a /* Public */,
      19,    1,  225,    2, 0x0a /* Public */,
      21,    1,  228,    2, 0x0a /* Public */,
      22,    1,  231,    2, 0x0a /* Public */,
      23,    1,  234,    2, 0x0a /* Public */,
      24,    1,  237,    2, 0x0a /* Public */,
      25,    1,  240,    2, 0x0a /* Public */,
      27,    1,  243,    2, 0x0a /* Public */,
      29,    1,  246,    2, 0x0a /* Public */,
      31,    1,  249,    2, 0x0a /* Public */,
      33,    1,  252,    2, 0x0a /* Public */,
      35,    1,  255,    2, 0x0a /* Public */,
      37,    1,  258,    2, 0x0a /* Public */,
      39,    1,  261,    2, 0x0a /* Public */,
      41,    1,  264,    2, 0x0a /* Public */,
      43,    1,  267,    2, 0x0a /* Public */,
      45,    1,  270,    2, 0x0a /* Public */,
      47,    1,  273,    2, 0x0a /* Public */,
      49,    1,  276,    2, 0x0a /* Public */,
      51,    1,  279,    2, 0x0a /* Public */,
      53,    1,  282,    2, 0x0a /* Public */,
      55,    1,  285,    2, 0x0a /* Public */,
      57,    0,  288,    2, 0x0a /* Public */,
      58,    2,  289,    2, 0x0a /* Public */,
      59,    0,  294,    2, 0x0a /* Public */,
      60,    1,  295,    2, 0x0a /* Public */,
      61,    0,  298,    2, 0x0a /* Public */,
      62,    0,  299,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int, QMetaType::Float, QMetaType::Int,   12,   13,   14,   15,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void, QMetaType::QColor,   36,
    QMetaType::Void, QMetaType::QColor,   38,
    QMetaType::Void, QMetaType::QColor,   40,
    QMetaType::Void, QMetaType::QColor,   42,
    QMetaType::Void, QMetaType::QColor,   44,
    QMetaType::Void, QMetaType::Int,   46,
    QMetaType::Void, QMetaType::Int,   48,
    QMetaType::Void, QMetaType::Int,   50,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   54,
    QMetaType::Void, QMetaType::Int,   56,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,   12,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   56,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Controller *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendSettingsToGLWidget((*reinterpret_cast< Settings_t*(*)>(_a[1]))); break;
        case 1: _t->XRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->YRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ZRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->MultipChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->SendSavePictureSignal((*reinterpret_cast< char(*)[]>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 6: _t->SendSettingsToMainWindow((*reinterpret_cast< Settings_t*(*)>(_a[1]))); break;
        case 7: _t->SendLablesColorChangeSignal(); break;
        case 8: _t->SettingsFromGLWidgetToController((*reinterpret_cast< Settings_t*(*)>(_a[1]))); break;
        case 9: _t->GetFacetsStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->SetXRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->SetYRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->SetZRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->SetMultip((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->SetXMove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->SetYMove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->SetZMove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->SetXLight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->SetYLight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->SetSceneColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 20: _t->SetLineColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 21: _t->SetVertexColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 22: _t->SetFacetsColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 23: _t->SetLightColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 24: _t->SetLineWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->SetVertexSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->SetVertexType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->SetPerspectiveStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->SetFacetsStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->SetDashLineSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->SaveStartPos(); break;
        case 31: _t->GetSavePictureSignal((*reinterpret_cast< char(*)[]>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 32: _t->GetSaveYRotGifSignal(); break;
        case 33: _t->GetNormalGuroSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->RequestFromMainWindowForSettings(); break;
        case 35: _t->ReadStartPos(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Controller::*)(Settings_t * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::SendSettingsToGLWidget)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Controller::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::XRotationChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Controller::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::YRotationChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Controller::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::ZRotationChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Controller::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::MultipChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Controller::*)(char [], int , float , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::SendSavePictureSignal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Controller::*)(Settings_t * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::SendSettingsToMainWindow)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::SendLablesColorChangeSignal)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Controller::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Controller.data,
    qt_meta_data_Controller,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 36)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 36;
    }
    return _id;
}

// SIGNAL 0
void Controller::SendSettingsToGLWidget(Settings_t * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Controller::XRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Controller::YRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Controller::ZRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Controller::MultipChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Controller::SendSavePictureSignal(char _t1[], int _t2, float _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Controller::SendSettingsToMainWindow(Settings_t * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Controller::SendLablesColorChangeSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
