/****************************************************************************
** Meta object code from reading C++ file 'authdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../0806_mCR_login/authdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'authdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AuthDialog_t {
    const uint offsetsAndSize[22];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AuthDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AuthDialog_t qt_meta_stringdata_AuthDialog = {
    {
QT_MOC_LITERAL(0, 10), // "AuthDialog"
QT_MOC_LITERAL(11, 13), // "sendUIDSignal"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 3), // "uid"
QT_MOC_LITERAL(30, 20), // "on_btn_login_clicked"
QT_MOC_LITERAL(51, 16), // "openMainEUWindow"
QT_MOC_LITERAL(68, 19), // "openMainAdminWindow"
QT_MOC_LITERAL(88, 29), // "on_btn_switchToSignup_clicked"
QT_MOC_LITERAL(118, 28), // "on_btn_switchToLogin_clicked"
QT_MOC_LITERAL(147, 28), // "on_btn_createAccount_clicked"
QT_MOC_LITERAL(176, 39) // "on_lineEdit_inputRegEmail_inp..."

    },
    "AuthDialog\0sendUIDSignal\0\0uid\0"
    "on_btn_login_clicked\0openMainEUWindow\0"
    "openMainAdminWindow\0on_btn_switchToSignup_clicked\0"
    "on_btn_switchToLogin_clicked\0"
    "on_btn_createAccount_clicked\0"
    "on_lineEdit_inputRegEmail_inputRejected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AuthDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   65,    2, 0x0a,    3 /* Public */,
       5,    0,   66,    2, 0x0a,    4 /* Public */,
       6,    0,   67,    2, 0x0a,    5 /* Public */,
       7,    0,   68,    2, 0x08,    6 /* Private */,
       8,    0,   69,    2, 0x08,    7 /* Private */,
       9,    0,   70,    2, 0x08,    8 /* Private */,
      10,    0,   71,    2, 0x08,    9 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AuthDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AuthDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendUIDSignal((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->on_btn_login_clicked(); break;
        case 2: _t->openMainEUWindow(); break;
        case 3: _t->openMainAdminWindow(); break;
        case 4: _t->on_btn_switchToSignup_clicked(); break;
        case 5: _t->on_btn_switchToLogin_clicked(); break;
        case 6: _t->on_btn_createAccount_clicked(); break;
        case 7: _t->on_lineEdit_inputRegEmail_inputRejected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AuthDialog::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AuthDialog::sendUIDSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject AuthDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_AuthDialog.offsetsAndSize,
    qt_meta_data_AuthDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AuthDialog_t
, QtPrivate::TypeAndForceComplete<AuthDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *AuthDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AuthDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AuthDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AuthDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void AuthDialog::sendUIDSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
