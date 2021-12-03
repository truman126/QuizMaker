/****************************************************************************
** Meta object code from reading C++ file 'WindowEditQuiz.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/WindowEditQuiz.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WindowEditQuiz.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WindowEditQuiz_t {
    QByteArrayData data[14];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WindowEditQuiz_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WindowEditQuiz_t qt_meta_stringdata_WindowEditQuiz = {
    {
QT_MOC_LITERAL(0, 0, 14), // "WindowEditQuiz"
QT_MOC_LITERAL(1, 15, 12), // "switchWindow"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "addQuestion"
QT_MOC_LITERAL(4, 41, 14), // "deleteQuestion"
QT_MOC_LITERAL(5, 56, 12), // "editQuestion"
QT_MOC_LITERAL(6, 69, 6), // "cancel"
QT_MOC_LITERAL(7, 76, 2), // "ok"
QT_MOC_LITERAL(8, 79, 16), // "selectionChanged"
QT_MOC_LITERAL(9, 96, 8), // "isNumber"
QT_MOC_LITERAL(10, 105, 11), // "std::string"
QT_MOC_LITERAL(11, 117, 18), // "quizTimeLimitInput"
QT_MOC_LITERAL(12, 136, 26), // "buildTableWidget_Questions"
QT_MOC_LITERAL(13, 163, 17) // "setQuizAttributes"

    },
    "WindowEditQuiz\0switchWindow\0\0addQuestion\0"
    "deleteQuestion\0editQuestion\0cancel\0"
    "ok\0selectionChanged\0isNumber\0std::string\0"
    "quizTimeLimitInput\0buildTableWidget_Questions\0"
    "setQuizAttributes"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WindowEditQuiz[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    1,   71,    2, 0x08 /* Private */,
      12,    0,   74,    2, 0x08 /* Private */,
      13,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WindowEditQuiz::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WindowEditQuiz *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->switchWindow(); break;
        case 1: _t->addQuestion(); break;
        case 2: _t->deleteQuestion(); break;
        case 3: _t->editQuestion(); break;
        case 4: _t->cancel(); break;
        case 5: _t->ok(); break;
        case 6: _t->selectionChanged(); break;
        case 7: { bool _r = _t->isNumber((*reinterpret_cast< const std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->buildTableWidget_Questions(); break;
        case 9: _t->setQuizAttributes(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WindowEditQuiz::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WindowEditQuiz::switchWindow)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WindowEditQuiz::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_WindowEditQuiz.data,
    qt_meta_data_WindowEditQuiz,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WindowEditQuiz::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WindowEditQuiz::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WindowEditQuiz.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int WindowEditQuiz::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void WindowEditQuiz::switchWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
