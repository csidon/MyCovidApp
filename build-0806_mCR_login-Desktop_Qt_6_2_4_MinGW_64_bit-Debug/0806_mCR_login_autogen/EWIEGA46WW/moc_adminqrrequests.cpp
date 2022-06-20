/****************************************************************************
** Meta object code from reading C++ file 'adminqrrequests.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../0806_mCR_login/adminqrrequests.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminqrrequests.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdminQRRequests_t {
    const uint offsetsAndSize[16];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AdminQRRequests_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AdminQRRequests_t qt_meta_stringdata_AdminQRRequests = {
    {
QT_MOC_LITERAL(0, 15), // "AdminQRRequests"
QT_MOC_LITERAL(16, 10), // "pageTurned"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 24), // "on_btn_pageRight_clicked"
QT_MOC_LITERAL(53, 23), // "on_btn_pageLeft_clicked"
QT_MOC_LITERAL(77, 30), // "on_btn_backToAdminHome_clicked"
QT_MOC_LITERAL(108, 10), // "setDisplay"
QT_MOC_LITERAL(119, 7) // "topUser"

    },
    "AdminQRRequests\0pageTurned\0\0"
    "on_btn_pageRight_clicked\0"
    "on_btn_pageLeft_clicked\0"
    "on_btn_backToAdminHome_clicked\0"
    "setDisplay\0topUser"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminQRRequests[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   47,    2, 0x08,    3 /* Private */,
       4,    0,   48,    2, 0x08,    4 /* Private */,
       5,    0,   49,    2, 0x08,    5 /* Private */,
       6,    1,   50,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void AdminQRRequests::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdminQRRequests *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->pageTurned((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->on_btn_pageRight_clicked(); break;
        case 2: _t->on_btn_pageLeft_clicked(); break;
        case 3: _t->on_btn_backToAdminHome_clicked(); break;
        case 4: _t->setDisplay((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AdminQRRequests::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminQRRequests::pageTurned)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject AdminQRRequests::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_AdminQRRequests.offsetsAndSize,
    qt_meta_data_AdminQRRequests,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AdminQRRequests_t
, QtPrivate::TypeAndForceComplete<AdminQRRequests, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *AdminQRRequests::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminQRRequests::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdminQRRequests.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AdminQRRequests::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void AdminQRRequests::pageTurned(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
