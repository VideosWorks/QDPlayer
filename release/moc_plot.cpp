/****************************************************************************
** Meta object code from reading C++ file 'plot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../plot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Plot_t {
    QByteArrayData data[17];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Plot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Plot_t qt_meta_stringdata_Plot = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Plot"
QT_MOC_LITERAL(1, 5, 13), // "applySettings"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 4), // "date"
QT_MOC_LITERAL(4, 25, 5), // "paint"
QT_MOC_LITERAL(5, 31, 5), // "date1"
QT_MOC_LITERAL(6, 37, 5), // "date2"
QT_MOC_LITERAL(7, 43, 5), // "point"
QT_MOC_LITERAL(8, 49, 6), // "camera"
QT_MOC_LITERAL(9, 56, 11), // "first_paint"
QT_MOC_LITERAL(10, 68, 15), // "mousePressEvent"
QT_MOC_LITERAL(11, 84, 12), // "QMouseEvent*"
QT_MOC_LITERAL(12, 97, 5), // "event"
QT_MOC_LITERAL(13, 103, 10), // "wheelEvent"
QT_MOC_LITERAL(14, 114, 12), // "QWheelEvent*"
QT_MOC_LITERAL(15, 127, 11), // "convertdate"
QT_MOC_LITERAL(16, 139, 5) // "value"

    },
    "Plot\0applySettings\0\0date\0paint\0date1\0"
    "date2\0point\0camera\0first_paint\0"
    "mousePressEvent\0QMouseEvent*\0event\0"
    "wheelEvent\0QWheelEvent*\0convertdate\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Plot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    4,   47,    2, 0x0a /* Public */,
       9,    3,   56,    2, 0x0a /* Public */,
      10,    1,   63,    2, 0x0a /* Public */,
      13,    1,   66,    2, 0x0a /* Public */,
      15,    2,   69,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QDate,    3,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime, QMetaType::Int, QMetaType::Int,    5,    6,    7,    8,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime, QMetaType::Int,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   12,
    QMetaType::QDateTime, QMetaType::QDate, QMetaType::Int,    3,   16,

       0        // eod
};

void Plot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Plot *_t = static_cast<Plot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->applySettings((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 1: _t->paint((*reinterpret_cast< QDateTime(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->first_paint((*reinterpret_cast< QDateTime(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->wheelEvent((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 5: { QDateTime _r = _t->convertdate((*reinterpret_cast< QDate(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDateTime*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Plot::staticMetaObject = {
    { &QwtPlot::staticMetaObject, qt_meta_stringdata_Plot.data,
      qt_meta_data_Plot,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Plot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Plot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Plot.stringdata0))
        return static_cast<void*>(this);
    return QwtPlot::qt_metacast(_clname);
}

int Plot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
