/****************************************************************************
** Meta object code from reading C++ file 'userwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../userwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSUserWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSUserWindowENDCLASS = QtMocHelpers::stringData(
    "UserWindow",
    "reconnect",
    "",
    "finished",
    "readyRead",
    "on_pbn_view_balance_clicked",
    "on_pbn_make_trasnaction_clicked",
    "on_pbn_mk_transfer_clicked",
    "on_pbn_view_transaction_histroy_clicked",
    "on_pushButton_get_account_number_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSUserWindowENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[11];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[10];
    char stringdata5[28];
    char stringdata6[32];
    char stringdata7[27];
    char stringdata8[40];
    char stringdata9[41];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSUserWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSUserWindowENDCLASS_t qt_meta_stringdata_CLASSUserWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "UserWindow"
        QT_MOC_LITERAL(11, 9),  // "reconnect"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 8),  // "finished"
        QT_MOC_LITERAL(31, 9),  // "readyRead"
        QT_MOC_LITERAL(41, 27),  // "on_pbn_view_balance_clicked"
        QT_MOC_LITERAL(69, 31),  // "on_pbn_make_trasnaction_clicked"
        QT_MOC_LITERAL(101, 26),  // "on_pbn_mk_transfer_clicked"
        QT_MOC_LITERAL(128, 39),  // "on_pbn_view_transaction_histr..."
        QT_MOC_LITERAL(168, 40)   // "on_pushButton_get_account_num..."
    },
    "UserWindow",
    "reconnect",
    "",
    "finished",
    "readyRead",
    "on_pbn_view_balance_clicked",
    "on_pbn_make_trasnaction_clicked",
    "on_pbn_mk_transfer_clicked",
    "on_pbn_view_transaction_histroy_clicked",
    "on_pushButton_get_account_number_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSUserWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    1 /* Public */,
       3,    0,   63,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x08,    7 /* Private */,
       9,    0,   69,    2, 0x08,    8 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject UserWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSUserWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSUserWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSUserWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<UserWindow, std::true_type>,
        // method 'reconnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'finished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbn_view_balance_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbn_make_trasnaction_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbn_mk_transfer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbn_view_transaction_histroy_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_get_account_number_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void UserWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->reconnect(); break;
        case 1: _t->finished(); break;
        case 2: _t->readyRead(); break;
        case 3: _t->on_pbn_view_balance_clicked(); break;
        case 4: _t->on_pbn_make_trasnaction_clicked(); break;
        case 5: _t->on_pbn_mk_transfer_clicked(); break;
        case 6: _t->on_pbn_view_transaction_histroy_clicked(); break;
        case 7: _t->on_pushButton_get_account_number_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UserWindow::*)();
            if (_t _q_method = &UserWindow::reconnect; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UserWindow::*)();
            if (_t _q_method = &UserWindow::finished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *UserWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSUserWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int UserWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void UserWindow::reconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void UserWindow::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
