/****************************************************************************
** Meta object code from reading C++ file 'arena.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FollowAndDrop/arena.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'arena.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Arena_t {
    QByteArrayData data[9];
    char stringdata[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Arena_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Arena_t qt_meta_stringdata_Arena = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Arena"
QT_MOC_LITERAL(1, 6, 16), // "xRotationChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "angle"
QT_MOC_LITERAL(4, 30, 16), // "yRotationChanged"
QT_MOC_LITERAL(5, 47, 16), // "zRotationChanged"
QT_MOC_LITERAL(6, 64, 12), // "setYRotation"
QT_MOC_LITERAL(7, 77, 12), // "setZRotation"
QT_MOC_LITERAL(8, 90, 12) // "setXRotation"

    },
    "Arena\0xRotationChanged\0\0angle\0"
    "yRotationChanged\0zRotationChanged\0"
    "setYRotation\0setZRotation\0setXRotation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Arena[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       5,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   53,    2, 0x0a /* Public */,
       7,    1,   56,    2, 0x0a /* Public */,
       8,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void Arena::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Arena *_t = static_cast<Arena *>(_o);
        switch (_id) {
        case 0: _t->xRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->yRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->zRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setYRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setZRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setXRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Arena::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Arena::xRotationChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (Arena::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Arena::yRotationChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (Arena::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Arena::zRotationChanged)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Arena::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_Arena.data,
      qt_meta_data_Arena,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Arena::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Arena::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Arena.stringdata))
        return static_cast<void*>(const_cast< Arena*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int Arena::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Arena::xRotationChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Arena::yRotationChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Arena::zRotationChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
