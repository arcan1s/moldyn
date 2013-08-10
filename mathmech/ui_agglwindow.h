/********************************************************************************
** Form generated from reading UI file 'agglwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGGLWINDOW_H
#define UI_AGGLWINDOW_H

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
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AgglWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *agl_layout_input;
    QLabel *agl_label_input;
    QLineEdit *agl_lineEdit_input;
    QPushButton *agl_pushButton_input;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QComboBox *agl_comboBox;
    QListWidget *agl_listWidget;
    QTextBrowser *agl_textBrowser;
    QHBoxLayout *agl_layout_output;
    QLabel *agl_label_output;
    QLineEdit *agl_lineEdit_output;
    QPushButton *agl_pushButton_output;
    QHBoxLayout *agl_layout_buttons;
    QPushButton *agl_pushButton_clear;
    QSpacerItem *horizontalSpacer;
    QPushButton *agl_pushButton_create;
    QPushButton *agl_pushButton_close;

    void setupUi(QMainWindow *AgglWindow)
    {
        if (AgglWindow->objectName().isEmpty())
            AgglWindow->setObjectName(QString::fromUtf8("AgglWindow"));
        AgglWindow->resize(396, 400);
        centralwidget = new QWidget(AgglWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        agl_layout_input = new QHBoxLayout();
        agl_layout_input->setObjectName(QString::fromUtf8("agl_layout_input"));
        agl_label_input = new QLabel(centralwidget);
        agl_label_input->setObjectName(QString::fromUtf8("agl_label_input"));
        agl_label_input->setMinimumSize(QSize(110, 23));

        agl_layout_input->addWidget(agl_label_input);

        agl_lineEdit_input = new QLineEdit(centralwidget);
        agl_lineEdit_input->setObjectName(QString::fromUtf8("agl_lineEdit_input"));
        agl_lineEdit_input->setMinimumSize(QSize(100, 23));
        agl_lineEdit_input->setMaximumSize(QSize(16777215, 16777215));

        agl_layout_input->addWidget(agl_lineEdit_input);

        agl_pushButton_input = new QPushButton(centralwidget);
        agl_pushButton_input->setObjectName(QString::fromUtf8("agl_pushButton_input"));
        agl_pushButton_input->setMinimumSize(QSize(80, 23));
        agl_pushButton_input->setAutoDefault(true);

        agl_layout_input->addWidget(agl_pushButton_input);


        verticalLayout->addLayout(agl_layout_input);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(80, 23));
        pushButton->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        agl_comboBox = new QComboBox(centralwidget);
        agl_comboBox->setObjectName(QString::fromUtf8("agl_comboBox"));

        verticalLayout->addWidget(agl_comboBox);

        agl_listWidget = new QListWidget(centralwidget);
        agl_listWidget->setObjectName(QString::fromUtf8("agl_listWidget"));
        agl_listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(agl_listWidget);

        agl_textBrowser = new QTextBrowser(centralwidget);
        agl_textBrowser->setObjectName(QString::fromUtf8("agl_textBrowser"));

        verticalLayout->addWidget(agl_textBrowser);

        agl_layout_output = new QHBoxLayout();
        agl_layout_output->setObjectName(QString::fromUtf8("agl_layout_output"));
        agl_label_output = new QLabel(centralwidget);
        agl_label_output->setObjectName(QString::fromUtf8("agl_label_output"));
        agl_label_output->setMinimumSize(QSize(110, 23));

        agl_layout_output->addWidget(agl_label_output);

        agl_lineEdit_output = new QLineEdit(centralwidget);
        agl_lineEdit_output->setObjectName(QString::fromUtf8("agl_lineEdit_output"));
        agl_lineEdit_output->setMinimumSize(QSize(100, 23));
        agl_lineEdit_output->setMaximumSize(QSize(16777215, 16777215));

        agl_layout_output->addWidget(agl_lineEdit_output);

        agl_pushButton_output = new QPushButton(centralwidget);
        agl_pushButton_output->setObjectName(QString::fromUtf8("agl_pushButton_output"));
        agl_pushButton_output->setMinimumSize(QSize(80, 23));
        agl_pushButton_output->setAutoDefault(true);

        agl_layout_output->addWidget(agl_pushButton_output);


        verticalLayout->addLayout(agl_layout_output);

        agl_layout_buttons = new QHBoxLayout();
        agl_layout_buttons->setObjectName(QString::fromUtf8("agl_layout_buttons"));
        agl_pushButton_clear = new QPushButton(centralwidget);
        agl_pushButton_clear->setObjectName(QString::fromUtf8("agl_pushButton_clear"));
        agl_pushButton_clear->setMinimumSize(QSize(80, 23));
        agl_pushButton_clear->setAutoDefault(true);

        agl_layout_buttons->addWidget(agl_pushButton_clear);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        agl_layout_buttons->addItem(horizontalSpacer);

        agl_pushButton_create = new QPushButton(centralwidget);
        agl_pushButton_create->setObjectName(QString::fromUtf8("agl_pushButton_create"));
        agl_pushButton_create->setMinimumSize(QSize(80, 23));
        agl_pushButton_create->setMaximumSize(QSize(16777215, 16777215));
        agl_pushButton_create->setAutoDefault(true);

        agl_layout_buttons->addWidget(agl_pushButton_create);

        agl_pushButton_close = new QPushButton(centralwidget);
        agl_pushButton_close->setObjectName(QString::fromUtf8("agl_pushButton_close"));
        agl_pushButton_close->setMinimumSize(QSize(80, 23));
        agl_pushButton_close->setAutoDefault(true);

        agl_layout_buttons->addWidget(agl_pushButton_close);


        verticalLayout->addLayout(agl_layout_buttons);

        AgglWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(agl_lineEdit_input, agl_pushButton_input);
        QWidget::setTabOrder(agl_pushButton_input, pushButton);
        QWidget::setTabOrder(pushButton, agl_comboBox);
        QWidget::setTabOrder(agl_comboBox, agl_listWidget);
        QWidget::setTabOrder(agl_listWidget, agl_textBrowser);
        QWidget::setTabOrder(agl_textBrowser, agl_lineEdit_output);
        QWidget::setTabOrder(agl_lineEdit_output, agl_pushButton_output);
        QWidget::setTabOrder(agl_pushButton_output, agl_pushButton_clear);
        QWidget::setTabOrder(agl_pushButton_clear, agl_pushButton_create);
        QWidget::setTabOrder(agl_pushButton_create, agl_pushButton_close);

        retranslateUi(AgglWindow);
        QObject::connect(agl_pushButton_close, SIGNAL(clicked()), AgglWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(AgglWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AgglWindow)
    {
        AgglWindow->setWindowTitle(QApplication::translate("AgglWindow", "Agglomerate", 0, QApplication::UnicodeUTF8));
        agl_label_input->setText(QApplication::translate("AgglWindow", "Input file", 0, QApplication::UnicodeUTF8));
        agl_pushButton_input->setText(QApplication::translate("AgglWindow", "Browse", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AgglWindow", "Select", 0, QApplication::UnicodeUTF8));
        agl_label_output->setText(QApplication::translate("AgglWindow", "Output file", 0, QApplication::UnicodeUTF8));
        agl_pushButton_output->setText(QApplication::translate("AgglWindow", "Browse", 0, QApplication::UnicodeUTF8));
        agl_pushButton_clear->setText(QApplication::translate("AgglWindow", "Clear", 0, QApplication::UnicodeUTF8));
        agl_pushButton_create->setText(QApplication::translate("AgglWindow", "Create", 0, QApplication::UnicodeUTF8));
        agl_pushButton_close->setText(QApplication::translate("AgglWindow", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AgglWindow: public Ui_AgglWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGGLWINDOW_H
