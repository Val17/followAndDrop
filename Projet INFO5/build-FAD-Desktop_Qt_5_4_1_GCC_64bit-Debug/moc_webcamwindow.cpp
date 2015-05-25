/****************************************************************************
** Meta object code from reading C++ file 'webcamwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FAD/webcamwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'webcamwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WebCamWindow_t {
    QByteArrayData data[7];
    char stringdata[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WebCamWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WebCamWindow_t qt_meta_stringdata_WebCamWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "WebCamWindow"
QT_MOC_LITERAL(1, 13, 9), // "emitPoint"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "cv::Point"
QT_MOC_LITERAL(4, 34, 9), // "handPoint"
QT_MOC_LITERAL(5, 44, 6), // "aquire"
QT_MOC_LITERAL(6, 51, 11) // "startWebCam"

    },
    "WebCamWindow\0emitPoint\0\0cv::Point\0"
    "handPoint\0aquire\0startWebCam"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WebCamWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   32,    2, 0x08 /* Private */,
       6,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WebCamWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WebCamWindow *_t = static_cast<WebCamWindow *>(_o);
        switch (_id) {
        case 0: _t->emitPoint((*reinterpret_cast< cv::Point(*)>(_a[1]))); break;
        case 1: _t->aquire(); break;
        case 2: _t->startWebCam(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WebCamWindow::*_t)(cv::Point );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebCamWindow::emitPoint)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject WebCamWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WebCamWindow.data,
      qt_meta_data_WebCamWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WebCamWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebCamWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WebCamWindow.stringdata))
        return static_cast<void*>(const_cast< WebCamWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int WebCamWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void WebCamWindow::emitPoint(cv::Point _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
