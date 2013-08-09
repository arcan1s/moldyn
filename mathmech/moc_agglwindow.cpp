/****************************************************************************
** Meta object code from reading C++ file 'agglwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "agglwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'agglwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AgglWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      46,   11,   11,   11, 0x08,
      76,   70,   11,   11, 0x08,
     117,   11,   11,   11, 0x08,
     151,   11,   11,   11, 0x08,
     186,   11,   11,   11, 0x08,
     220,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AgglWindow[] = {
    "AgglWindow\0\0on_agl_pushButton_input_clicked()\0"
    "on_pushButton_clicked()\0index\0"
    "on_agl_comboBox_currentIndexChanged(int)\0"
    "on_agl_listWidget_itemActivated()\0"
    "on_agl_pushButton_output_clicked()\0"
    "on_agl_pushButton_clear_clicked()\0"
    "on_agl_pushButton_create_clicked()\0"
};

void AgglWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AgglWindow *_t = static_cast<AgglWindow *>(_o);
        switch (_id) {
        case 0: _t->on_agl_pushButton_input_clicked(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_agl_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_agl_listWidget_itemActivated(); break;
        case 4: _t->on_agl_pushButton_output_clicked(); break;
        case 5: _t->on_agl_pushButton_clear_clicked(); break;
        case 6: _t->on_agl_pushButton_create_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AgglWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AgglWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AgglWindow,
      qt_meta_data_AgglWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AgglWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AgglWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AgglWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AgglWindow))
        return static_cast<void*>(const_cast< AgglWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AgglWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
