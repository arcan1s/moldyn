/****************************************************************************
** Meta object code from reading C++ file 'atomtypeswindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "atomtypeswindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'atomtypeswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AtomTypesWindow[] = {

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
      17,   16,   16,   16, 0x08,
      58,   16,   16,   16, 0x08,
      96,   16,   16,   16, 0x08,
     138,   16,   16,   16, 0x08,
     178,   16,   16,   16, 0x08,
     232,  226,   16,   16, 0x08,
     283,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AtomTypesWindow[] = {
    "AtomTypesWindow\0\0"
    "on_atomTypes_pushButton_output_clicked()\0"
    "on_atomTypes_pushButton_add_clicked()\0"
    "on_atomTypes_pushButton_typeRem_clicked()\0"
    "on_atomTypes_pushButton_clear_clicked()\0"
    "on_atomTypes_spinBox_numOfMol_editingFinished()\0"
    "index\0on_atomTypes_comboBox_mol_currentIndexChanged(int)\0"
    "on_atomTypes_pushButton_create_clicked()\0"
};

void AtomTypesWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AtomTypesWindow *_t = static_cast<AtomTypesWindow *>(_o);
        switch (_id) {
        case 0: _t->on_atomTypes_pushButton_output_clicked(); break;
        case 1: _t->on_atomTypes_pushButton_add_clicked(); break;
        case 2: _t->on_atomTypes_pushButton_typeRem_clicked(); break;
        case 3: _t->on_atomTypes_pushButton_clear_clicked(); break;
        case 4: _t->on_atomTypes_spinBox_numOfMol_editingFinished(); break;
        case 5: _t->on_atomTypes_comboBox_mol_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_atomTypes_pushButton_create_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AtomTypesWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AtomTypesWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AtomTypesWindow,
      qt_meta_data_AtomTypesWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AtomTypesWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AtomTypesWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AtomTypesWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AtomTypesWindow))
        return static_cast<void*>(const_cast< AtomTypesWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AtomTypesWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
