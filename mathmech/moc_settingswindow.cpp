/****************************************************************************
** Meta object code from reading C++ file 'settingswindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "settingswindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SettingsWindow[] = {

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
      16,   15,   15,   15, 0x08,
      54,   15,   15,   15, 0x08,
      91,   15,   15,   15, 0x08,
     132,   15,   15,   15, 0x08,
     171,   15,   15,   15, 0x08,
     209,   15,   15,   15, 0x08,
     250,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SettingsWindow[] = {
    "SettingsWindow\0\0on_settings_pushButton_save_clicked()\0"
    "on_settings_pushButton_trj_clicked()\0"
    "on_settings_pushButton_statgen_clicked()\0"
    "on_settings_pushButton_envir_clicked()\0"
    "on_settings_pushButton_radf_clicked()\0"
    "on_settings_pushButton_trj2pdb_clicked()\0"
    "on_settings_pushButton_agl_clicked()\0"
};

void SettingsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SettingsWindow *_t = static_cast<SettingsWindow *>(_o);
        switch (_id) {
        case 0: _t->on_settings_pushButton_save_clicked(); break;
        case 1: _t->on_settings_pushButton_trj_clicked(); break;
        case 2: _t->on_settings_pushButton_statgen_clicked(); break;
        case 3: _t->on_settings_pushButton_envir_clicked(); break;
        case 4: _t->on_settings_pushButton_radf_clicked(); break;
        case 5: _t->on_settings_pushButton_trj2pdb_clicked(); break;
        case 6: _t->on_settings_pushButton_agl_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SettingsWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SettingsWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SettingsWindow,
      qt_meta_data_SettingsWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SettingsWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SettingsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SettingsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsWindow))
        return static_cast<void*>(const_cast< SettingsWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SettingsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
