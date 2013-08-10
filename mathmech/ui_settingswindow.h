/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *settings_layout_trj;
    QLabel *settings_label_trj;
    QLineEdit *settings_lineEdit_trj;
    QPushButton *settings_pushButton_trj;
    QHBoxLayout *settings_layout_statgen;
    QLabel *settings_label_statgen;
    QLineEdit *settings_lineEdit_statgen;
    QPushButton *settings_pushButton_statgen;
    QHBoxLayout *settings_layout_envir;
    QLabel *settings_label_envir;
    QLineEdit *settings_lineEdit_envir;
    QPushButton *settings_pushButton_envir;
    QHBoxLayout *settings_layout_radf;
    QLabel *settings_label_radf;
    QLineEdit *settings_lineEdit_radf;
    QPushButton *settings_pushButton_radf;
    QHBoxLayout *settings_layout_trj2pdb;
    QLabel *settings_label_trj2pdb;
    QLineEdit *settings_lineEdit_trj2pdb;
    QPushButton *settings_pushButton_trj2pdb;
    QHBoxLayout *settings_layout_agl;
    QLabel *settings_label_agl;
    QLineEdit *settings_lineEdit_agl;
    QPushButton *settings_pushButton_agl;
    QHBoxLayout *settings_layout_lang;
    QLabel *settings_label_lang;
    QComboBox *settings_comboBox_lang;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *settings_layout_buttons;
    QSpacerItem *horizontalSpacer;
    QPushButton *settings_pushButton_save;
    QPushButton *settings_pushButton_close;

    void setupUi(QMainWindow *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QString::fromUtf8("SettingsWindow"));
        SettingsWindow->resize(392, 320);
        centralwidget = new QWidget(SettingsWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        settings_layout_trj = new QHBoxLayout();
        settings_layout_trj->setObjectName(QString::fromUtf8("settings_layout_trj"));
        settings_label_trj = new QLabel(centralwidget);
        settings_label_trj->setObjectName(QString::fromUtf8("settings_label_trj"));
        settings_label_trj->setMinimumSize(QSize(110, 23));

        settings_layout_trj->addWidget(settings_label_trj);

        settings_lineEdit_trj = new QLineEdit(centralwidget);
        settings_lineEdit_trj->setObjectName(QString::fromUtf8("settings_lineEdit_trj"));

        settings_layout_trj->addWidget(settings_lineEdit_trj);

        settings_pushButton_trj = new QPushButton(centralwidget);
        settings_pushButton_trj->setObjectName(QString::fromUtf8("settings_pushButton_trj"));
        settings_pushButton_trj->setMinimumSize(QSize(80, 23));
        settings_pushButton_trj->setAutoDefault(true);

        settings_layout_trj->addWidget(settings_pushButton_trj);


        verticalLayout->addLayout(settings_layout_trj);

        settings_layout_statgen = new QHBoxLayout();
        settings_layout_statgen->setObjectName(QString::fromUtf8("settings_layout_statgen"));
        settings_label_statgen = new QLabel(centralwidget);
        settings_label_statgen->setObjectName(QString::fromUtf8("settings_label_statgen"));
        settings_label_statgen->setMinimumSize(QSize(110, 23));

        settings_layout_statgen->addWidget(settings_label_statgen);

        settings_lineEdit_statgen = new QLineEdit(centralwidget);
        settings_lineEdit_statgen->setObjectName(QString::fromUtf8("settings_lineEdit_statgen"));

        settings_layout_statgen->addWidget(settings_lineEdit_statgen);

        settings_pushButton_statgen = new QPushButton(centralwidget);
        settings_pushButton_statgen->setObjectName(QString::fromUtf8("settings_pushButton_statgen"));
        settings_pushButton_statgen->setMinimumSize(QSize(80, 23));
        settings_pushButton_statgen->setAutoDefault(true);

        settings_layout_statgen->addWidget(settings_pushButton_statgen);


        verticalLayout->addLayout(settings_layout_statgen);

        settings_layout_envir = new QHBoxLayout();
        settings_layout_envir->setObjectName(QString::fromUtf8("settings_layout_envir"));
        settings_label_envir = new QLabel(centralwidget);
        settings_label_envir->setObjectName(QString::fromUtf8("settings_label_envir"));
        settings_label_envir->setMinimumSize(QSize(110, 23));

        settings_layout_envir->addWidget(settings_label_envir);

        settings_lineEdit_envir = new QLineEdit(centralwidget);
        settings_lineEdit_envir->setObjectName(QString::fromUtf8("settings_lineEdit_envir"));

        settings_layout_envir->addWidget(settings_lineEdit_envir);

        settings_pushButton_envir = new QPushButton(centralwidget);
        settings_pushButton_envir->setObjectName(QString::fromUtf8("settings_pushButton_envir"));
        settings_pushButton_envir->setMinimumSize(QSize(80, 23));
        settings_pushButton_envir->setAutoDefault(true);

        settings_layout_envir->addWidget(settings_pushButton_envir);


        verticalLayout->addLayout(settings_layout_envir);

        settings_layout_radf = new QHBoxLayout();
        settings_layout_radf->setObjectName(QString::fromUtf8("settings_layout_radf"));
        settings_label_radf = new QLabel(centralwidget);
        settings_label_radf->setObjectName(QString::fromUtf8("settings_label_radf"));
        settings_label_radf->setMinimumSize(QSize(110, 23));

        settings_layout_radf->addWidget(settings_label_radf);

        settings_lineEdit_radf = new QLineEdit(centralwidget);
        settings_lineEdit_radf->setObjectName(QString::fromUtf8("settings_lineEdit_radf"));

        settings_layout_radf->addWidget(settings_lineEdit_radf);

        settings_pushButton_radf = new QPushButton(centralwidget);
        settings_pushButton_radf->setObjectName(QString::fromUtf8("settings_pushButton_radf"));
        settings_pushButton_radf->setMinimumSize(QSize(80, 23));
        settings_pushButton_radf->setAutoDefault(true);

        settings_layout_radf->addWidget(settings_pushButton_radf);


        verticalLayout->addLayout(settings_layout_radf);

        settings_layout_trj2pdb = new QHBoxLayout();
        settings_layout_trj2pdb->setObjectName(QString::fromUtf8("settings_layout_trj2pdb"));
        settings_label_trj2pdb = new QLabel(centralwidget);
        settings_label_trj2pdb->setObjectName(QString::fromUtf8("settings_label_trj2pdb"));
        settings_label_trj2pdb->setMinimumSize(QSize(110, 23));

        settings_layout_trj2pdb->addWidget(settings_label_trj2pdb);

        settings_lineEdit_trj2pdb = new QLineEdit(centralwidget);
        settings_lineEdit_trj2pdb->setObjectName(QString::fromUtf8("settings_lineEdit_trj2pdb"));

        settings_layout_trj2pdb->addWidget(settings_lineEdit_trj2pdb);

        settings_pushButton_trj2pdb = new QPushButton(centralwidget);
        settings_pushButton_trj2pdb->setObjectName(QString::fromUtf8("settings_pushButton_trj2pdb"));
        settings_pushButton_trj2pdb->setMinimumSize(QSize(80, 23));
        settings_pushButton_trj2pdb->setAutoDefault(true);

        settings_layout_trj2pdb->addWidget(settings_pushButton_trj2pdb);


        verticalLayout->addLayout(settings_layout_trj2pdb);

        settings_layout_agl = new QHBoxLayout();
        settings_layout_agl->setObjectName(QString::fromUtf8("settings_layout_agl"));
        settings_label_agl = new QLabel(centralwidget);
        settings_label_agl->setObjectName(QString::fromUtf8("settings_label_agl"));
        settings_label_agl->setMinimumSize(QSize(110, 0));

        settings_layout_agl->addWidget(settings_label_agl);

        settings_lineEdit_agl = new QLineEdit(centralwidget);
        settings_lineEdit_agl->setObjectName(QString::fromUtf8("settings_lineEdit_agl"));

        settings_layout_agl->addWidget(settings_lineEdit_agl);

        settings_pushButton_agl = new QPushButton(centralwidget);
        settings_pushButton_agl->setObjectName(QString::fromUtf8("settings_pushButton_agl"));
        settings_pushButton_agl->setMinimumSize(QSize(80, 23));
        settings_pushButton_agl->setAutoDefault(true);

        settings_layout_agl->addWidget(settings_pushButton_agl);


        verticalLayout->addLayout(settings_layout_agl);

        settings_layout_lang = new QHBoxLayout();
        settings_layout_lang->setObjectName(QString::fromUtf8("settings_layout_lang"));
        settings_label_lang = new QLabel(centralwidget);
        settings_label_lang->setObjectName(QString::fromUtf8("settings_label_lang"));
        settings_label_lang->setMinimumSize(QSize(110, 23));
        settings_label_lang->setText(QString::fromUtf8("Language"));

        settings_layout_lang->addWidget(settings_label_lang);

        settings_comboBox_lang = new QComboBox(centralwidget);
        settings_comboBox_lang->setObjectName(QString::fromUtf8("settings_comboBox_lang"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(settings_comboBox_lang->sizePolicy().hasHeightForWidth());
        settings_comboBox_lang->setSizePolicy(sizePolicy);

        settings_layout_lang->addWidget(settings_comboBox_lang);


        verticalLayout->addLayout(settings_layout_lang);

        verticalSpacer = new QSpacerItem(20, 51, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        settings_layout_buttons = new QHBoxLayout();
        settings_layout_buttons->setObjectName(QString::fromUtf8("settings_layout_buttons"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        settings_layout_buttons->addItem(horizontalSpacer);

        settings_pushButton_save = new QPushButton(centralwidget);
        settings_pushButton_save->setObjectName(QString::fromUtf8("settings_pushButton_save"));
        settings_pushButton_save->setMinimumSize(QSize(80, 23));
        settings_pushButton_save->setAutoDefault(true);

        settings_layout_buttons->addWidget(settings_pushButton_save);

        settings_pushButton_close = new QPushButton(centralwidget);
        settings_pushButton_close->setObjectName(QString::fromUtf8("settings_pushButton_close"));
        settings_pushButton_close->setMinimumSize(QSize(80, 23));
        settings_pushButton_close->setAutoDefault(true);

        settings_layout_buttons->addWidget(settings_pushButton_close);


        verticalLayout->addLayout(settings_layout_buttons);

        SettingsWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(settings_lineEdit_trj, settings_pushButton_trj);
        QWidget::setTabOrder(settings_pushButton_trj, settings_lineEdit_statgen);
        QWidget::setTabOrder(settings_lineEdit_statgen, settings_pushButton_statgen);
        QWidget::setTabOrder(settings_pushButton_statgen, settings_lineEdit_envir);
        QWidget::setTabOrder(settings_lineEdit_envir, settings_pushButton_envir);
        QWidget::setTabOrder(settings_pushButton_envir, settings_lineEdit_radf);
        QWidget::setTabOrder(settings_lineEdit_radf, settings_pushButton_radf);
        QWidget::setTabOrder(settings_pushButton_radf, settings_lineEdit_trj2pdb);
        QWidget::setTabOrder(settings_lineEdit_trj2pdb, settings_pushButton_trj2pdb);
        QWidget::setTabOrder(settings_pushButton_trj2pdb, settings_lineEdit_agl);
        QWidget::setTabOrder(settings_lineEdit_agl, settings_pushButton_agl);
        QWidget::setTabOrder(settings_pushButton_agl, settings_comboBox_lang);
        QWidget::setTabOrder(settings_comboBox_lang, settings_pushButton_close);
        QWidget::setTabOrder(settings_pushButton_close, settings_pushButton_save);

        retranslateUi(SettingsWindow);
        QObject::connect(settings_pushButton_close, SIGNAL(clicked()), SettingsWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QApplication::translate("SettingsWindow", "Settings", 0, QApplication::UnicodeUTF8));
        settings_label_trj->setText(QApplication::translate("SettingsWindow", "mm_trj", 0, QApplication::UnicodeUTF8));
        settings_pushButton_trj->setText(QApplication::translate("SettingsWindow", "Browse", 0, QApplication::UnicodeUTF8));
        settings_label_statgen->setText(QApplication::translate("SettingsWindow", "mm_statgen", 0, QApplication::UnicodeUTF8));
        settings_pushButton_statgen->setText(QApplication::translate("SettingsWindow", "Browse", 0, QApplication::UnicodeUTF8));
        settings_label_envir->setText(QApplication::translate("SettingsWindow", "mm_envir", 0, QApplication::UnicodeUTF8));
        settings_pushButton_envir->setText(QApplication::translate("SettingsWindow", "Browse", 0, QApplication::UnicodeUTF8));
        settings_label_radf->setText(QApplication::translate("SettingsWindow", "mm_radf", 0, QApplication::UnicodeUTF8));
        settings_pushButton_radf->setText(QApplication::translate("SettingsWindow", "Browse", 0, QApplication::UnicodeUTF8));
        settings_label_trj2pdb->setText(QApplication::translate("SettingsWindow", "mm_trj2pdb", 0, QApplication::UnicodeUTF8));
        settings_pushButton_trj2pdb->setText(QApplication::translate("SettingsWindow", "Browse", 0, QApplication::UnicodeUTF8));
        settings_label_agl->setText(QApplication::translate("SettingsWindow", "mm_agl", 0, QApplication::UnicodeUTF8));
        settings_pushButton_agl->setText(QApplication::translate("SettingsWindow", "Browse", 0, QApplication::UnicodeUTF8));
        settings_comboBox_lang->clear();
        settings_comboBox_lang->insertItems(0, QStringList()
         << QApplication::translate("SettingsWindow", "English", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsWindow", "Russian", 0, QApplication::UnicodeUTF8)
        );
        settings_pushButton_save->setText(QApplication::translate("SettingsWindow", "Save", 0, QApplication::UnicodeUTF8));
        settings_pushButton_close->setText(QApplication::translate("SettingsWindow", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
