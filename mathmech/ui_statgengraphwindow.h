/********************************************************************************
** Form generated from reading UI file 'statgengraphwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATGENGRAPHWINDOW_H
#define UI_STATGENGRAPHWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatgenGraphWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *graph_layout_buttons;
    QSpacerItem *horizontalSpacer;
    QPushButton *graph_pushButton_save;
    QPushButton *graph_pushButton_close;

    void setupUi(QMainWindow *StatgenGraphWindow)
    {
        if (StatgenGraphWindow->objectName().isEmpty())
            StatgenGraphWindow->setObjectName(QString::fromUtf8("StatgenGraphWindow"));
        StatgenGraphWindow->resize(418, 299);
        centralwidget = new QWidget(StatgenGraphWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graph_layout_buttons = new QHBoxLayout();
        graph_layout_buttons->setObjectName(QString::fromUtf8("graph_layout_buttons"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        graph_layout_buttons->addItem(horizontalSpacer);

        graph_pushButton_save = new QPushButton(centralwidget);
        graph_pushButton_save->setObjectName(QString::fromUtf8("graph_pushButton_save"));
        graph_pushButton_save->setMinimumSize(QSize(80, 23));
        graph_pushButton_save->setAutoDefault(true);

        graph_layout_buttons->addWidget(graph_pushButton_save);

        graph_pushButton_close = new QPushButton(centralwidget);
        graph_pushButton_close->setObjectName(QString::fromUtf8("graph_pushButton_close"));
        graph_pushButton_close->setMinimumSize(QSize(80, 23));
        graph_pushButton_close->setAutoDefault(true);

        graph_layout_buttons->addWidget(graph_pushButton_close);


        verticalLayout->addLayout(graph_layout_buttons);

        StatgenGraphWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(graph_pushButton_save, graph_pushButton_close);

        retranslateUi(StatgenGraphWindow);
        QObject::connect(graph_pushButton_close, SIGNAL(clicked()), StatgenGraphWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(StatgenGraphWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StatgenGraphWindow)
    {
        StatgenGraphWindow->setWindowTitle(QApplication::translate("StatgenGraphWindow", "Graph", 0, QApplication::UnicodeUTF8));
        graph_pushButton_save->setText(QApplication::translate("StatgenGraphWindow", "Save", 0, QApplication::UnicodeUTF8));
        graph_pushButton_close->setText(QApplication::translate("StatgenGraphWindow", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StatgenGraphWindow: public Ui_StatgenGraphWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATGENGRAPHWINDOW_H
