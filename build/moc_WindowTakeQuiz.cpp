/****************************************************************************
** Meta object code from reading C++ file 'WindowTakeQuiz.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/WindowTakeQuiz.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WindowTakeQuiz.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WindowTakeQuiz_t {
    QByteArrayData data[15];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WindowTakeQuiz_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WindowTakeQuiz_t qt_meta_stringdata_WindowTakeQuiz = {
    {
QT_MOC_LITERAL(0, 0, 14), // "WindowTakeQuiz"
QT_MOC_LITERAL(1, 15, 12), // "switchWindow"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 16), // "buildAnswerLists"
QT_MOC_LITERAL(4, 46, 14), // "jumpToQuestion"
QT_MOC_LITERAL(5, 61, 16), // "selectionChanged"
QT_MOC_LITERAL(6, 78, 16), // "previousQuestion"
QT_MOC_LITERAL(7, 95, 12), // "nextQuestion"
QT_MOC_LITERAL(8, 108, 10), // "submitQuiz"
QT_MOC_LITERAL(9, 119, 19), // "calculateQuizStatus"
QT_MOC_LITERAL(10, 139, 12), // "updateWindow"
QT_MOC_LITERAL(11, 152, 6), // "button"
QT_MOC_LITERAL(12, 159, 10), // "updateQuiz"
QT_MOC_LITERAL(13, 170, 27), // "updateTableWidget_Questions"
QT_MOC_LITERAL(14, 198, 23) // "updateLineEdit_TimeUsed"

    },
    "WindowTakeQuiz\0switchWindow\0\0"
    "buildAnswerLists\0jumpToQuestion\0"
    "selectionChanged\0previousQuestion\0"
    "nextQuestion\0submitQuiz\0calculateQuizStatus\0"
    "updateWindow\0button\0updateQuiz\0"
    "updateTableWidget_Questions\0"
    "updateLineEdit_TimeUsed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WindowTakeQuiz[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    1,   82,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WindowTakeQuiz::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WindowTakeQuiz *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->switchWindow(); break;
        case 1: _t->buildAnswerLists(); break;
        case 2: _t->jumpToQuestion(); break;
        case 3: _t->selectionChanged(); break;
        case 4: _t->previousQuestion(); break;
        case 5: _t->nextQuestion(); break;
        case 6: _t->submitQuiz(); break;
        case 7: _t->calculateQuizStatus(); break;
        case 8: _t->updateWindow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->updateQuiz(); break;
        case 10: _t->updateTableWidget_Questions(); break;
        case 11: _t->updateLineEdit_TimeUsed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WindowTakeQuiz::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WindowTakeQuiz::switchWindow)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WindowTakeQuiz::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_WindowTakeQuiz.data,
    qt_meta_data_WindowTakeQuiz,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WindowTakeQuiz::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WindowTakeQuiz::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WindowTakeQuiz.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int WindowTakeQuiz::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void WindowTakeQuiz::switchWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
