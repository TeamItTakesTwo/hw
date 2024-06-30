/****************************************************************************
** Meta object code from reading C++ file 'datewidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../datewidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
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
struct qt_meta_stringdata_CLASSdateWidgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSdateWidgetENDCLASS = QtMocHelpers::stringData(
    "dateWidget",
    "casesUpdated",
    "",
    "QList<MyCase*>",
    "newCases",
    "aboutToClose",
    "QList<MyCase>",
    "updatedCases",
    "closed",
    "onAddButtonClicked",
    "onCloseButtonClicked",
    "addNewCase",
    "start_date",
    "end_date",
    "description",
    "onDeleteButtonClicked",
    "CaseWidgetItem*",
    "item"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSdateWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,
       5,    1,   59,    2, 0x06,    3 /* Public */,
       8,    0,   62,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   63,    2, 0x08,    6 /* Private */,
      10,    0,   64,    2, 0x08,    7 /* Private */,
      11,    3,   65,    2, 0x08,    8 /* Private */,
      15,    1,   72,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime, QMetaType::QString,   12,   13,   14,
    QMetaType::Void, 0x80000000 | 16,   17,

       0        // eod
};

Q_CONSTINIT const QMetaObject dateWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSdateWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSdateWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSdateWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<dateWidget, std::true_type>,
        // method 'casesUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<MyCase*>, std::false_type>,
        // method 'aboutToClose'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<MyCase> &, std::false_type>,
        // method 'closed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCloseButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addNewCase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDateTime &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDateTime &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onDeleteButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<CaseWidgetItem *, std::false_type>
    >,
    nullptr
} };

void dateWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dateWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->casesUpdated((*reinterpret_cast< std::add_pointer_t<QList<MyCase*>>>(_a[1]))); break;
        case 1: _t->aboutToClose((*reinterpret_cast< std::add_pointer_t<QList<MyCase>>>(_a[1]))); break;
        case 2: _t->closed(); break;
        case 3: _t->onAddButtonClicked(); break;
        case 4: _t->onCloseButtonClicked(); break;
        case 5: _t->addNewCase((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 6: _t->onDeleteButtonClicked((*reinterpret_cast< std::add_pointer_t<CaseWidgetItem*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< CaseWidgetItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (dateWidget::*)(const QVector<MyCase*> );
            if (_t _q_method = &dateWidget::casesUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (dateWidget::*)(const QVector<MyCase> & );
            if (_t _q_method = &dateWidget::aboutToClose; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (dateWidget::*)();
            if (_t _q_method = &dateWidget::closed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *dateWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dateWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSdateWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int dateWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void dateWidget::casesUpdated(const QVector<MyCase*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void dateWidget::aboutToClose(const QVector<MyCase> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void dateWidget::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSCaseWidgetItemENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSCaseWidgetItemENDCLASS = QtMocHelpers::stringData(
    "CaseWidgetItem",
    "deleteRequested",
    "",
    "CaseWidgetItem*",
    "item",
    "clicked",
    "caseUpdated",
    "QList<MyCase*>",
    "cases",
    "onDeleteButtonClicked",
    "onWidgetClicked",
    "onCaseUpdated"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCaseWidgetItemENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       5,    0,   53,    2, 0x06,    3 /* Public */,
       6,    1,   54,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   57,    2, 0x08,    6 /* Private */,
      10,    0,   58,    2, 0x08,    7 /* Private */,
      11,    1,   59,    2, 0x08,    8 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject CaseWidgetItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSCaseWidgetItemENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCaseWidgetItemENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCaseWidgetItemENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CaseWidgetItem, std::true_type>,
        // method 'deleteRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<CaseWidgetItem *, std::false_type>,
        // method 'clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'caseUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<MyCase*>, std::false_type>,
        // method 'onDeleteButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onWidgetClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCaseUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<MyCase*>, std::false_type>
    >,
    nullptr
} };

void CaseWidgetItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CaseWidgetItem *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->deleteRequested((*reinterpret_cast< std::add_pointer_t<CaseWidgetItem*>>(_a[1]))); break;
        case 1: _t->clicked(); break;
        case 2: _t->caseUpdated((*reinterpret_cast< std::add_pointer_t<QList<MyCase*>>>(_a[1]))); break;
        case 3: _t->onDeleteButtonClicked(); break;
        case 4: _t->onWidgetClicked(); break;
        case 5: _t->onCaseUpdated((*reinterpret_cast< std::add_pointer_t<QList<MyCase*>>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< CaseWidgetItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CaseWidgetItem::*)(CaseWidgetItem * );
            if (_t _q_method = &CaseWidgetItem::deleteRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CaseWidgetItem::*)();
            if (_t _q_method = &CaseWidgetItem::clicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CaseWidgetItem::*)(QVector<MyCase*> );
            if (_t _q_method = &CaseWidgetItem::caseUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *CaseWidgetItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CaseWidgetItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCaseWidgetItemENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CaseWidgetItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CaseWidgetItem::deleteRequested(CaseWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CaseWidgetItem::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CaseWidgetItem::caseUpdated(QVector<MyCase*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
