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
    const uint offsetsAndSize[22];
    char stringdata0[241];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AdminQRRequests_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AdminQRRequests_t qt_meta_stringdata_AdminQRRequests = {
    {
QT_MOC_LITERAL(0, 15), // "AdminQRRequests"
QT_MOC_LITERAL(16, 24), // "on_btn_pageRight_clicked"
QT_MOC_LITERAL(41, 0), // ""
QT_MOC_LITERAL(42, 23), // "on_btn_pageLeft_clicked"
QT_MOC_LITERAL(66, 30), // "on_btn_backToAdminHome_clicked"
QT_MOC_LITERAL(97, 23), // "on_btn_assign_1_clicked"
QT_MOC_LITERAL(121, 23), // "on_btn_assign_2_clicked"
QT_MOC_LITERAL(145, 23), // "on_btn_assign_3_clicked"
QT_MOC_LITERAL(169, 23), // "on_btn_assign_4_clicked"
QT_MOC_LITERAL(193, 23), // "on_btn_assign_5_clicked"
QT_MOC_LITERAL(217, 23) // "on_btn_assign_6_clicked"

    },
    "AdminQRRequests\0on_btn_pageRight_clicked\0"
    "\0on_btn_pageLeft_clicked\0"
    "on_btn_backToAdminHome_clicked\0"
    "on_btn_assign_1_clicked\0on_btn_assign_2_clicked\0"
    "on_btn_assign_3_clicked\0on_btn_assign_4_clicked\0"
    "on_btn_assign_5_clicked\0on_btn_assign_6_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminQRRequests[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    0,   71,    2, 0x08,    4 /* Private */,
       6,    0,   72,    2, 0x08,    5 /* Private */,
       7,    0,   73,    2, 0x08,    6 /* Private */,
       8,    0,   74,    2, 0x08,    7 /* Private */,
       9,    0,   75,    2, 0x08,    8 /* Private */,
      10,    0,   76,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AdminQRRequests::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdminQRRequests *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btn_pageRight_clicked(); break;
        case 1: _t->on_btn_pageLeft_clicked(); break;
        case 2: _t->on_btn_backToAdminHome_clicked(); break;
        case 3: _t->on_btn_assign_1_clicked(); break;
        case 4: _t->on_btn_assign_2_clicked(); break;
        case 5: _t->on_btn_assign_3_clicked(); break;
        case 6: _t->on_btn_assign_4_clicked(); break;
        case 7: _t->on_btn_assign_5_clicked(); break;
        case 8: _t->on_btn_assign_6_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject AdminQRRequests::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_AdminQRRequests.offsetsAndSize,
    qt_meta_data_AdminQRRequests,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AdminQRRequests_t
, QtPrivate::TypeAndForceComplete<AdminQRRequests, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
