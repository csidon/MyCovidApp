/****************************************************************************
** Meta object code from reading C++ file 'authdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../0806_mCR_login/authdialog.h"
#include <QtGui/qtextcursor.h>
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
    const uint offsetsAndSize[38];
    char stringdata0[401];
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
QT_MOC_LITERAL(51, 19), // "openMainAdminWindow"
QT_MOC_LITERAL(71, 16), // "setValueProgress"
QT_MOC_LITERAL(88, 18), // "showAccountCreated"
QT_MOC_LITERAL(107, 15), // "redirectToLogin"
QT_MOC_LITERAL(123, 29), // "on_btn_switchToSignup_clicked"
QT_MOC_LITERAL(153, 28), // "on_btn_switchToLogin_clicked"
QT_MOC_LITERAL(182, 28), // "on_btn_createAccount_clicked"
QT_MOC_LITERAL(211, 39), // "on_lineEdit_inputRegEmail_inp..."
QT_MOC_LITERAL(251, 25), // "on_btn_nextTerms1_clicked"
QT_MOC_LITERAL(277, 36), // "on_checkBox_agreeTerms2_state..."
QT_MOC_LITERAL(314, 4), // "arg1"
QT_MOC_LITERAL(319, 25), // "on_btn_nextTerms2_clicked"
QT_MOC_LITERAL(345, 26), // "on_btn_nextDetails_clicked"
QT_MOC_LITERAL(372, 28) // "on_btn_nextDetails_2_clicked"

    },
    "AuthDialog\0sendUIDSignal\0\0uid\0"
    "on_btn_login_clicked\0openMainAdminWindow\0"
    "setValueProgress\0showAccountCreated\0"
    "redirectToLogin\0on_btn_switchToSignup_clicked\0"
    "on_btn_switchToLogin_clicked\0"
    "on_btn_createAccount_clicked\0"
    "on_lineEdit_inputRegEmail_inputRejected\0"
    "on_btn_nextTerms1_clicked\0"
    "on_checkBox_agreeTerms2_stateChanged\0"
    "arg1\0on_btn_nextTerms2_clicked\0"
    "on_btn_nextDetails_clicked\0"
    "on_btn_nextDetails_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AuthDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,  107,    2, 0x0a,    3 /* Public */,
       5,    0,  108,    2, 0x0a,    4 /* Public */,
       6,    0,  109,    2, 0x0a,    5 /* Public */,
       7,    0,  110,    2, 0x0a,    6 /* Public */,
       8,    0,  111,    2, 0x0a,    7 /* Public */,
       9,    0,  112,    2, 0x08,    8 /* Private */,
      10,    0,  113,    2, 0x08,    9 /* Private */,
      11,    0,  114,    2, 0x08,   10 /* Private */,
      12,    0,  115,    2, 0x08,   11 /* Private */,
      13,    0,  116,    2, 0x08,   12 /* Private */,
      14,    1,  117,    2, 0x08,   13 /* Private */,
      16,    0,  120,    2, 0x08,   15 /* Private */,
      17,    0,  121,    2, 0x08,   16 /* Private */,
      18,    0,  122,    2, 0x08,   17 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
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
        case 2: _t->openMainAdminWindow(); break;
        case 3: _t->setValueProgress(); break;
        case 4: _t->showAccountCreated(); break;
        case 5: _t->redirectToLogin(); break;
        case 6: _t->on_btn_switchToSignup_clicked(); break;
        case 7: _t->on_btn_switchToLogin_clicked(); break;
        case 8: _t->on_btn_createAccount_clicked(); break;
        case 9: _t->on_lineEdit_inputRegEmail_inputRejected(); break;
        case 10: _t->on_btn_nextTerms1_clicked(); break;
        case 11: _t->on_checkBox_agreeTerms2_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->on_btn_nextTerms2_clicked(); break;
        case 13: _t->on_btn_nextDetails_clicked(); break;
        case 14: _t->on_btn_nextDetails_2_clicked(); break;
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
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


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

// SIGNAL 0
void AuthDialog::sendUIDSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
