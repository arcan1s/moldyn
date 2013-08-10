/********************************************************************************
** Form generated from reading UI file 'atomtypeswindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATOMTYPESWINDOW_H
#define UI_ATOMTYPESWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AtomTypesWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *atomTypes_layout_output;
    QLabel *atomTypes_label_output;
    QLineEdit *atomTypes_lineEdit_output;
    QPushButton *atomTypes_pushButton_output;
    QHBoxLayout *atomTypes_layout_mol;
    QLabel *atomTypes_label_mol;
    QComboBox *atomTypes_comboBox_mol;
    QLabel *atomTypes_label_numOfMol;
    QSpinBox *atomTypes_spinBox_numOfMol;
    QHBoxLayout *atomTypes_layout_atom;
    QLabel *atomTypes_label_chType;
    QLineEdit *atomTypes_lineEdit_chType;
    QLabel *atomTypes_label_intType;
    QSpinBox *atomTypes_spinBox_intType;
    QPushButton *atomTypes_pushButton_add;
    QListWidget *atomTypes_listWidget;
    QHBoxLayout *atomTypes_layout_intRem;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *atomTypes_pushButton_typeRem;
    QHBoxLayout *atomTypes_layout_buttons;
    QPushButton *atomTypes_pushButton_clear;
    QSpacerItem *horizontalSpacer;
    QPushButton *atomTypes_pushButton_create;
    QPushButton *atomTypes_pushButton_close;

    void setupUi(QMainWindow *AtomTypesWindow)
    {
        if (AtomTypesWindow->objectName().isEmpty())
            AtomTypesWindow->setObjectName(QString::fromUtf8("AtomTypesWindow"));
        AtomTypesWindow->resize(468, 320);
        centralwidget = new QWidget(AtomTypesWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        atomTypes_layout_output = new QHBoxLayout();
        atomTypes_layout_output->setObjectName(QString::fromUtf8("atomTypes_layout_output"));
        atomTypes_label_output = new QLabel(centralwidget);
        atomTypes_label_output->setObjectName(QString::fromUtf8("atomTypes_label_output"));
        atomTypes_label_output->setMinimumSize(QSize(110, 23));

        atomTypes_layout_output->addWidget(atomTypes_label_output);

        atomTypes_lineEdit_output = new QLineEdit(centralwidget);
        atomTypes_lineEdit_output->setObjectName(QString::fromUtf8("atomTypes_lineEdit_output"));
        atomTypes_lineEdit_output->setMinimumSize(QSize(100, 23));
        atomTypes_lineEdit_output->setMaximumSize(QSize(16777215, 16777215));

        atomTypes_layout_output->addWidget(atomTypes_lineEdit_output);

        atomTypes_pushButton_output = new QPushButton(centralwidget);
        atomTypes_pushButton_output->setObjectName(QString::fromUtf8("atomTypes_pushButton_output"));
        atomTypes_pushButton_output->setMinimumSize(QSize(80, 23));
        atomTypes_pushButton_output->setAutoDefault(true);

        atomTypes_layout_output->addWidget(atomTypes_pushButton_output);


        verticalLayout->addLayout(atomTypes_layout_output);

        atomTypes_layout_mol = new QHBoxLayout();
        atomTypes_layout_mol->setObjectName(QString::fromUtf8("atomTypes_layout_mol"));
        atomTypes_label_mol = new QLabel(centralwidget);
        atomTypes_label_mol->setObjectName(QString::fromUtf8("atomTypes_label_mol"));
        atomTypes_label_mol->setMinimumSize(QSize(110, 23));

        atomTypes_layout_mol->addWidget(atomTypes_label_mol);

        atomTypes_comboBox_mol = new QComboBox(centralwidget);
        atomTypes_comboBox_mol->setObjectName(QString::fromUtf8("atomTypes_comboBox_mol"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(atomTypes_comboBox_mol->sizePolicy().hasHeightForWidth());
        atomTypes_comboBox_mol->setSizePolicy(sizePolicy);
        atomTypes_comboBox_mol->setMinimumSize(QSize(130, 23));

        atomTypes_layout_mol->addWidget(atomTypes_comboBox_mol);

        atomTypes_label_numOfMol = new QLabel(centralwidget);
        atomTypes_label_numOfMol->setObjectName(QString::fromUtf8("atomTypes_label_numOfMol"));
        atomTypes_label_numOfMol->setMinimumSize(QSize(130, 23));

        atomTypes_layout_mol->addWidget(atomTypes_label_numOfMol);

        atomTypes_spinBox_numOfMol = new QSpinBox(centralwidget);
        atomTypes_spinBox_numOfMol->setObjectName(QString::fromUtf8("atomTypes_spinBox_numOfMol"));
        atomTypes_spinBox_numOfMol->setMinimumSize(QSize(60, 23));
        atomTypes_spinBox_numOfMol->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        atomTypes_spinBox_numOfMol->setMinimum(1);
        atomTypes_spinBox_numOfMol->setMaximum(999);

        atomTypes_layout_mol->addWidget(atomTypes_spinBox_numOfMol);


        verticalLayout->addLayout(atomTypes_layout_mol);

        atomTypes_layout_atom = new QHBoxLayout();
        atomTypes_layout_atom->setObjectName(QString::fromUtf8("atomTypes_layout_atom"));
        atomTypes_label_chType = new QLabel(centralwidget);
        atomTypes_label_chType->setObjectName(QString::fromUtf8("atomTypes_label_chType"));
        atomTypes_label_chType->setMinimumSize(QSize(110, 23));

        atomTypes_layout_atom->addWidget(atomTypes_label_chType);

        atomTypes_lineEdit_chType = new QLineEdit(centralwidget);
        atomTypes_lineEdit_chType->setObjectName(QString::fromUtf8("atomTypes_lineEdit_chType"));
        atomTypes_lineEdit_chType->setMinimumSize(QSize(60, 23));

        atomTypes_layout_atom->addWidget(atomTypes_lineEdit_chType);

        atomTypes_label_intType = new QLabel(centralwidget);
        atomTypes_label_intType->setObjectName(QString::fromUtf8("atomTypes_label_intType"));
        atomTypes_label_intType->setMinimumSize(QSize(110, 23));

        atomTypes_layout_atom->addWidget(atomTypes_label_intType);

        atomTypes_spinBox_intType = new QSpinBox(centralwidget);
        atomTypes_spinBox_intType->setObjectName(QString::fromUtf8("atomTypes_spinBox_intType"));
        atomTypes_spinBox_intType->setMinimumSize(QSize(60, 23));
        atomTypes_spinBox_intType->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        atomTypes_spinBox_intType->setMinimum(1);

        atomTypes_layout_atom->addWidget(atomTypes_spinBox_intType);

        atomTypes_pushButton_add = new QPushButton(centralwidget);
        atomTypes_pushButton_add->setObjectName(QString::fromUtf8("atomTypes_pushButton_add"));
        atomTypes_pushButton_add->setMinimumSize(QSize(80, 23));
        atomTypes_pushButton_add->setAutoDefault(true);

        atomTypes_layout_atom->addWidget(atomTypes_pushButton_add);


        verticalLayout->addLayout(atomTypes_layout_atom);

        atomTypes_listWidget = new QListWidget(centralwidget);
        atomTypes_listWidget->setObjectName(QString::fromUtf8("atomTypes_listWidget"));
        atomTypes_listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(atomTypes_listWidget);

        atomTypes_layout_intRem = new QHBoxLayout();
        atomTypes_layout_intRem->setObjectName(QString::fromUtf8("atomTypes_layout_intRem"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        atomTypes_layout_intRem->addItem(horizontalSpacer_5);

        atomTypes_pushButton_typeRem = new QPushButton(centralwidget);
        atomTypes_pushButton_typeRem->setObjectName(QString::fromUtf8("atomTypes_pushButton_typeRem"));
        atomTypes_pushButton_typeRem->setMinimumSize(QSize(80, 23));
        atomTypes_pushButton_typeRem->setAutoDefault(true);

        atomTypes_layout_intRem->addWidget(atomTypes_pushButton_typeRem);


        verticalLayout->addLayout(atomTypes_layout_intRem);

        atomTypes_layout_buttons = new QHBoxLayout();
        atomTypes_layout_buttons->setObjectName(QString::fromUtf8("atomTypes_layout_buttons"));
        atomTypes_pushButton_clear = new QPushButton(centralwidget);
        atomTypes_pushButton_clear->setObjectName(QString::fromUtf8("atomTypes_pushButton_clear"));
        atomTypes_pushButton_clear->setMinimumSize(QSize(80, 23));
        atomTypes_pushButton_clear->setAutoDefault(true);

        atomTypes_layout_buttons->addWidget(atomTypes_pushButton_clear);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        atomTypes_layout_buttons->addItem(horizontalSpacer);

        atomTypes_pushButton_create = new QPushButton(centralwidget);
        atomTypes_pushButton_create->setObjectName(QString::fromUtf8("atomTypes_pushButton_create"));
        atomTypes_pushButton_create->setMinimumSize(QSize(80, 23));
        atomTypes_pushButton_create->setMaximumSize(QSize(16777215, 16777215));
        atomTypes_pushButton_create->setAutoDefault(true);

        atomTypes_layout_buttons->addWidget(atomTypes_pushButton_create);

        atomTypes_pushButton_close = new QPushButton(centralwidget);
        atomTypes_pushButton_close->setObjectName(QString::fromUtf8("atomTypes_pushButton_close"));
        atomTypes_pushButton_close->setMinimumSize(QSize(80, 23));
        atomTypes_pushButton_close->setAutoDefault(true);

        atomTypes_layout_buttons->addWidget(atomTypes_pushButton_close);


        verticalLayout->addLayout(atomTypes_layout_buttons);

        AtomTypesWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(atomTypes_lineEdit_output, atomTypes_pushButton_output);
        QWidget::setTabOrder(atomTypes_pushButton_output, atomTypes_comboBox_mol);
        QWidget::setTabOrder(atomTypes_comboBox_mol, atomTypes_spinBox_numOfMol);
        QWidget::setTabOrder(atomTypes_spinBox_numOfMol, atomTypes_lineEdit_chType);
        QWidget::setTabOrder(atomTypes_lineEdit_chType, atomTypes_spinBox_intType);
        QWidget::setTabOrder(atomTypes_spinBox_intType, atomTypes_pushButton_add);
        QWidget::setTabOrder(atomTypes_pushButton_add, atomTypes_listWidget);
        QWidget::setTabOrder(atomTypes_listWidget, atomTypes_pushButton_typeRem);
        QWidget::setTabOrder(atomTypes_pushButton_typeRem, atomTypes_pushButton_clear);
        QWidget::setTabOrder(atomTypes_pushButton_clear, atomTypes_pushButton_create);
        QWidget::setTabOrder(atomTypes_pushButton_create, atomTypes_pushButton_close);

        retranslateUi(AtomTypesWindow);
        QObject::connect(atomTypes_pushButton_close, SIGNAL(clicked()), AtomTypesWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(AtomTypesWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AtomTypesWindow)
    {
        AtomTypesWindow->setWindowTitle(QApplication::translate("AtomTypesWindow", "Atom types", 0, QApplication::UnicodeUTF8));
        atomTypes_label_output->setText(QApplication::translate("AtomTypesWindow", "Output file", 0, QApplication::UnicodeUTF8));
        atomTypes_pushButton_output->setText(QApplication::translate("AtomTypesWindow", "Browse", 0, QApplication::UnicodeUTF8));
        atomTypes_label_mol->setText(QApplication::translate("AtomTypesWindow", "Molecule", 0, QApplication::UnicodeUTF8));
        atomTypes_comboBox_mol->clear();
        atomTypes_comboBox_mol->insertItems(0, QStringList()
         << QApplication::translate("AtomTypesWindow", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AtomTypesWindow", "Add new molecule", 0, QApplication::UnicodeUTF8)
        );
        atomTypes_label_numOfMol->setText(QApplication::translate("AtomTypesWindow", "Number of molecules", 0, QApplication::UnicodeUTF8));
        atomTypes_label_chType->setText(QApplication::translate("AtomTypesWindow", "Char atom type", 0, QApplication::UnicodeUTF8));
        atomTypes_label_intType->setText(QApplication::translate("AtomTypesWindow", "Int atom type", 0, QApplication::UnicodeUTF8));
        atomTypes_pushButton_add->setText(QApplication::translate("AtomTypesWindow", "Add", 0, QApplication::UnicodeUTF8));
        atomTypes_pushButton_typeRem->setText(QApplication::translate("AtomTypesWindow", "Remove", 0, QApplication::UnicodeUTF8));
        atomTypes_pushButton_clear->setText(QApplication::translate("AtomTypesWindow", "Clear", 0, QApplication::UnicodeUTF8));
        atomTypes_pushButton_create->setText(QApplication::translate("AtomTypesWindow", "Create", 0, QApplication::UnicodeUTF8));
        atomTypes_pushButton_close->setText(QApplication::translate("AtomTypesWindow", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AtomTypesWindow: public Ui_AtomTypesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATOMTYPESWINDOW_H
