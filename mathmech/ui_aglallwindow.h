/********************************************************************************
** Form generated from reading UI file 'aglallwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGLALLWINDOW_H
#define UI_AGLALLWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AglAllWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *aglall_layout_workDir;
    QLabel *aglall_label_workDir;
    QLineEdit *aglall_lineEdit_workDir;
    QPushButton *aglall_pushButton_workDir;
    QHBoxLayout *aglall_layout_input;
    QLabel *aglall_label_input;
    QLineEdit *aglall_lineEdit_input;
    QPushButton *pdb_pushButton_input;
    QHBoxLayout *aglall_layout_output;
    QLabel *aglall_label_output;
    QLineEdit *aglall_lineEdit_output;
    QPushButton *aglall_pushButton_output;
    QHBoxLayout *aglall_layout_num;
    QLabel *aglall_label_file;
    QSpinBox *aglall_spinBox_file;
    QSpacerItem *horizontalSpacer;
    QLabel *aglall_label_num;
    QSpinBox *aglall_spinBox_num;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *aglall_layout_buttons;
    QPushButton *aglall_pushButton_clear;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *aglall_pushButton_start;
    QPushButton *aglall_pushButton_close;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AglAllWindow)
    {
        if (AglAllWindow->objectName().isEmpty())
            AglAllWindow->setObjectName(QString::fromUtf8("AglAllWindow"));
        AglAllWindow->resize(502, 260);
        centralwidget = new QWidget(AglAllWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        aglall_layout_workDir = new QHBoxLayout();
        aglall_layout_workDir->setObjectName(QString::fromUtf8("aglall_layout_workDir"));
        aglall_label_workDir = new QLabel(centralwidget);
        aglall_label_workDir->setObjectName(QString::fromUtf8("aglall_label_workDir"));
        aglall_label_workDir->setMinimumSize(QSize(110, 23));

        aglall_layout_workDir->addWidget(aglall_label_workDir);

        aglall_lineEdit_workDir = new QLineEdit(centralwidget);
        aglall_lineEdit_workDir->setObjectName(QString::fromUtf8("aglall_lineEdit_workDir"));
        aglall_lineEdit_workDir->setMinimumSize(QSize(280, 23));

        aglall_layout_workDir->addWidget(aglall_lineEdit_workDir);

        aglall_pushButton_workDir = new QPushButton(centralwidget);
        aglall_pushButton_workDir->setObjectName(QString::fromUtf8("aglall_pushButton_workDir"));
        aglall_pushButton_workDir->setMinimumSize(QSize(80, 23));
        aglall_pushButton_workDir->setAutoDefault(true);

        aglall_layout_workDir->addWidget(aglall_pushButton_workDir);


        verticalLayout->addLayout(aglall_layout_workDir);

        aglall_layout_input = new QHBoxLayout();
        aglall_layout_input->setObjectName(QString::fromUtf8("aglall_layout_input"));
        aglall_label_input = new QLabel(centralwidget);
        aglall_label_input->setObjectName(QString::fromUtf8("aglall_label_input"));
        aglall_label_input->setMinimumSize(QSize(110, 23));

        aglall_layout_input->addWidget(aglall_label_input);

        aglall_lineEdit_input = new QLineEdit(centralwidget);
        aglall_lineEdit_input->setObjectName(QString::fromUtf8("aglall_lineEdit_input"));
        aglall_lineEdit_input->setMinimumSize(QSize(280, 23));

        aglall_layout_input->addWidget(aglall_lineEdit_input);

        pdb_pushButton_input = new QPushButton(centralwidget);
        pdb_pushButton_input->setObjectName(QString::fromUtf8("pdb_pushButton_input"));
        pdb_pushButton_input->setMinimumSize(QSize(80, 23));
        pdb_pushButton_input->setAutoDefault(true);

        aglall_layout_input->addWidget(pdb_pushButton_input);


        verticalLayout->addLayout(aglall_layout_input);

        aglall_layout_output = new QHBoxLayout();
        aglall_layout_output->setObjectName(QString::fromUtf8("aglall_layout_output"));
        aglall_label_output = new QLabel(centralwidget);
        aglall_label_output->setObjectName(QString::fromUtf8("aglall_label_output"));
        aglall_label_output->setMinimumSize(QSize(110, 23));

        aglall_layout_output->addWidget(aglall_label_output);

        aglall_lineEdit_output = new QLineEdit(centralwidget);
        aglall_lineEdit_output->setObjectName(QString::fromUtf8("aglall_lineEdit_output"));
        aglall_lineEdit_output->setMinimumSize(QSize(280, 23));

        aglall_layout_output->addWidget(aglall_lineEdit_output);

        aglall_pushButton_output = new QPushButton(centralwidget);
        aglall_pushButton_output->setObjectName(QString::fromUtf8("aglall_pushButton_output"));
        aglall_pushButton_output->setMinimumSize(QSize(80, 23));
        aglall_pushButton_output->setAutoDefault(true);

        aglall_layout_output->addWidget(aglall_pushButton_output);


        verticalLayout->addLayout(aglall_layout_output);

        aglall_layout_num = new QHBoxLayout();
        aglall_layout_num->setObjectName(QString::fromUtf8("aglall_layout_num"));
        aglall_label_file = new QLabel(centralwidget);
        aglall_label_file->setObjectName(QString::fromUtf8("aglall_label_file"));
        aglall_label_file->setMinimumSize(QSize(110, 23));

        aglall_layout_num->addWidget(aglall_label_file);

        aglall_spinBox_file = new QSpinBox(centralwidget);
        aglall_spinBox_file->setObjectName(QString::fromUtf8("aglall_spinBox_file"));
        aglall_spinBox_file->setMinimumSize(QSize(75, 23));
        aglall_spinBox_file->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        aglall_spinBox_file->setMaximum(999);

        aglall_layout_num->addWidget(aglall_spinBox_file);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        aglall_layout_num->addItem(horizontalSpacer);

        aglall_label_num = new QLabel(centralwidget);
        aglall_label_num->setObjectName(QString::fromUtf8("aglall_label_num"));
        aglall_label_num->setMinimumSize(QSize(150, 23));

        aglall_layout_num->addWidget(aglall_label_num);

        aglall_spinBox_num = new QSpinBox(centralwidget);
        aglall_spinBox_num->setObjectName(QString::fromUtf8("aglall_spinBox_num"));
        aglall_spinBox_num->setMinimumSize(QSize(75, 23));
        aglall_spinBox_num->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        aglall_layout_num->addWidget(aglall_spinBox_num);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        aglall_layout_num->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(aglall_layout_num);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        aglall_layout_buttons = new QHBoxLayout();
        aglall_layout_buttons->setObjectName(QString::fromUtf8("aglall_layout_buttons"));
        aglall_pushButton_clear = new QPushButton(centralwidget);
        aglall_pushButton_clear->setObjectName(QString::fromUtf8("aglall_pushButton_clear"));
        aglall_pushButton_clear->setMinimumSize(QSize(80, 23));
        aglall_pushButton_clear->setAutoDefault(true);

        aglall_layout_buttons->addWidget(aglall_pushButton_clear);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        aglall_layout_buttons->addItem(horizontalSpacer_15);

        aglall_pushButton_start = new QPushButton(centralwidget);
        aglall_pushButton_start->setObjectName(QString::fromUtf8("aglall_pushButton_start"));
        aglall_pushButton_start->setMinimumSize(QSize(80, 23));
        aglall_pushButton_start->setMaximumSize(QSize(16777215, 16777215));
        aglall_pushButton_start->setAutoDefault(true);

        aglall_layout_buttons->addWidget(aglall_pushButton_start);

        aglall_pushButton_close = new QPushButton(centralwidget);
        aglall_pushButton_close->setObjectName(QString::fromUtf8("aglall_pushButton_close"));
        aglall_pushButton_close->setMinimumSize(QSize(80, 23));
        aglall_pushButton_close->setAutoDefault(true);

        aglall_layout_buttons->addWidget(aglall_pushButton_close);


        verticalLayout->addLayout(aglall_layout_buttons);

        AglAllWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(AglAllWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AglAllWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(aglall_lineEdit_workDir, aglall_pushButton_workDir);
        QWidget::setTabOrder(aglall_pushButton_workDir, aglall_lineEdit_input);
        QWidget::setTabOrder(aglall_lineEdit_input, pdb_pushButton_input);
        QWidget::setTabOrder(pdb_pushButton_input, aglall_lineEdit_output);
        QWidget::setTabOrder(aglall_lineEdit_output, aglall_pushButton_output);
        QWidget::setTabOrder(aglall_pushButton_output, aglall_spinBox_file);
        QWidget::setTabOrder(aglall_spinBox_file, aglall_spinBox_num);
        QWidget::setTabOrder(aglall_spinBox_num, aglall_pushButton_clear);
        QWidget::setTabOrder(aglall_pushButton_clear, aglall_pushButton_start);
        QWidget::setTabOrder(aglall_pushButton_start, aglall_pushButton_close);

        retranslateUi(AglAllWindow);
        QObject::connect(aglall_pushButton_close, SIGNAL(clicked()), AglAllWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(AglAllWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AglAllWindow)
    {
        AglAllWindow->setWindowTitle(QApplication::translate("AglAllWindow", "agl_all", 0, QApplication::UnicodeUTF8));
        aglall_label_workDir->setText(QApplication::translate("AglAllWindow", "Work directory", 0, QApplication::UnicodeUTF8));
        aglall_pushButton_workDir->setText(QApplication::translate("AglAllWindow", "Browse", 0, QApplication::UnicodeUTF8));
        aglall_label_input->setText(QApplication::translate("AglAllWindow", "Input file", 0, QApplication::UnicodeUTF8));
        pdb_pushButton_input->setText(QApplication::translate("AglAllWindow", "Browse", 0, QApplication::UnicodeUTF8));
        aglall_label_output->setText(QApplication::translate("AglAllWindow", "Mask of output files", 0, QApplication::UnicodeUTF8));
        aglall_pushButton_output->setText(QApplication::translate("AglAllWindow", "Browse", 0, QApplication::UnicodeUTF8));
        aglall_label_file->setText(QApplication::translate("AglAllWindow", "File", 0, QApplication::UnicodeUTF8));
        aglall_label_num->setText(QApplication::translate("AglAllWindow", "Number of molecules", 0, QApplication::UnicodeUTF8));
        aglall_pushButton_clear->setText(QApplication::translate("AglAllWindow", "Clear", 0, QApplication::UnicodeUTF8));
        aglall_pushButton_start->setText(QApplication::translate("AglAllWindow", "Start", 0, QApplication::UnicodeUTF8));
        aglall_pushButton_close->setText(QApplication::translate("AglAllWindow", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AglAllWindow: public Ui_AglAllWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGLALLWINDOW_H
