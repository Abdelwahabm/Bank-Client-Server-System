/****************************************************************************
** Meta object code from reading C++ file 'adminwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../adminwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSAdminWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSAdminWindowENDCLASS = QtMocHelpers::stringData(
    "AdminWindow",
    "reconnect",
    "",
    "finished",
    "readyRead",
    "on_pushButton_get_account_number_clicked",
    "on_pbn_view_balance_clicked",
    "on_pbn_create_new_account_clicked",
    "on_pbn_delete_account_clicked",
    "on_pbn_view_database_clicked",
    "on_pbn_view_transaction_history_clicked",
    "on_pbn_update_account_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAdminWindowENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[12];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[10];
    char stringdata5[41];
    char stringdata6[28];
    char stringdata7[34];
    char stringdata8[30];
    char stringdata9[29];
    char stringdata10[40];
    char stringdata11[30];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAdminWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAdminWindowENDCLASS_t qt_meta_stringdata_CLASSAdminWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "AdminWindow"
        QT_MOC_LITERAL(12, 9),  // "reconnect"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 8),  // "finished"
        QT_MOC_LITERAL(32, 9),  // "readyRead"
        QT_MOC_LITERAL(42, 40),  // "on_pushButton_get_account_num..."
        QT_MOC_LITERAL(83, 27),  // "on_pbn_view_balance_clicked"
        QT_MOC_LITERAL(111, 33),  // "on_pbn_create_new_account_cli..."
        QT_MOC_LITERAL(145, 29),  // "on_pbn_delete_account_clicked"
        QT_MOC_LITERAL(175, 28),  // "on_pbn_view_database_clicked"
        QT_MOC_LITERAL(204, 39),  // "on_pbn_view_transaction_histo..."
        QT_MOC_LITERAL(244, 29)   // "on_pbn_update_account_clicked"
    },
    "AdminWindow",
    "reconnect",
    "",
    "finished",
    "readyRead",
    "on_pushButton_get_account_number_clicked",
    "on_pbn_view_balance_clicked",
    "on_pbn_create_new_account_clicked",
    "on_pbn_delete_account_clicked",
    "on_pbn_view_database_clicked",
    "on_pbn_view_transaction_history_clicked",
    "on_pbn_update_account_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAdminWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x06,    1 /* Public */,
       3,    0,   75,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   76,    2, 0x08,    3 /* Private */,
       5,    0,   77,    2, 0x08,    4 /* Private */,
       6,    0,   78,    2, 0x08,    5 /* Private */,
       7,    0,   79,    2, 0x08,    6 /* Private */,
       8,    0,   80,    2, 0x08,    7 /* Private */,
       9,    0,   81,    2, 0x08,    8 /* Private */,
      10,    0,   82,    2, 0x08,    9 /* Private */,
      11,    0,   83,    2, 0x08,   10 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject AdminWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSAdminWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAdminWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAdminWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AdminWindow, std::true_type>,
        // method 'reconnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'finished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_get_account_number_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbn_view_balance_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbn_create_new_account_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbn_delete_account_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbn_view_database_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbn_view_transaction_history_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbn_update_account_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void AdminWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdminWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->reconnect(); break;
        case 1: _t->finished(); break;
        case 2: _t->readyRead(); break;
        case 3: _t->on_pushButton_get_account_number_clicked(); break;
        case 4: _t->on_pbn_view_balance_clicked(); break;
        case 5: _t->on_pbn_create_new_account_clicked(); break;
        case 6: _t->on_pbn_delete_account_clicked(); break;
        case 7: _t->on_pbn_view_database_clicked(); break;
        case 8: _t->on_pbn_view_transaction_history_clicked(); break;
        case 9: _t->on_pbn_update_account_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AdminWindow::*)();
            if (_t _q_method = &AdminWindow::reconnect; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AdminWindow::*)();
            if (_t _q_method = &AdminWindow::finished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *AdminWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAdminWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int AdminWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void AdminWindow::reconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AdminWindow::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
