/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionAtom_types_file;
    QAction *actionAgglomerate_file;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *trj;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *trj_layout_workDir;
    QLabel *trj_label_workDir;
    QLineEdit *trj_lineEdit_workDir;
    QPushButton *trj_pushButton_workDir;
    QHBoxLayout *trj_layout_input;
    QLabel *trj_label_input;
    QLineEdit *trj_lineEdit_input;
    QPushButton *trj_pushButton_input;
    QHBoxLayout *trj_layout_opt_1;
    QLabel *trj_label_type;
    QComboBox *trj_comboBox_type;
    QSpacerItem *horizontalSpacer_2;
    QLabel *trj_label_steps;
    QSpinBox *trj_spinBox_steps;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *trj_layout_atoms;
    QLabel *trj_label_atoms;
    QLineEdit *trj_lineEdit_atoms;
    QPushButton *trj_pushButton_atoms;
    QHBoxLayout *trj_layout_output;
    QLabel *trj_label_output;
    QLineEdit *trj_lineEdit_output;
    QHBoxLayout *trj_layout_opt_2;
    QLabel *trj_label_totalTypes;
    QSpinBox *trj_spinBox_totalTypes;
    QCheckBox *trj_checkBox_log;
    QLineEdit *trj_lineEdit_log;
    QPushButton *trj_pushButton_log;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *trj_layout_buttons;
    QPushButton *trj_pushButton_clear;
    QSpacerItem *horizontalSpacer;
    QPushButton *trj_pushButton_start;
    QWidget *statgen;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *statgen_layout_workDir;
    QLabel *statgen_label_workDir;
    QLineEdit *statgen_lineEdit_workDir;
    QPushButton *statgen_pushButton_workDir;
    QHBoxLayout *statgen_layout_input;
    QLabel *statgen_label_input;
    QLineEdit *statgen_lineEdit_input;
    QHBoxLayout *statgen_layout_steps;
    QLabel *statgen_label_steps;
    QLabel *statgen_label_stepsFirst;
    QSpinBox *statgen_spinBox_stepsFirst;
    QSpacerItem *horizontalSpacer_4;
    QLabel *statgen_label_stepsLast;
    QSpinBox *statgen_spinBox_stepsLast;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *statgen_layout_cell;
    QLabel *statgen_label_cell;
    QLabel *statgen_label_cellX;
    QDoubleSpinBox *statgen_doubleSpinBox_cellX;
    QLabel *statgen_label_cellY;
    QDoubleSpinBox *statgen_doubleSpinBox_cellY;
    QLabel *statgen_label_cellZ;
    QDoubleSpinBox *statgen_doubleSpinBox_cellZ;
    QHBoxLayout *statgen_layout_atoms;
    QLabel *statgen_label_atoms0;
    QSpinBox *statgen_spinBox_atoms0;
    QCheckBox *statgen_checkBox_atoms1;
    QSpinBox *statgen_spinBox_atoms1;
    QCheckBox *statgen_checkBox_atoms2;
    QSpinBox *statgen_spinBox_atoms2;
    QCheckBox *statgen_checkBox_atoms3;
    QSpinBox *statgen_spinBox_atoms3;
    QHBoxLayout *statgen_layout_int;
    QLabel *statgen_label_int;
    QComboBox *statgen_comboBox_int;
    QDoubleSpinBox *statgen_doubleSpinBox_int;
    QPushButton *stagen_pushButton_intSave;
    QPushButton *statgen_pushButton_intAdd;
    QListWidget *statgen_listWidget_int;
    QHBoxLayout *stagen_layout_intRem;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *stagen_pushButton_intRem;
    QHBoxLayout *statgen_layout_output;
    QLabel *statgen_label_output;
    QLineEdit *statgen_lineEdit_output;
    QPushButton *statgen_pushButton_output;
    QHBoxLayout *statgen_layout_opt;
    QCheckBox *statgen_checkBox_depth;
    QSpinBox *statgen_spinBox_depth;
    QCheckBox *statgen_checkBox_log;
    QLineEdit *statgen_lineEdit_log;
    QPushButton *statgen_pushButton_log;
    QHBoxLayout *statgen_layout_buttons;
    QPushButton *statgen_pushButton_clear;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *statgen_pushButton_start;
    QWidget *envir;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *envir_layout_workDir;
    QLabel *envir_label_workDir;
    QLineEdit *envir_lineEdit_workDir;
    QPushButton *envir_pushButton_workDir;
    QHBoxLayout *envir_layout_input;
    QLabel *envir_label_input;
    QLineEdit *envir_lineEdit_input;
    QPushButton *envir_pushButton_input;
    QHBoxLayout *envir_layout_cell;
    QLabel *envir_label_cell;
    QLabel *envir_label_cellX;
    QDoubleSpinBox *envir_doubleSpinBox_cellX;
    QLabel *envir_label_cellY;
    QDoubleSpinBox *envir_doubleSpinBox_cellY;
    QLabel *envir_label_cellZ;
    QDoubleSpinBox *envir_doubleSpinBox_cellZ;
    QHBoxLayout *envir_layout_output;
    QLabel *envir_label_output;
    QLineEdit *envir_lineEdit_output;
    QPushButton *envir_pushButton_output;
    QHBoxLayout *envir_layout_opt_1;
    QLabel *envir_label_molecule;
    QSpinBox *envir_spinBox_molecule;
    QSpacerItem *horizontalSpacer_8;
    QLabel *envir_label_radius;
    QDoubleSpinBox *envir_doubleSpinBox_radius;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *envir_layout_opt_2;
    QCheckBox *envir_checkBox_log;
    QLineEdit *envir_lineEdit_log;
    QPushButton *envir_pushButton_log;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *envir_layout_buttons;
    QPushButton *envir_pushButton_clear;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *envir_pushButton_start;
    QWidget *radf;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *radf_layout_workDir;
    QLabel *radf_label_workDir;
    QLineEdit *radf_lineEdit_workDir;
    QPushButton *radf_pushButton_workDir;
    QHBoxLayout *radf_layout_input;
    QLabel *radf_label_input;
    QLineEdit *radf_lineEdit_input;
    QHBoxLayout *radf_layout_steps;
    QLabel *radf_label_steps;
    QLabel *radf_label_stepsFirst;
    QSpinBox *radf_spinBox_stepsFirst;
    QSpacerItem *horizontalSpacer_11;
    QLabel *radf_label_stepsLast;
    QSpinBox *radf_spinBox_stepsLast;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *radf_layout_cell;
    QLabel *radf_label_cell;
    QLabel *radf_label_cellX;
    QDoubleSpinBox *radf_doubleSpinBox_cellX;
    QLabel *radf_label_cellY;
    QDoubleSpinBox *radf_doubleSpinBox_cellY;
    QLabel *radf_label_cellZ;
    QDoubleSpinBox *radf_doubleSpinBox_cellZ;
    QHBoxLayout *radf_layout_output;
    QLabel *radf_label_output;
    QLineEdit *radf_lineEdit_output;
    QPushButton *radf_pushButton_output;
    QHBoxLayout *radf_layout_atom1;
    QComboBox *radf_comboBox_atom;
    QLabel *radf_label_atoms0;
    QSpinBox *radf_spinBox_atoms0;
    QLabel *radf_label_atoms1;
    QSpinBox *radf_spinBox_atoms1;
    QLabel *radf_label_atoms2;
    QSpinBox *radf_spinBox_atoms2;
    QHBoxLayout *radf_layout_atom2;
    QSpacerItem *horizontalSpacer_14;
    QLabel *radf_label_atoms3;
    QSpinBox *radf_spinBox_atoms3;
    QLabel *radf_label_atoms4;
    QSpinBox *radf_spinBox_atoms4;
    QLabel *radf_label_atoms5;
    QSpinBox *radf_spinBox_atoms5;
    QHBoxLayout *radf_layout_rad;
    QLabel *radf_label_rad;
    QLabel *radf_label_radMin;
    QDoubleSpinBox *radf_doubleSpinBox_radMin;
    QLabel *radf_label_radMax;
    QDoubleSpinBox *radf_doubleSpinBox_radMax;
    QLabel *radf_label_radStep;
    QDoubleSpinBox *radf_doubleSpinBox_radStep;
    QHBoxLayout *radf_layout_ang;
    QCheckBox *radf_checkBox_ang;
    QLabel *radf_label_angMin;
    QDoubleSpinBox *radf_doubleSpinBox_angMin;
    QLabel *radf_label_angMax;
    QDoubleSpinBox *radf_doubleSpinBox_angMax;
    QLabel *radf_label_angStep;
    QDoubleSpinBox *radf_doubleSpinBox_angStep;
    QHBoxLayout *radf_layout_opt;
    QCheckBox *radf_checkBox_matrix;
    QCheckBox *radf_checkBox_log;
    QLineEdit *radf_lineEdit_log;
    QPushButton *radf_pushButton_log;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *radf_layout_buttons;
    QPushButton *radf_pushButton_clear;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *radf_pushButton_start;
    QWidget *pdb;
    QVBoxLayout *verticalLayout_5;
    QComboBox *pdb_comboBox_mode;
    QHBoxLayout *pdb_layout_workDir;
    QLabel *pdb_label_workDir;
    QLineEdit *pdb_lineEdit_workDir;
    QPushButton *pdb_pushButton_workDir;
    QHBoxLayout *pdb_layout_input;
    QLabel *pdb_label_input;
    QLineEdit *pdb_lineEdit_input;
    QPushButton *pdb_pushButton_input;
    QHBoxLayout *pdb_layout_agl;
    QLabel *pdb_label_agl;
    QLineEdit *pdb_lineEdit_agl;
    QPushButton *pdb_pushButton_agl;
    QHBoxLayout *pdb_layout_cell;
    QLabel *pdb_label_cell;
    QLabel *pdb_label_cellX;
    QDoubleSpinBox *pdb_doubleSpinBox_cellX;
    QLabel *pdb_label_cellY;
    QDoubleSpinBox *pdb_doubleSpinBox_cellY;
    QLabel *pdb_label_cellZ;
    QDoubleSpinBox *pdb_doubleSpinBox_cellZ;
    QHBoxLayout *pdb_layout_output;
    QLabel *pdb_label_output;
    QLineEdit *pdb_lineEdit_output;
    QPushButton *pdb_pushButton_output;
    QHBoxLayout *pdb_layout_opt;
    QCheckBox *pdb_checkBox_log;
    QLineEdit *pdb_lineEdit_log;
    QPushButton *pdb_pushButton_log;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *pdb_layout_buttons;
    QPushButton *pdb_pushButton_clear;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *pdb_pushButton_start;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuFile_creator;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(564, 554);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAtom_types_file = new QAction(MainWindow);
        actionAtom_types_file->setObjectName(QString::fromUtf8("actionAtom_types_file"));
        actionAgglomerate_file = new QAction(MainWindow);
        actionAgglomerate_file->setObjectName(QString::fromUtf8("actionAgglomerate_file"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        trj = new QWidget();
        trj->setObjectName(QString::fromUtf8("trj"));
        verticalLayout = new QVBoxLayout(trj);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        trj_layout_workDir = new QHBoxLayout();
        trj_layout_workDir->setSpacing(6);
        trj_layout_workDir->setObjectName(QString::fromUtf8("trj_layout_workDir"));
        trj_label_workDir = new QLabel(trj);
        trj_label_workDir->setObjectName(QString::fromUtf8("trj_label_workDir"));
        trj_label_workDir->setMinimumSize(QSize(110, 23));

        trj_layout_workDir->addWidget(trj_label_workDir);

        trj_lineEdit_workDir = new QLineEdit(trj);
        trj_lineEdit_workDir->setObjectName(QString::fromUtf8("trj_lineEdit_workDir"));
        trj_lineEdit_workDir->setMinimumSize(QSize(280, 23));

        trj_layout_workDir->addWidget(trj_lineEdit_workDir);

        trj_pushButton_workDir = new QPushButton(trj);
        trj_pushButton_workDir->setObjectName(QString::fromUtf8("trj_pushButton_workDir"));
        trj_pushButton_workDir->setMinimumSize(QSize(80, 23));
        trj_pushButton_workDir->setAutoDefault(true);

        trj_layout_workDir->addWidget(trj_pushButton_workDir);


        verticalLayout->addLayout(trj_layout_workDir);

        trj_layout_input = new QHBoxLayout();
        trj_layout_input->setSpacing(6);
        trj_layout_input->setObjectName(QString::fromUtf8("trj_layout_input"));
        trj_label_input = new QLabel(trj);
        trj_label_input->setObjectName(QString::fromUtf8("trj_label_input"));
        trj_label_input->setMinimumSize(QSize(110, 23));

        trj_layout_input->addWidget(trj_label_input);

        trj_lineEdit_input = new QLineEdit(trj);
        trj_lineEdit_input->setObjectName(QString::fromUtf8("trj_lineEdit_input"));
        trj_lineEdit_input->setMinimumSize(QSize(280, 23));

        trj_layout_input->addWidget(trj_lineEdit_input);

        trj_pushButton_input = new QPushButton(trj);
        trj_pushButton_input->setObjectName(QString::fromUtf8("trj_pushButton_input"));
        trj_pushButton_input->setMinimumSize(QSize(80, 23));
        trj_pushButton_input->setAutoDefault(true);

        trj_layout_input->addWidget(trj_pushButton_input);


        verticalLayout->addLayout(trj_layout_input);

        trj_layout_opt_1 = new QHBoxLayout();
        trj_layout_opt_1->setSpacing(6);
        trj_layout_opt_1->setObjectName(QString::fromUtf8("trj_layout_opt_1"));
        trj_label_type = new QLabel(trj);
        trj_label_type->setObjectName(QString::fromUtf8("trj_label_type"));
        trj_label_type->setMinimumSize(QSize(110, 23));

        trj_layout_opt_1->addWidget(trj_label_type);

        trj_comboBox_type = new QComboBox(trj);
        trj_comboBox_type->setObjectName(QString::fromUtf8("trj_comboBox_type"));
        trj_comboBox_type->setMinimumSize(QSize(130, 23));

        trj_layout_opt_1->addWidget(trj_comboBox_type);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        trj_layout_opt_1->addItem(horizontalSpacer_2);

        trj_label_steps = new QLabel(trj);
        trj_label_steps->setObjectName(QString::fromUtf8("trj_label_steps"));
        trj_label_steps->setMinimumSize(QSize(110, 23));

        trj_layout_opt_1->addWidget(trj_label_steps);

        trj_spinBox_steps = new QSpinBox(trj);
        trj_spinBox_steps->setObjectName(QString::fromUtf8("trj_spinBox_steps"));
        trj_spinBox_steps->setMinimumSize(QSize(75, 23));
        trj_spinBox_steps->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        trj_spinBox_steps->setMinimum(1);
        trj_spinBox_steps->setMaximum(999);

        trj_layout_opt_1->addWidget(trj_spinBox_steps);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        trj_layout_opt_1->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(trj_layout_opt_1);

        trj_layout_atoms = new QHBoxLayout();
        trj_layout_atoms->setSpacing(6);
        trj_layout_atoms->setObjectName(QString::fromUtf8("trj_layout_atoms"));
        trj_label_atoms = new QLabel(trj);
        trj_label_atoms->setObjectName(QString::fromUtf8("trj_label_atoms"));
        trj_label_atoms->setMinimumSize(QSize(110, 23));

        trj_layout_atoms->addWidget(trj_label_atoms);

        trj_lineEdit_atoms = new QLineEdit(trj);
        trj_lineEdit_atoms->setObjectName(QString::fromUtf8("trj_lineEdit_atoms"));
        trj_lineEdit_atoms->setMinimumSize(QSize(280, 23));

        trj_layout_atoms->addWidget(trj_lineEdit_atoms);

        trj_pushButton_atoms = new QPushButton(trj);
        trj_pushButton_atoms->setObjectName(QString::fromUtf8("trj_pushButton_atoms"));
        trj_pushButton_atoms->setMinimumSize(QSize(80, 23));
        trj_pushButton_atoms->setAutoDefault(true);

        trj_layout_atoms->addWidget(trj_pushButton_atoms);


        verticalLayout->addLayout(trj_layout_atoms);

        trj_layout_output = new QHBoxLayout();
        trj_layout_output->setSpacing(6);
        trj_layout_output->setObjectName(QString::fromUtf8("trj_layout_output"));
        trj_label_output = new QLabel(trj);
        trj_label_output->setObjectName(QString::fromUtf8("trj_label_output"));
        trj_label_output->setMinimumSize(QSize(110, 23));

        trj_layout_output->addWidget(trj_label_output);

        trj_lineEdit_output = new QLineEdit(trj);
        trj_lineEdit_output->setObjectName(QString::fromUtf8("trj_lineEdit_output"));
        trj_lineEdit_output->setMinimumSize(QSize(365, 23));

        trj_layout_output->addWidget(trj_lineEdit_output);


        verticalLayout->addLayout(trj_layout_output);

        trj_layout_opt_2 = new QHBoxLayout();
        trj_layout_opt_2->setSpacing(6);
        trj_layout_opt_2->setObjectName(QString::fromUtf8("trj_layout_opt_2"));
        trj_label_totalTypes = new QLabel(trj);
        trj_label_totalTypes->setObjectName(QString::fromUtf8("trj_label_totalTypes"));
        trj_label_totalTypes->setMinimumSize(QSize(110, 23));

        trj_layout_opt_2->addWidget(trj_label_totalTypes);

        trj_spinBox_totalTypes = new QSpinBox(trj);
        trj_spinBox_totalTypes->setObjectName(QString::fromUtf8("trj_spinBox_totalTypes"));
        trj_spinBox_totalTypes->setMinimumSize(QSize(80, 23));
        trj_spinBox_totalTypes->setLayoutDirection(Qt::LeftToRight);
        trj_spinBox_totalTypes->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        trj_spinBox_totalTypes->setMinimum(1024);
        trj_spinBox_totalTypes->setMaximum(999999);

        trj_layout_opt_2->addWidget(trj_spinBox_totalTypes);

        trj_checkBox_log = new QCheckBox(trj);
        trj_checkBox_log->setObjectName(QString::fromUtf8("trj_checkBox_log"));
        trj_checkBox_log->setMinimumSize(QSize(110, 23));
        trj_checkBox_log->setChecked(true);

        trj_layout_opt_2->addWidget(trj_checkBox_log);

        trj_lineEdit_log = new QLineEdit(trj);
        trj_lineEdit_log->setObjectName(QString::fromUtf8("trj_lineEdit_log"));
        trj_lineEdit_log->setMinimumSize(QSize(80, 23));

        trj_layout_opt_2->addWidget(trj_lineEdit_log);

        trj_pushButton_log = new QPushButton(trj);
        trj_pushButton_log->setObjectName(QString::fromUtf8("trj_pushButton_log"));
        trj_pushButton_log->setMinimumSize(QSize(80, 23));
        trj_pushButton_log->setAutoDefault(true);

        trj_layout_opt_2->addWidget(trj_pushButton_log);


        verticalLayout->addLayout(trj_layout_opt_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        trj_layout_buttons = new QHBoxLayout();
        trj_layout_buttons->setSpacing(6);
        trj_layout_buttons->setObjectName(QString::fromUtf8("trj_layout_buttons"));
        trj_pushButton_clear = new QPushButton(trj);
        trj_pushButton_clear->setObjectName(QString::fromUtf8("trj_pushButton_clear"));
        trj_pushButton_clear->setMinimumSize(QSize(80, 23));
        trj_pushButton_clear->setAutoDefault(true);

        trj_layout_buttons->addWidget(trj_pushButton_clear);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        trj_layout_buttons->addItem(horizontalSpacer);

        trj_pushButton_start = new QPushButton(trj);
        trj_pushButton_start->setObjectName(QString::fromUtf8("trj_pushButton_start"));
        trj_pushButton_start->setMinimumSize(QSize(80, 23));
        trj_pushButton_start->setMaximumSize(QSize(16777215, 16777215));
        trj_pushButton_start->setAutoDefault(true);

        trj_layout_buttons->addWidget(trj_pushButton_start);


        verticalLayout->addLayout(trj_layout_buttons);

        tabWidget->addTab(trj, QString());
        statgen = new QWidget();
        statgen->setObjectName(QString::fromUtf8("statgen"));
        verticalLayout_2 = new QVBoxLayout(statgen);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        statgen_layout_workDir = new QHBoxLayout();
        statgen_layout_workDir->setSpacing(6);
        statgen_layout_workDir->setObjectName(QString::fromUtf8("statgen_layout_workDir"));
        statgen_label_workDir = new QLabel(statgen);
        statgen_label_workDir->setObjectName(QString::fromUtf8("statgen_label_workDir"));
        statgen_label_workDir->setMinimumSize(QSize(110, 23));

        statgen_layout_workDir->addWidget(statgen_label_workDir);

        statgen_lineEdit_workDir = new QLineEdit(statgen);
        statgen_lineEdit_workDir->setObjectName(QString::fromUtf8("statgen_lineEdit_workDir"));
        statgen_lineEdit_workDir->setMinimumSize(QSize(280, 23));

        statgen_layout_workDir->addWidget(statgen_lineEdit_workDir);

        statgen_pushButton_workDir = new QPushButton(statgen);
        statgen_pushButton_workDir->setObjectName(QString::fromUtf8("statgen_pushButton_workDir"));
        statgen_pushButton_workDir->setMinimumSize(QSize(80, 23));
        statgen_pushButton_workDir->setAutoDefault(true);

        statgen_layout_workDir->addWidget(statgen_pushButton_workDir);


        verticalLayout_2->addLayout(statgen_layout_workDir);

        statgen_layout_input = new QHBoxLayout();
        statgen_layout_input->setSpacing(6);
        statgen_layout_input->setObjectName(QString::fromUtf8("statgen_layout_input"));
        statgen_label_input = new QLabel(statgen);
        statgen_label_input->setObjectName(QString::fromUtf8("statgen_label_input"));
        statgen_label_input->setMinimumSize(QSize(110, 23));

        statgen_layout_input->addWidget(statgen_label_input);

        statgen_lineEdit_input = new QLineEdit(statgen);
        statgen_lineEdit_input->setObjectName(QString::fromUtf8("statgen_lineEdit_input"));
        statgen_lineEdit_input->setMinimumSize(QSize(280, 23));

        statgen_layout_input->addWidget(statgen_lineEdit_input);


        verticalLayout_2->addLayout(statgen_layout_input);

        statgen_layout_steps = new QHBoxLayout();
        statgen_layout_steps->setSpacing(6);
        statgen_layout_steps->setObjectName(QString::fromUtf8("statgen_layout_steps"));
        statgen_label_steps = new QLabel(statgen);
        statgen_label_steps->setObjectName(QString::fromUtf8("statgen_label_steps"));
        statgen_label_steps->setMinimumSize(QSize(110, 23));

        statgen_layout_steps->addWidget(statgen_label_steps);

        statgen_label_stepsFirst = new QLabel(statgen);
        statgen_label_stepsFirst->setObjectName(QString::fromUtf8("statgen_label_stepsFirst"));
        statgen_label_stepsFirst->setMinimumSize(QSize(75, 23));

        statgen_layout_steps->addWidget(statgen_label_stepsFirst);

        statgen_spinBox_stepsFirst = new QSpinBox(statgen);
        statgen_spinBox_stepsFirst->setObjectName(QString::fromUtf8("statgen_spinBox_stepsFirst"));
        statgen_spinBox_stepsFirst->setMinimumSize(QSize(75, 23));
        statgen_spinBox_stepsFirst->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        statgen_spinBox_stepsFirst->setMinimum(1);
        statgen_spinBox_stepsFirst->setMaximum(999);

        statgen_layout_steps->addWidget(statgen_spinBox_stepsFirst);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        statgen_layout_steps->addItem(horizontalSpacer_4);

        statgen_label_stepsLast = new QLabel(statgen);
        statgen_label_stepsLast->setObjectName(QString::fromUtf8("statgen_label_stepsLast"));
        statgen_label_stepsLast->setMinimumSize(QSize(75, 23));

        statgen_layout_steps->addWidget(statgen_label_stepsLast);

        statgen_spinBox_stepsLast = new QSpinBox(statgen);
        statgen_spinBox_stepsLast->setObjectName(QString::fromUtf8("statgen_spinBox_stepsLast"));
        statgen_spinBox_stepsLast->setMinimumSize(QSize(75, 23));
        statgen_spinBox_stepsLast->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        statgen_spinBox_stepsLast->setMinimum(1);
        statgen_spinBox_stepsLast->setMaximum(999);

        statgen_layout_steps->addWidget(statgen_spinBox_stepsLast);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        statgen_layout_steps->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(statgen_layout_steps);

        statgen_layout_cell = new QHBoxLayout();
        statgen_layout_cell->setSpacing(6);
        statgen_layout_cell->setObjectName(QString::fromUtf8("statgen_layout_cell"));
        statgen_label_cell = new QLabel(statgen);
        statgen_label_cell->setObjectName(QString::fromUtf8("statgen_label_cell"));
        statgen_label_cell->setMinimumSize(QSize(110, 23));

        statgen_layout_cell->addWidget(statgen_label_cell);

        statgen_label_cellX = new QLabel(statgen);
        statgen_label_cellX->setObjectName(QString::fromUtf8("statgen_label_cellX"));
        statgen_label_cellX->setMinimumSize(QSize(50, 23));

        statgen_layout_cell->addWidget(statgen_label_cellX);

        statgen_doubleSpinBox_cellX = new QDoubleSpinBox(statgen);
        statgen_doubleSpinBox_cellX->setObjectName(QString::fromUtf8("statgen_doubleSpinBox_cellX"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(statgen_doubleSpinBox_cellX->sizePolicy().hasHeightForWidth());
        statgen_doubleSpinBox_cellX->setSizePolicy(sizePolicy);
        statgen_doubleSpinBox_cellX->setMinimumSize(QSize(55, 23));
        statgen_doubleSpinBox_cellX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        statgen_doubleSpinBox_cellX->setDecimals(4);
        statgen_doubleSpinBox_cellX->setMinimum(0.1);
        statgen_doubleSpinBox_cellX->setMaximum(999.99);

        statgen_layout_cell->addWidget(statgen_doubleSpinBox_cellX);

        statgen_label_cellY = new QLabel(statgen);
        statgen_label_cellY->setObjectName(QString::fromUtf8("statgen_label_cellY"));
        statgen_label_cellY->setMinimumSize(QSize(50, 23));

        statgen_layout_cell->addWidget(statgen_label_cellY);

        statgen_doubleSpinBox_cellY = new QDoubleSpinBox(statgen);
        statgen_doubleSpinBox_cellY->setObjectName(QString::fromUtf8("statgen_doubleSpinBox_cellY"));
        sizePolicy.setHeightForWidth(statgen_doubleSpinBox_cellY->sizePolicy().hasHeightForWidth());
        statgen_doubleSpinBox_cellY->setSizePolicy(sizePolicy);
        statgen_doubleSpinBox_cellY->setMinimumSize(QSize(55, 23));
        statgen_doubleSpinBox_cellY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        statgen_doubleSpinBox_cellY->setDecimals(4);
        statgen_doubleSpinBox_cellY->setMinimum(0.1);
        statgen_doubleSpinBox_cellY->setMaximum(999.99);

        statgen_layout_cell->addWidget(statgen_doubleSpinBox_cellY);

        statgen_label_cellZ = new QLabel(statgen);
        statgen_label_cellZ->setObjectName(QString::fromUtf8("statgen_label_cellZ"));
        statgen_label_cellZ->setMinimumSize(QSize(50, 23));

        statgen_layout_cell->addWidget(statgen_label_cellZ);

        statgen_doubleSpinBox_cellZ = new QDoubleSpinBox(statgen);
        statgen_doubleSpinBox_cellZ->setObjectName(QString::fromUtf8("statgen_doubleSpinBox_cellZ"));
        sizePolicy.setHeightForWidth(statgen_doubleSpinBox_cellZ->sizePolicy().hasHeightForWidth());
        statgen_doubleSpinBox_cellZ->setSizePolicy(sizePolicy);
        statgen_doubleSpinBox_cellZ->setMinimumSize(QSize(55, 23));
        statgen_doubleSpinBox_cellZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        statgen_doubleSpinBox_cellZ->setDecimals(4);
        statgen_doubleSpinBox_cellZ->setMinimum(0.1);
        statgen_doubleSpinBox_cellZ->setMaximum(999.99);

        statgen_layout_cell->addWidget(statgen_doubleSpinBox_cellZ);


        verticalLayout_2->addLayout(statgen_layout_cell);

        statgen_layout_atoms = new QHBoxLayout();
        statgen_layout_atoms->setSpacing(6);
        statgen_layout_atoms->setObjectName(QString::fromUtf8("statgen_layout_atoms"));
        statgen_label_atoms0 = new QLabel(statgen);
        statgen_label_atoms0->setObjectName(QString::fromUtf8("statgen_label_atoms0"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(statgen_label_atoms0->sizePolicy().hasHeightForWidth());
        statgen_label_atoms0->setSizePolicy(sizePolicy1);
        statgen_label_atoms0->setMinimumSize(QSize(45, 23));

        statgen_layout_atoms->addWidget(statgen_label_atoms0);

        statgen_spinBox_atoms0 = new QSpinBox(statgen);
        statgen_spinBox_atoms0->setObjectName(QString::fromUtf8("statgen_spinBox_atoms0"));
        sizePolicy.setHeightForWidth(statgen_spinBox_atoms0->sizePolicy().hasHeightForWidth());
        statgen_spinBox_atoms0->setSizePolicy(sizePolicy);
        statgen_spinBox_atoms0->setMinimumSize(QSize(50, 23));
        statgen_spinBox_atoms0->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        statgen_layout_atoms->addWidget(statgen_spinBox_atoms0);

        statgen_checkBox_atoms1 = new QCheckBox(statgen);
        statgen_checkBox_atoms1->setObjectName(QString::fromUtf8("statgen_checkBox_atoms1"));
        statgen_checkBox_atoms1->setMinimumSize(QSize(65, 23));

        statgen_layout_atoms->addWidget(statgen_checkBox_atoms1);

        statgen_spinBox_atoms1 = new QSpinBox(statgen);
        statgen_spinBox_atoms1->setObjectName(QString::fromUtf8("statgen_spinBox_atoms1"));
        statgen_spinBox_atoms1->setEnabled(false);
        sizePolicy.setHeightForWidth(statgen_spinBox_atoms1->sizePolicy().hasHeightForWidth());
        statgen_spinBox_atoms1->setSizePolicy(sizePolicy);
        statgen_spinBox_atoms1->setMinimumSize(QSize(50, 23));
        statgen_spinBox_atoms1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        statgen_layout_atoms->addWidget(statgen_spinBox_atoms1);

        statgen_checkBox_atoms2 = new QCheckBox(statgen);
        statgen_checkBox_atoms2->setObjectName(QString::fromUtf8("statgen_checkBox_atoms2"));
        statgen_checkBox_atoms2->setEnabled(false);
        statgen_checkBox_atoms2->setMinimumSize(QSize(65, 23));

        statgen_layout_atoms->addWidget(statgen_checkBox_atoms2);

        statgen_spinBox_atoms2 = new QSpinBox(statgen);
        statgen_spinBox_atoms2->setObjectName(QString::fromUtf8("statgen_spinBox_atoms2"));
        statgen_spinBox_atoms2->setEnabled(false);
        sizePolicy.setHeightForWidth(statgen_spinBox_atoms2->sizePolicy().hasHeightForWidth());
        statgen_spinBox_atoms2->setSizePolicy(sizePolicy);
        statgen_spinBox_atoms2->setMinimumSize(QSize(50, 23));
        statgen_spinBox_atoms2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        statgen_layout_atoms->addWidget(statgen_spinBox_atoms2);

        statgen_checkBox_atoms3 = new QCheckBox(statgen);
        statgen_checkBox_atoms3->setObjectName(QString::fromUtf8("statgen_checkBox_atoms3"));
        statgen_checkBox_atoms3->setEnabled(false);
        statgen_checkBox_atoms3->setMinimumSize(QSize(65, 23));

        statgen_layout_atoms->addWidget(statgen_checkBox_atoms3);

        statgen_spinBox_atoms3 = new QSpinBox(statgen);
        statgen_spinBox_atoms3->setObjectName(QString::fromUtf8("statgen_spinBox_atoms3"));
        statgen_spinBox_atoms3->setEnabled(false);
        sizePolicy.setHeightForWidth(statgen_spinBox_atoms3->sizePolicy().hasHeightForWidth());
        statgen_spinBox_atoms3->setSizePolicy(sizePolicy);
        statgen_spinBox_atoms3->setMinimumSize(QSize(50, 23));
        statgen_spinBox_atoms3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        statgen_layout_atoms->addWidget(statgen_spinBox_atoms3);


        verticalLayout_2->addLayout(statgen_layout_atoms);

        statgen_layout_int = new QHBoxLayout();
        statgen_layout_int->setSpacing(6);
        statgen_layout_int->setObjectName(QString::fromUtf8("statgen_layout_int"));
        statgen_label_int = new QLabel(statgen);
        statgen_label_int->setObjectName(QString::fromUtf8("statgen_label_int"));
        statgen_label_int->setMinimumSize(QSize(110, 23));

        statgen_layout_int->addWidget(statgen_label_int);

        statgen_comboBox_int = new QComboBox(statgen);
        statgen_comboBox_int->setObjectName(QString::fromUtf8("statgen_comboBox_int"));
        sizePolicy.setHeightForWidth(statgen_comboBox_int->sizePolicy().hasHeightForWidth());
        statgen_comboBox_int->setSizePolicy(sizePolicy);
        statgen_comboBox_int->setMinimumSize(QSize(90, 23));

        statgen_layout_int->addWidget(statgen_comboBox_int);

        statgen_doubleSpinBox_int = new QDoubleSpinBox(statgen);
        statgen_doubleSpinBox_int->setObjectName(QString::fromUtf8("statgen_doubleSpinBox_int"));
        sizePolicy.setHeightForWidth(statgen_doubleSpinBox_int->sizePolicy().hasHeightForWidth());
        statgen_doubleSpinBox_int->setSizePolicy(sizePolicy);
        statgen_doubleSpinBox_int->setMinimumSize(QSize(90, 23));
        statgen_doubleSpinBox_int->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        statgen_doubleSpinBox_int->setDecimals(3);
        statgen_doubleSpinBox_int->setMinimum(0);
        statgen_doubleSpinBox_int->setValue(0);

        statgen_layout_int->addWidget(statgen_doubleSpinBox_int);

        stagen_pushButton_intSave = new QPushButton(statgen);
        stagen_pushButton_intSave->setObjectName(QString::fromUtf8("stagen_pushButton_intSave"));
        stagen_pushButton_intSave->setMinimumSize(QSize(80, 23));
        stagen_pushButton_intSave->setAutoDefault(true);

        statgen_layout_int->addWidget(stagen_pushButton_intSave);

        statgen_pushButton_intAdd = new QPushButton(statgen);
        statgen_pushButton_intAdd->setObjectName(QString::fromUtf8("statgen_pushButton_intAdd"));
        statgen_pushButton_intAdd->setMinimumSize(QSize(80, 23));
        statgen_pushButton_intAdd->setAutoDefault(true);

        statgen_layout_int->addWidget(statgen_pushButton_intAdd);


        verticalLayout_2->addLayout(statgen_layout_int);

        statgen_listWidget_int = new QListWidget(statgen);
        statgen_listWidget_int->setObjectName(QString::fromUtf8("statgen_listWidget_int"));
        statgen_listWidget_int->setMinimumSize(QSize(484, 85));
        statgen_listWidget_int->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(statgen_listWidget_int);

        stagen_layout_intRem = new QHBoxLayout();
        stagen_layout_intRem->setSpacing(6);
        stagen_layout_intRem->setObjectName(QString::fromUtf8("stagen_layout_intRem"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        stagen_layout_intRem->addItem(horizontalSpacer_5);

        stagen_pushButton_intRem = new QPushButton(statgen);
        stagen_pushButton_intRem->setObjectName(QString::fromUtf8("stagen_pushButton_intRem"));
        stagen_pushButton_intRem->setMinimumSize(QSize(80, 23));
        stagen_pushButton_intRem->setAutoDefault(true);

        stagen_layout_intRem->addWidget(stagen_pushButton_intRem);


        verticalLayout_2->addLayout(stagen_layout_intRem);

        statgen_layout_output = new QHBoxLayout();
        statgen_layout_output->setSpacing(6);
        statgen_layout_output->setObjectName(QString::fromUtf8("statgen_layout_output"));
        statgen_label_output = new QLabel(statgen);
        statgen_label_output->setObjectName(QString::fromUtf8("statgen_label_output"));
        statgen_label_output->setMinimumSize(QSize(110, 23));

        statgen_layout_output->addWidget(statgen_label_output);

        statgen_lineEdit_output = new QLineEdit(statgen);
        statgen_lineEdit_output->setObjectName(QString::fromUtf8("statgen_lineEdit_output"));
        statgen_lineEdit_output->setMinimumSize(QSize(280, 23));

        statgen_layout_output->addWidget(statgen_lineEdit_output);

        statgen_pushButton_output = new QPushButton(statgen);
        statgen_pushButton_output->setObjectName(QString::fromUtf8("statgen_pushButton_output"));
        statgen_pushButton_output->setMinimumSize(QSize(80, 23));
        statgen_pushButton_output->setAutoDefault(true);

        statgen_layout_output->addWidget(statgen_pushButton_output);


        verticalLayout_2->addLayout(statgen_layout_output);

        statgen_layout_opt = new QHBoxLayout();
        statgen_layout_opt->setSpacing(6);
        statgen_layout_opt->setObjectName(QString::fromUtf8("statgen_layout_opt"));
        statgen_checkBox_depth = new QCheckBox(statgen);
        statgen_checkBox_depth->setObjectName(QString::fromUtf8("statgen_checkBox_depth"));
        statgen_checkBox_depth->setMinimumSize(QSize(110, 23));
        statgen_checkBox_depth->setChecked(true);

        statgen_layout_opt->addWidget(statgen_checkBox_depth);

        statgen_spinBox_depth = new QSpinBox(statgen);
        statgen_spinBox_depth->setObjectName(QString::fromUtf8("statgen_spinBox_depth"));
        statgen_spinBox_depth->setMinimumSize(QSize(80, 23));
        statgen_spinBox_depth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        statgen_spinBox_depth->setMinimum(3);
        statgen_spinBox_depth->setMaximum(1000);
        statgen_spinBox_depth->setValue(10);

        statgen_layout_opt->addWidget(statgen_spinBox_depth);

        statgen_checkBox_log = new QCheckBox(statgen);
        statgen_checkBox_log->setObjectName(QString::fromUtf8("statgen_checkBox_log"));
        statgen_checkBox_log->setMinimumSize(QSize(110, 23));
        statgen_checkBox_log->setChecked(true);

        statgen_layout_opt->addWidget(statgen_checkBox_log);

        statgen_lineEdit_log = new QLineEdit(statgen);
        statgen_lineEdit_log->setObjectName(QString::fromUtf8("statgen_lineEdit_log"));
        statgen_lineEdit_log->setMinimumSize(QSize(80, 23));

        statgen_layout_opt->addWidget(statgen_lineEdit_log);

        statgen_pushButton_log = new QPushButton(statgen);
        statgen_pushButton_log->setObjectName(QString::fromUtf8("statgen_pushButton_log"));
        statgen_pushButton_log->setMinimumSize(QSize(80, 23));
        statgen_pushButton_log->setAutoDefault(true);

        statgen_layout_opt->addWidget(statgen_pushButton_log);


        verticalLayout_2->addLayout(statgen_layout_opt);

        statgen_layout_buttons = new QHBoxLayout();
        statgen_layout_buttons->setSpacing(6);
        statgen_layout_buttons->setObjectName(QString::fromUtf8("statgen_layout_buttons"));
        statgen_pushButton_clear = new QPushButton(statgen);
        statgen_pushButton_clear->setObjectName(QString::fromUtf8("statgen_pushButton_clear"));
        statgen_pushButton_clear->setMinimumSize(QSize(80, 23));
        statgen_pushButton_clear->setAutoDefault(true);

        statgen_layout_buttons->addWidget(statgen_pushButton_clear);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        statgen_layout_buttons->addItem(horizontalSpacer_3);

        statgen_pushButton_start = new QPushButton(statgen);
        statgen_pushButton_start->setObjectName(QString::fromUtf8("statgen_pushButton_start"));
        statgen_pushButton_start->setMinimumSize(QSize(80, 23));
        statgen_pushButton_start->setMaximumSize(QSize(16777215, 16777215));
        statgen_pushButton_start->setAutoDefault(true);

        statgen_layout_buttons->addWidget(statgen_pushButton_start);


        verticalLayout_2->addLayout(statgen_layout_buttons);

        tabWidget->addTab(statgen, QString());
        envir = new QWidget();
        envir->setObjectName(QString::fromUtf8("envir"));
        verticalLayout_3 = new QVBoxLayout(envir);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        envir_layout_workDir = new QHBoxLayout();
        envir_layout_workDir->setSpacing(6);
        envir_layout_workDir->setObjectName(QString::fromUtf8("envir_layout_workDir"));
        envir_label_workDir = new QLabel(envir);
        envir_label_workDir->setObjectName(QString::fromUtf8("envir_label_workDir"));
        envir_label_workDir->setMinimumSize(QSize(110, 23));

        envir_layout_workDir->addWidget(envir_label_workDir);

        envir_lineEdit_workDir = new QLineEdit(envir);
        envir_lineEdit_workDir->setObjectName(QString::fromUtf8("envir_lineEdit_workDir"));
        envir_lineEdit_workDir->setMinimumSize(QSize(280, 23));

        envir_layout_workDir->addWidget(envir_lineEdit_workDir);

        envir_pushButton_workDir = new QPushButton(envir);
        envir_pushButton_workDir->setObjectName(QString::fromUtf8("envir_pushButton_workDir"));
        envir_pushButton_workDir->setMinimumSize(QSize(80, 23));
        envir_pushButton_workDir->setAutoDefault(true);

        envir_layout_workDir->addWidget(envir_pushButton_workDir);


        verticalLayout_3->addLayout(envir_layout_workDir);

        envir_layout_input = new QHBoxLayout();
        envir_layout_input->setSpacing(6);
        envir_layout_input->setObjectName(QString::fromUtf8("envir_layout_input"));
        envir_label_input = new QLabel(envir);
        envir_label_input->setObjectName(QString::fromUtf8("envir_label_input"));
        envir_label_input->setMinimumSize(QSize(110, 23));

        envir_layout_input->addWidget(envir_label_input);

        envir_lineEdit_input = new QLineEdit(envir);
        envir_lineEdit_input->setObjectName(QString::fromUtf8("envir_lineEdit_input"));
        envir_lineEdit_input->setMinimumSize(QSize(280, 23));

        envir_layout_input->addWidget(envir_lineEdit_input);

        envir_pushButton_input = new QPushButton(envir);
        envir_pushButton_input->setObjectName(QString::fromUtf8("envir_pushButton_input"));
        envir_pushButton_input->setMinimumSize(QSize(80, 23));
        envir_pushButton_input->setAutoDefault(true);

        envir_layout_input->addWidget(envir_pushButton_input);


        verticalLayout_3->addLayout(envir_layout_input);

        envir_layout_cell = new QHBoxLayout();
        envir_layout_cell->setSpacing(6);
        envir_layout_cell->setObjectName(QString::fromUtf8("envir_layout_cell"));
        envir_label_cell = new QLabel(envir);
        envir_label_cell->setObjectName(QString::fromUtf8("envir_label_cell"));
        envir_label_cell->setMinimumSize(QSize(110, 23));

        envir_layout_cell->addWidget(envir_label_cell);

        envir_label_cellX = new QLabel(envir);
        envir_label_cellX->setObjectName(QString::fromUtf8("envir_label_cellX"));
        envir_label_cellX->setMinimumSize(QSize(50, 23));

        envir_layout_cell->addWidget(envir_label_cellX);

        envir_doubleSpinBox_cellX = new QDoubleSpinBox(envir);
        envir_doubleSpinBox_cellX->setObjectName(QString::fromUtf8("envir_doubleSpinBox_cellX"));
        sizePolicy.setHeightForWidth(envir_doubleSpinBox_cellX->sizePolicy().hasHeightForWidth());
        envir_doubleSpinBox_cellX->setSizePolicy(sizePolicy);
        envir_doubleSpinBox_cellX->setMinimumSize(QSize(55, 23));
        envir_doubleSpinBox_cellX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        envir_doubleSpinBox_cellX->setDecimals(4);
        envir_doubleSpinBox_cellX->setMinimum(0.1);
        envir_doubleSpinBox_cellX->setMaximum(999.99);

        envir_layout_cell->addWidget(envir_doubleSpinBox_cellX);

        envir_label_cellY = new QLabel(envir);
        envir_label_cellY->setObjectName(QString::fromUtf8("envir_label_cellY"));
        envir_label_cellY->setMinimumSize(QSize(50, 23));

        envir_layout_cell->addWidget(envir_label_cellY);

        envir_doubleSpinBox_cellY = new QDoubleSpinBox(envir);
        envir_doubleSpinBox_cellY->setObjectName(QString::fromUtf8("envir_doubleSpinBox_cellY"));
        sizePolicy.setHeightForWidth(envir_doubleSpinBox_cellY->sizePolicy().hasHeightForWidth());
        envir_doubleSpinBox_cellY->setSizePolicy(sizePolicy);
        envir_doubleSpinBox_cellY->setMinimumSize(QSize(55, 23));
        envir_doubleSpinBox_cellY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        envir_doubleSpinBox_cellY->setDecimals(4);
        envir_doubleSpinBox_cellY->setMinimum(0.1);
        envir_doubleSpinBox_cellY->setMaximum(999.99);

        envir_layout_cell->addWidget(envir_doubleSpinBox_cellY);

        envir_label_cellZ = new QLabel(envir);
        envir_label_cellZ->setObjectName(QString::fromUtf8("envir_label_cellZ"));
        envir_label_cellZ->setMinimumSize(QSize(50, 23));

        envir_layout_cell->addWidget(envir_label_cellZ);

        envir_doubleSpinBox_cellZ = new QDoubleSpinBox(envir);
        envir_doubleSpinBox_cellZ->setObjectName(QString::fromUtf8("envir_doubleSpinBox_cellZ"));
        sizePolicy.setHeightForWidth(envir_doubleSpinBox_cellZ->sizePolicy().hasHeightForWidth());
        envir_doubleSpinBox_cellZ->setSizePolicy(sizePolicy);
        envir_doubleSpinBox_cellZ->setMinimumSize(QSize(55, 23));
        envir_doubleSpinBox_cellZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        envir_doubleSpinBox_cellZ->setDecimals(4);
        envir_doubleSpinBox_cellZ->setMinimum(0.1);
        envir_doubleSpinBox_cellZ->setMaximum(999.99);

        envir_layout_cell->addWidget(envir_doubleSpinBox_cellZ);


        verticalLayout_3->addLayout(envir_layout_cell);

        envir_layout_output = new QHBoxLayout();
        envir_layout_output->setSpacing(6);
        envir_layout_output->setObjectName(QString::fromUtf8("envir_layout_output"));
        envir_label_output = new QLabel(envir);
        envir_label_output->setObjectName(QString::fromUtf8("envir_label_output"));
        envir_label_output->setMinimumSize(QSize(110, 23));

        envir_layout_output->addWidget(envir_label_output);

        envir_lineEdit_output = new QLineEdit(envir);
        envir_lineEdit_output->setObjectName(QString::fromUtf8("envir_lineEdit_output"));
        envir_lineEdit_output->setMinimumSize(QSize(280, 23));

        envir_layout_output->addWidget(envir_lineEdit_output);

        envir_pushButton_output = new QPushButton(envir);
        envir_pushButton_output->setObjectName(QString::fromUtf8("envir_pushButton_output"));
        envir_pushButton_output->setMinimumSize(QSize(80, 23));
        envir_pushButton_output->setAutoDefault(true);

        envir_layout_output->addWidget(envir_pushButton_output);


        verticalLayout_3->addLayout(envir_layout_output);

        envir_layout_opt_1 = new QHBoxLayout();
        envir_layout_opt_1->setSpacing(6);
        envir_layout_opt_1->setObjectName(QString::fromUtf8("envir_layout_opt_1"));
        envir_label_molecule = new QLabel(envir);
        envir_label_molecule->setObjectName(QString::fromUtf8("envir_label_molecule"));
        envir_label_molecule->setMinimumSize(QSize(110, 23));

        envir_layout_opt_1->addWidget(envir_label_molecule);

        envir_spinBox_molecule = new QSpinBox(envir);
        envir_spinBox_molecule->setObjectName(QString::fromUtf8("envir_spinBox_molecule"));
        envir_spinBox_molecule->setMinimumSize(QSize(75, 23));
        envir_spinBox_molecule->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        envir_spinBox_molecule->setMinimum(1);
        envir_spinBox_molecule->setMaximum(9999);

        envir_layout_opt_1->addWidget(envir_spinBox_molecule);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        envir_layout_opt_1->addItem(horizontalSpacer_8);

        envir_label_radius = new QLabel(envir);
        envir_label_radius->setObjectName(QString::fromUtf8("envir_label_radius"));
        envir_label_radius->setMinimumSize(QSize(110, 23));

        envir_layout_opt_1->addWidget(envir_label_radius);

        envir_doubleSpinBox_radius = new QDoubleSpinBox(envir);
        envir_doubleSpinBox_radius->setObjectName(QString::fromUtf8("envir_doubleSpinBox_radius"));
        envir_doubleSpinBox_radius->setMinimumSize(QSize(75, 23));
        envir_doubleSpinBox_radius->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        envir_doubleSpinBox_radius->setDecimals(3);

        envir_layout_opt_1->addWidget(envir_doubleSpinBox_radius);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        envir_layout_opt_1->addItem(horizontalSpacer_9);


        verticalLayout_3->addLayout(envir_layout_opt_1);

        envir_layout_opt_2 = new QHBoxLayout();
        envir_layout_opt_2->setSpacing(6);
        envir_layout_opt_2->setObjectName(QString::fromUtf8("envir_layout_opt_2"));
        envir_checkBox_log = new QCheckBox(envir);
        envir_checkBox_log->setObjectName(QString::fromUtf8("envir_checkBox_log"));
        envir_checkBox_log->setMinimumSize(QSize(110, 23));
        envir_checkBox_log->setChecked(true);

        envir_layout_opt_2->addWidget(envir_checkBox_log);

        envir_lineEdit_log = new QLineEdit(envir);
        envir_lineEdit_log->setObjectName(QString::fromUtf8("envir_lineEdit_log"));
        envir_lineEdit_log->setMinimumSize(QSize(173, 23));

        envir_layout_opt_2->addWidget(envir_lineEdit_log);

        envir_pushButton_log = new QPushButton(envir);
        envir_pushButton_log->setObjectName(QString::fromUtf8("envir_pushButton_log"));
        envir_pushButton_log->setMinimumSize(QSize(80, 23));
        envir_pushButton_log->setAutoDefault(true);

        envir_layout_opt_2->addWidget(envir_pushButton_log);


        verticalLayout_3->addLayout(envir_layout_opt_2);

        verticalSpacer_2 = new QSpacerItem(20, 177, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        envir_layout_buttons = new QHBoxLayout();
        envir_layout_buttons->setSpacing(6);
        envir_layout_buttons->setObjectName(QString::fromUtf8("envir_layout_buttons"));
        envir_pushButton_clear = new QPushButton(envir);
        envir_pushButton_clear->setObjectName(QString::fromUtf8("envir_pushButton_clear"));
        envir_pushButton_clear->setMinimumSize(QSize(80, 23));
        envir_pushButton_clear->setAutoDefault(true);

        envir_layout_buttons->addWidget(envir_pushButton_clear);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        envir_layout_buttons->addItem(horizontalSpacer_10);

        envir_pushButton_start = new QPushButton(envir);
        envir_pushButton_start->setObjectName(QString::fromUtf8("envir_pushButton_start"));
        envir_pushButton_start->setMinimumSize(QSize(80, 23));
        envir_pushButton_start->setMaximumSize(QSize(16777215, 16777215));
        envir_pushButton_start->setAutoDefault(true);

        envir_layout_buttons->addWidget(envir_pushButton_start);


        verticalLayout_3->addLayout(envir_layout_buttons);

        tabWidget->addTab(envir, QString());
        radf = new QWidget();
        radf->setObjectName(QString::fromUtf8("radf"));
        verticalLayout_4 = new QVBoxLayout(radf);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        radf_layout_workDir = new QHBoxLayout();
        radf_layout_workDir->setSpacing(6);
        radf_layout_workDir->setObjectName(QString::fromUtf8("radf_layout_workDir"));
        radf_label_workDir = new QLabel(radf);
        radf_label_workDir->setObjectName(QString::fromUtf8("radf_label_workDir"));
        radf_label_workDir->setMinimumSize(QSize(110, 23));

        radf_layout_workDir->addWidget(radf_label_workDir);

        radf_lineEdit_workDir = new QLineEdit(radf);
        radf_lineEdit_workDir->setObjectName(QString::fromUtf8("radf_lineEdit_workDir"));
        radf_lineEdit_workDir->setMinimumSize(QSize(280, 23));

        radf_layout_workDir->addWidget(radf_lineEdit_workDir);

        radf_pushButton_workDir = new QPushButton(radf);
        radf_pushButton_workDir->setObjectName(QString::fromUtf8("radf_pushButton_workDir"));
        radf_pushButton_workDir->setMinimumSize(QSize(80, 23));
        radf_pushButton_workDir->setAutoDefault(true);

        radf_layout_workDir->addWidget(radf_pushButton_workDir);


        verticalLayout_4->addLayout(radf_layout_workDir);

        radf_layout_input = new QHBoxLayout();
        radf_layout_input->setSpacing(6);
        radf_layout_input->setObjectName(QString::fromUtf8("radf_layout_input"));
        radf_label_input = new QLabel(radf);
        radf_label_input->setObjectName(QString::fromUtf8("radf_label_input"));
        radf_label_input->setMinimumSize(QSize(110, 23));

        radf_layout_input->addWidget(radf_label_input);

        radf_lineEdit_input = new QLineEdit(radf);
        radf_lineEdit_input->setObjectName(QString::fromUtf8("radf_lineEdit_input"));
        radf_lineEdit_input->setMinimumSize(QSize(280, 23));

        radf_layout_input->addWidget(radf_lineEdit_input);


        verticalLayout_4->addLayout(radf_layout_input);

        radf_layout_steps = new QHBoxLayout();
        radf_layout_steps->setSpacing(6);
        radf_layout_steps->setObjectName(QString::fromUtf8("radf_layout_steps"));
        radf_label_steps = new QLabel(radf);
        radf_label_steps->setObjectName(QString::fromUtf8("radf_label_steps"));
        radf_label_steps->setMinimumSize(QSize(110, 23));

        radf_layout_steps->addWidget(radf_label_steps);

        radf_label_stepsFirst = new QLabel(radf);
        radf_label_stepsFirst->setObjectName(QString::fromUtf8("radf_label_stepsFirst"));
        radf_label_stepsFirst->setMinimumSize(QSize(75, 23));

        radf_layout_steps->addWidget(radf_label_stepsFirst);

        radf_spinBox_stepsFirst = new QSpinBox(radf);
        radf_spinBox_stepsFirst->setObjectName(QString::fromUtf8("radf_spinBox_stepsFirst"));
        radf_spinBox_stepsFirst->setMinimumSize(QSize(75, 23));
        radf_spinBox_stepsFirst->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        radf_spinBox_stepsFirst->setMinimum(1);
        radf_spinBox_stepsFirst->setMaximum(999);

        radf_layout_steps->addWidget(radf_spinBox_stepsFirst);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        radf_layout_steps->addItem(horizontalSpacer_11);

        radf_label_stepsLast = new QLabel(radf);
        radf_label_stepsLast->setObjectName(QString::fromUtf8("radf_label_stepsLast"));
        radf_label_stepsLast->setMinimumSize(QSize(75, 23));

        radf_layout_steps->addWidget(radf_label_stepsLast);

        radf_spinBox_stepsLast = new QSpinBox(radf);
        radf_spinBox_stepsLast->setObjectName(QString::fromUtf8("radf_spinBox_stepsLast"));
        radf_spinBox_stepsLast->setMinimumSize(QSize(75, 23));
        radf_spinBox_stepsLast->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        radf_spinBox_stepsLast->setMinimum(1);
        radf_spinBox_stepsLast->setMaximum(999);

        radf_layout_steps->addWidget(radf_spinBox_stepsLast);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        radf_layout_steps->addItem(horizontalSpacer_12);


        verticalLayout_4->addLayout(radf_layout_steps);

        radf_layout_cell = new QHBoxLayout();
        radf_layout_cell->setSpacing(6);
        radf_layout_cell->setObjectName(QString::fromUtf8("radf_layout_cell"));
        radf_label_cell = new QLabel(radf);
        radf_label_cell->setObjectName(QString::fromUtf8("radf_label_cell"));
        radf_label_cell->setMinimumSize(QSize(110, 23));

        radf_layout_cell->addWidget(radf_label_cell);

        radf_label_cellX = new QLabel(radf);
        radf_label_cellX->setObjectName(QString::fromUtf8("radf_label_cellX"));
        radf_label_cellX->setMinimumSize(QSize(50, 23));

        radf_layout_cell->addWidget(radf_label_cellX);

        radf_doubleSpinBox_cellX = new QDoubleSpinBox(radf);
        radf_doubleSpinBox_cellX->setObjectName(QString::fromUtf8("radf_doubleSpinBox_cellX"));
        sizePolicy.setHeightForWidth(radf_doubleSpinBox_cellX->sizePolicy().hasHeightForWidth());
        radf_doubleSpinBox_cellX->setSizePolicy(sizePolicy);
        radf_doubleSpinBox_cellX->setMinimumSize(QSize(55, 23));
        radf_doubleSpinBox_cellX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        radf_doubleSpinBox_cellX->setDecimals(4);
        radf_doubleSpinBox_cellX->setMinimum(0.1);
        radf_doubleSpinBox_cellX->setMaximum(999.99);

        radf_layout_cell->addWidget(radf_doubleSpinBox_cellX);

        radf_label_cellY = new QLabel(radf);
        radf_label_cellY->setObjectName(QString::fromUtf8("radf_label_cellY"));
        radf_label_cellY->setMinimumSize(QSize(50, 23));

        radf_layout_cell->addWidget(radf_label_cellY);

        radf_doubleSpinBox_cellY = new QDoubleSpinBox(radf);
        radf_doubleSpinBox_cellY->setObjectName(QString::fromUtf8("radf_doubleSpinBox_cellY"));
        sizePolicy.setHeightForWidth(radf_doubleSpinBox_cellY->sizePolicy().hasHeightForWidth());
        radf_doubleSpinBox_cellY->setSizePolicy(sizePolicy);
        radf_doubleSpinBox_cellY->setMinimumSize(QSize(55, 23));
        radf_doubleSpinBox_cellY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        radf_doubleSpinBox_cellY->setDecimals(4);
        radf_doubleSpinBox_cellY->setMinimum(0.1);
        radf_doubleSpinBox_cellY->setMaximum(999.99);

        radf_layout_cell->addWidget(radf_doubleSpinBox_cellY);

        radf_label_cellZ = new QLabel(radf);
        radf_label_cellZ->setObjectName(QString::fromUtf8("radf_label_cellZ"));
        radf_label_cellZ->setMinimumSize(QSize(50, 23));

        radf_layout_cell->addWidget(radf_label_cellZ);

        radf_doubleSpinBox_cellZ = new QDoubleSpinBox(radf);
        radf_doubleSpinBox_cellZ->setObjectName(QString::fromUtf8("radf_doubleSpinBox_cellZ"));
        sizePolicy.setHeightForWidth(radf_doubleSpinBox_cellZ->sizePolicy().hasHeightForWidth());
        radf_doubleSpinBox_cellZ->setSizePolicy(sizePolicy);
        radf_doubleSpinBox_cellZ->setMinimumSize(QSize(55, 23));
        radf_doubleSpinBox_cellZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        radf_doubleSpinBox_cellZ->setDecimals(4);
        radf_doubleSpinBox_cellZ->setMinimum(0.1);
        radf_doubleSpinBox_cellZ->setMaximum(999.99);

        radf_layout_cell->addWidget(radf_doubleSpinBox_cellZ);


        verticalLayout_4->addLayout(radf_layout_cell);

        radf_layout_output = new QHBoxLayout();
        radf_layout_output->setSpacing(6);
        radf_layout_output->setObjectName(QString::fromUtf8("radf_layout_output"));
        radf_label_output = new QLabel(radf);
        radf_label_output->setObjectName(QString::fromUtf8("radf_label_output"));
        radf_label_output->setMinimumSize(QSize(110, 23));

        radf_layout_output->addWidget(radf_label_output);

        radf_lineEdit_output = new QLineEdit(radf);
        radf_lineEdit_output->setObjectName(QString::fromUtf8("radf_lineEdit_output"));
        radf_lineEdit_output->setMinimumSize(QSize(280, 23));

        radf_layout_output->addWidget(radf_lineEdit_output);

        radf_pushButton_output = new QPushButton(radf);
        radf_pushButton_output->setObjectName(QString::fromUtf8("radf_pushButton_output"));
        radf_pushButton_output->setMinimumSize(QSize(80, 23));
        radf_pushButton_output->setAutoDefault(true);

        radf_layout_output->addWidget(radf_pushButton_output);


        verticalLayout_4->addLayout(radf_layout_output);

        radf_layout_atom1 = new QHBoxLayout();
        radf_layout_atom1->setSpacing(6);
        radf_layout_atom1->setObjectName(QString::fromUtf8("radf_layout_atom1"));
        radf_comboBox_atom = new QComboBox(radf);
        radf_comboBox_atom->setObjectName(QString::fromUtf8("radf_comboBox_atom"));
        radf_comboBox_atom->setMinimumSize(QSize(150, 23));

        radf_layout_atom1->addWidget(radf_comboBox_atom);

        radf_label_atoms0 = new QLabel(radf);
        radf_label_atoms0->setObjectName(QString::fromUtf8("radf_label_atoms0"));
        sizePolicy1.setHeightForWidth(radf_label_atoms0->sizePolicy().hasHeightForWidth());
        radf_label_atoms0->setSizePolicy(sizePolicy1);
        radf_label_atoms0->setMinimumSize(QSize(45, 23));

        radf_layout_atom1->addWidget(radf_label_atoms0);

        radf_spinBox_atoms0 = new QSpinBox(radf);
        radf_spinBox_atoms0->setObjectName(QString::fromUtf8("radf_spinBox_atoms0"));
        sizePolicy.setHeightForWidth(radf_spinBox_atoms0->sizePolicy().hasHeightForWidth());
        radf_spinBox_atoms0->setSizePolicy(sizePolicy);
        radf_spinBox_atoms0->setMinimumSize(QSize(50, 23));
        radf_spinBox_atoms0->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        radf_layout_atom1->addWidget(radf_spinBox_atoms0);

        radf_label_atoms1 = new QLabel(radf);
        radf_label_atoms1->setObjectName(QString::fromUtf8("radf_label_atoms1"));
        sizePolicy1.setHeightForWidth(radf_label_atoms1->sizePolicy().hasHeightForWidth());
        radf_label_atoms1->setSizePolicy(sizePolicy1);
        radf_label_atoms1->setMinimumSize(QSize(45, 23));

        radf_layout_atom1->addWidget(radf_label_atoms1);

        radf_spinBox_atoms1 = new QSpinBox(radf);
        radf_spinBox_atoms1->setObjectName(QString::fromUtf8("radf_spinBox_atoms1"));
        radf_spinBox_atoms1->setEnabled(false);
        sizePolicy.setHeightForWidth(radf_spinBox_atoms1->sizePolicy().hasHeightForWidth());
        radf_spinBox_atoms1->setSizePolicy(sizePolicy);
        radf_spinBox_atoms1->setMinimumSize(QSize(50, 23));
        radf_spinBox_atoms1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        radf_layout_atom1->addWidget(radf_spinBox_atoms1);

        radf_label_atoms2 = new QLabel(radf);
        radf_label_atoms2->setObjectName(QString::fromUtf8("radf_label_atoms2"));
        sizePolicy1.setHeightForWidth(radf_label_atoms2->sizePolicy().hasHeightForWidth());
        radf_label_atoms2->setSizePolicy(sizePolicy1);
        radf_label_atoms2->setMinimumSize(QSize(45, 23));

        radf_layout_atom1->addWidget(radf_label_atoms2);

        radf_spinBox_atoms2 = new QSpinBox(radf);
        radf_spinBox_atoms2->setObjectName(QString::fromUtf8("radf_spinBox_atoms2"));
        radf_spinBox_atoms2->setEnabled(false);
        sizePolicy.setHeightForWidth(radf_spinBox_atoms2->sizePolicy().hasHeightForWidth());
        radf_spinBox_atoms2->setSizePolicy(sizePolicy);
        radf_spinBox_atoms2->setMinimumSize(QSize(50, 23));
        radf_spinBox_atoms2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        radf_layout_atom1->addWidget(radf_spinBox_atoms2);


        verticalLayout_4->addLayout(radf_layout_atom1);

        radf_layout_atom2 = new QHBoxLayout();
        radf_layout_atom2->setSpacing(6);
        radf_layout_atom2->setObjectName(QString::fromUtf8("radf_layout_atom2"));
        horizontalSpacer_14 = new QSpacerItem(155, 23, QSizePolicy::Fixed, QSizePolicy::Minimum);

        radf_layout_atom2->addItem(horizontalSpacer_14);

        radf_label_atoms3 = new QLabel(radf);
        radf_label_atoms3->setObjectName(QString::fromUtf8("radf_label_atoms3"));
        sizePolicy1.setHeightForWidth(radf_label_atoms3->sizePolicy().hasHeightForWidth());
        radf_label_atoms3->setSizePolicy(sizePolicy1);
        radf_label_atoms3->setMinimumSize(QSize(45, 23));

        radf_layout_atom2->addWidget(radf_label_atoms3);

        radf_spinBox_atoms3 = new QSpinBox(radf);
        radf_spinBox_atoms3->setObjectName(QString::fromUtf8("radf_spinBox_atoms3"));
        sizePolicy.setHeightForWidth(radf_spinBox_atoms3->sizePolicy().hasHeightForWidth());
        radf_spinBox_atoms3->setSizePolicy(sizePolicy);
        radf_spinBox_atoms3->setMinimumSize(QSize(50, 23));
        radf_spinBox_atoms3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        radf_layout_atom2->addWidget(radf_spinBox_atoms3);

        radf_label_atoms4 = new QLabel(radf);
        radf_label_atoms4->setObjectName(QString::fromUtf8("radf_label_atoms4"));
        sizePolicy1.setHeightForWidth(radf_label_atoms4->sizePolicy().hasHeightForWidth());
        radf_label_atoms4->setSizePolicy(sizePolicy1);
        radf_label_atoms4->setMinimumSize(QSize(45, 23));

        radf_layout_atom2->addWidget(radf_label_atoms4);

        radf_spinBox_atoms4 = new QSpinBox(radf);
        radf_spinBox_atoms4->setObjectName(QString::fromUtf8("radf_spinBox_atoms4"));
        radf_spinBox_atoms4->setEnabled(false);
        sizePolicy.setHeightForWidth(radf_spinBox_atoms4->sizePolicy().hasHeightForWidth());
        radf_spinBox_atoms4->setSizePolicy(sizePolicy);
        radf_spinBox_atoms4->setMinimumSize(QSize(50, 23));
        radf_spinBox_atoms4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        radf_layout_atom2->addWidget(radf_spinBox_atoms4);

        radf_label_atoms5 = new QLabel(radf);
        radf_label_atoms5->setObjectName(QString::fromUtf8("radf_label_atoms5"));
        sizePolicy1.setHeightForWidth(radf_label_atoms5->sizePolicy().hasHeightForWidth());
        radf_label_atoms5->setSizePolicy(sizePolicy1);
        radf_label_atoms5->setMinimumSize(QSize(45, 23));

        radf_layout_atom2->addWidget(radf_label_atoms5);

        radf_spinBox_atoms5 = new QSpinBox(radf);
        radf_spinBox_atoms5->setObjectName(QString::fromUtf8("radf_spinBox_atoms5"));
        radf_spinBox_atoms5->setEnabled(false);
        sizePolicy.setHeightForWidth(radf_spinBox_atoms5->sizePolicy().hasHeightForWidth());
        radf_spinBox_atoms5->setSizePolicy(sizePolicy);
        radf_spinBox_atoms5->setMinimumSize(QSize(50, 23));
        radf_spinBox_atoms5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        radf_layout_atom2->addWidget(radf_spinBox_atoms5);


        verticalLayout_4->addLayout(radf_layout_atom2);

        radf_layout_rad = new QHBoxLayout();
        radf_layout_rad->setSpacing(6);
        radf_layout_rad->setObjectName(QString::fromUtf8("radf_layout_rad"));
        radf_label_rad = new QLabel(radf);
        radf_label_rad->setObjectName(QString::fromUtf8("radf_label_rad"));
        radf_label_rad->setMinimumSize(QSize(110, 23));

        radf_layout_rad->addWidget(radf_label_rad);

        radf_label_radMin = new QLabel(radf);
        radf_label_radMin->setObjectName(QString::fromUtf8("radf_label_radMin"));
        radf_label_radMin->setMinimumSize(QSize(50, 23));

        radf_layout_rad->addWidget(radf_label_radMin);

        radf_doubleSpinBox_radMin = new QDoubleSpinBox(radf);
        radf_doubleSpinBox_radMin->setObjectName(QString::fromUtf8("radf_doubleSpinBox_radMin"));
        sizePolicy.setHeightForWidth(radf_doubleSpinBox_radMin->sizePolicy().hasHeightForWidth());
        radf_doubleSpinBox_radMin->setSizePolicy(sizePolicy);
        radf_doubleSpinBox_radMin->setMinimumSize(QSize(55, 23));
        radf_doubleSpinBox_radMin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        radf_doubleSpinBox_radMin->setDecimals(3);
        radf_doubleSpinBox_radMin->setMinimum(0);
        radf_doubleSpinBox_radMin->setMaximum(999.99);
        radf_doubleSpinBox_radMin->setValue(2);

        radf_layout_rad->addWidget(radf_doubleSpinBox_radMin);

        radf_label_radMax = new QLabel(radf);
        radf_label_radMax->setObjectName(QString::fromUtf8("radf_label_radMax"));
        radf_label_radMax->setMinimumSize(QSize(50, 23));

        radf_layout_rad->addWidget(radf_label_radMax);

        radf_doubleSpinBox_radMax = new QDoubleSpinBox(radf);
        radf_doubleSpinBox_radMax->setObjectName(QString::fromUtf8("radf_doubleSpinBox_radMax"));
        sizePolicy.setHeightForWidth(radf_doubleSpinBox_radMax->sizePolicy().hasHeightForWidth());
        radf_doubleSpinBox_radMax->setSizePolicy(sizePolicy);
        radf_doubleSpinBox_radMax->setMinimumSize(QSize(55, 23));
        radf_doubleSpinBox_radMax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        radf_doubleSpinBox_radMax->setDecimals(3);
        radf_doubleSpinBox_radMax->setMinimum(0.1);
        radf_doubleSpinBox_radMax->setMaximum(999.99);
        radf_doubleSpinBox_radMax->setValue(15);

        radf_layout_rad->addWidget(radf_doubleSpinBox_radMax);

        radf_label_radStep = new QLabel(radf);
        radf_label_radStep->setObjectName(QString::fromUtf8("radf_label_radStep"));
        radf_label_radStep->setMinimumSize(QSize(50, 23));

        radf_layout_rad->addWidget(radf_label_radStep);

        radf_doubleSpinBox_radStep = new QDoubleSpinBox(radf);
        radf_doubleSpinBox_radStep->setObjectName(QString::fromUtf8("radf_doubleSpinBox_radStep"));
        sizePolicy.setHeightForWidth(radf_doubleSpinBox_radStep->sizePolicy().hasHeightForWidth());
        radf_doubleSpinBox_radStep->setSizePolicy(sizePolicy);
        radf_doubleSpinBox_radStep->setMinimumSize(QSize(55, 23));
        radf_doubleSpinBox_radStep->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        radf_doubleSpinBox_radStep->setDecimals(3);
        radf_doubleSpinBox_radStep->setMinimum(0.001);
        radf_doubleSpinBox_radStep->setMaximum(1);
        radf_doubleSpinBox_radStep->setSingleStep(0.01);
        radf_doubleSpinBox_radStep->setValue(0.02);

        radf_layout_rad->addWidget(radf_doubleSpinBox_radStep);


        verticalLayout_4->addLayout(radf_layout_rad);

        radf_layout_ang = new QHBoxLayout();
        radf_layout_ang->setSpacing(6);
        radf_layout_ang->setObjectName(QString::fromUtf8("radf_layout_ang"));
        radf_checkBox_ang = new QCheckBox(radf);
        radf_checkBox_ang->setObjectName(QString::fromUtf8("radf_checkBox_ang"));
        radf_checkBox_ang->setMinimumSize(QSize(110, 23));

        radf_layout_ang->addWidget(radf_checkBox_ang);

        radf_label_angMin = new QLabel(radf);
        radf_label_angMin->setObjectName(QString::fromUtf8("radf_label_angMin"));
        radf_label_angMin->setMinimumSize(QSize(50, 23));

        radf_layout_ang->addWidget(radf_label_angMin);

        radf_doubleSpinBox_angMin = new QDoubleSpinBox(radf);
        radf_doubleSpinBox_angMin->setObjectName(QString::fromUtf8("radf_doubleSpinBox_angMin"));
        radf_doubleSpinBox_angMin->setEnabled(false);
        sizePolicy.setHeightForWidth(radf_doubleSpinBox_angMin->sizePolicy().hasHeightForWidth());
        radf_doubleSpinBox_angMin->setSizePolicy(sizePolicy);
        radf_doubleSpinBox_angMin->setMinimumSize(QSize(55, 23));
        radf_doubleSpinBox_angMin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        radf_doubleSpinBox_angMin->setDecimals(2);
        radf_doubleSpinBox_angMin->setMinimum(0);
        radf_doubleSpinBox_angMin->setMaximum(90);
        radf_doubleSpinBox_angMin->setSingleStep(15);
        radf_doubleSpinBox_angMin->setValue(0);

        radf_layout_ang->addWidget(radf_doubleSpinBox_angMin);

        radf_label_angMax = new QLabel(radf);
        radf_label_angMax->setObjectName(QString::fromUtf8("radf_label_angMax"));
        radf_label_angMax->setMinimumSize(QSize(50, 23));

        radf_layout_ang->addWidget(radf_label_angMax);

        radf_doubleSpinBox_angMax = new QDoubleSpinBox(radf);
        radf_doubleSpinBox_angMax->setObjectName(QString::fromUtf8("radf_doubleSpinBox_angMax"));
        radf_doubleSpinBox_angMax->setEnabled(false);
        sizePolicy.setHeightForWidth(radf_doubleSpinBox_angMax->sizePolicy().hasHeightForWidth());
        radf_doubleSpinBox_angMax->setSizePolicy(sizePolicy);
        radf_doubleSpinBox_angMax->setMinimumSize(QSize(55, 23));
        radf_doubleSpinBox_angMax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        radf_doubleSpinBox_angMax->setDecimals(2);
        radf_doubleSpinBox_angMax->setMinimum(0.1);
        radf_doubleSpinBox_angMax->setMaximum(90);
        radf_doubleSpinBox_angMax->setSingleStep(15);
        radf_doubleSpinBox_angMax->setValue(90);

        radf_layout_ang->addWidget(radf_doubleSpinBox_angMax);

        radf_label_angStep = new QLabel(radf);
        radf_label_angStep->setObjectName(QString::fromUtf8("radf_label_angStep"));
        radf_label_angStep->setMinimumSize(QSize(50, 23));

        radf_layout_ang->addWidget(radf_label_angStep);

        radf_doubleSpinBox_angStep = new QDoubleSpinBox(radf);
        radf_doubleSpinBox_angStep->setObjectName(QString::fromUtf8("radf_doubleSpinBox_angStep"));
        radf_doubleSpinBox_angStep->setEnabled(false);
        sizePolicy.setHeightForWidth(radf_doubleSpinBox_angStep->sizePolicy().hasHeightForWidth());
        radf_doubleSpinBox_angStep->setSizePolicy(sizePolicy);
        radf_doubleSpinBox_angStep->setMinimumSize(QSize(55, 23));
        radf_doubleSpinBox_angStep->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        radf_doubleSpinBox_angStep->setDecimals(2);
        radf_doubleSpinBox_angStep->setMinimum(0.1);
        radf_doubleSpinBox_angStep->setMaximum(90);
        radf_doubleSpinBox_angStep->setSingleStep(15);
        radf_doubleSpinBox_angStep->setValue(15);

        radf_layout_ang->addWidget(radf_doubleSpinBox_angStep);


        verticalLayout_4->addLayout(radf_layout_ang);

        radf_layout_opt = new QHBoxLayout();
        radf_layout_opt->setSpacing(6);
        radf_layout_opt->setObjectName(QString::fromUtf8("radf_layout_opt"));
        radf_checkBox_matrix = new QCheckBox(radf);
        radf_checkBox_matrix->setObjectName(QString::fromUtf8("radf_checkBox_matrix"));
        radf_checkBox_matrix->setMinimumSize(QSize(110, 23));

        radf_layout_opt->addWidget(radf_checkBox_matrix);

        radf_checkBox_log = new QCheckBox(radf);
        radf_checkBox_log->setObjectName(QString::fromUtf8("radf_checkBox_log"));
        radf_checkBox_log->setMinimumSize(QSize(110, 23));
        radf_checkBox_log->setChecked(true);

        radf_layout_opt->addWidget(radf_checkBox_log);

        radf_lineEdit_log = new QLineEdit(radf);
        radf_lineEdit_log->setObjectName(QString::fromUtf8("radf_lineEdit_log"));
        radf_lineEdit_log->setMinimumSize(QSize(150, 23));

        radf_layout_opt->addWidget(radf_lineEdit_log);

        radf_pushButton_log = new QPushButton(radf);
        radf_pushButton_log->setObjectName(QString::fromUtf8("radf_pushButton_log"));
        radf_pushButton_log->setMinimumSize(QSize(80, 23));
        radf_pushButton_log->setAutoDefault(true);

        radf_layout_opt->addWidget(radf_pushButton_log);


        verticalLayout_4->addLayout(radf_layout_opt);

        verticalSpacer_3 = new QSpacerItem(20, 47, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        radf_layout_buttons = new QHBoxLayout();
        radf_layout_buttons->setSpacing(6);
        radf_layout_buttons->setObjectName(QString::fromUtf8("radf_layout_buttons"));
        radf_pushButton_clear = new QPushButton(radf);
        radf_pushButton_clear->setObjectName(QString::fromUtf8("radf_pushButton_clear"));
        radf_pushButton_clear->setMinimumSize(QSize(80, 23));
        radf_pushButton_clear->setAutoDefault(true);

        radf_layout_buttons->addWidget(radf_pushButton_clear);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        radf_layout_buttons->addItem(horizontalSpacer_13);

        radf_pushButton_start = new QPushButton(radf);
        radf_pushButton_start->setObjectName(QString::fromUtf8("radf_pushButton_start"));
        radf_pushButton_start->setMinimumSize(QSize(80, 23));
        radf_pushButton_start->setMaximumSize(QSize(16777215, 16777215));
        radf_pushButton_start->setAutoDefault(true);

        radf_layout_buttons->addWidget(radf_pushButton_start);


        verticalLayout_4->addLayout(radf_layout_buttons);

        tabWidget->addTab(radf, QString());
        pdb = new QWidget();
        pdb->setObjectName(QString::fromUtf8("pdb"));
        verticalLayout_5 = new QVBoxLayout(pdb);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        pdb_comboBox_mode = new QComboBox(pdb);
        pdb_comboBox_mode->setObjectName(QString::fromUtf8("pdb_comboBox_mode"));

        verticalLayout_5->addWidget(pdb_comboBox_mode);

        pdb_layout_workDir = new QHBoxLayout();
        pdb_layout_workDir->setSpacing(6);
        pdb_layout_workDir->setObjectName(QString::fromUtf8("pdb_layout_workDir"));
        pdb_label_workDir = new QLabel(pdb);
        pdb_label_workDir->setObjectName(QString::fromUtf8("pdb_label_workDir"));
        pdb_label_workDir->setMinimumSize(QSize(110, 23));

        pdb_layout_workDir->addWidget(pdb_label_workDir);

        pdb_lineEdit_workDir = new QLineEdit(pdb);
        pdb_lineEdit_workDir->setObjectName(QString::fromUtf8("pdb_lineEdit_workDir"));
        pdb_lineEdit_workDir->setMinimumSize(QSize(280, 23));

        pdb_layout_workDir->addWidget(pdb_lineEdit_workDir);

        pdb_pushButton_workDir = new QPushButton(pdb);
        pdb_pushButton_workDir->setObjectName(QString::fromUtf8("pdb_pushButton_workDir"));
        pdb_pushButton_workDir->setMinimumSize(QSize(80, 23));
        pdb_pushButton_workDir->setAutoDefault(true);

        pdb_layout_workDir->addWidget(pdb_pushButton_workDir);


        verticalLayout_5->addLayout(pdb_layout_workDir);

        pdb_layout_input = new QHBoxLayout();
        pdb_layout_input->setSpacing(6);
        pdb_layout_input->setObjectName(QString::fromUtf8("pdb_layout_input"));
        pdb_label_input = new QLabel(pdb);
        pdb_label_input->setObjectName(QString::fromUtf8("pdb_label_input"));
        pdb_label_input->setMinimumSize(QSize(110, 23));

        pdb_layout_input->addWidget(pdb_label_input);

        pdb_lineEdit_input = new QLineEdit(pdb);
        pdb_lineEdit_input->setObjectName(QString::fromUtf8("pdb_lineEdit_input"));
        pdb_lineEdit_input->setMinimumSize(QSize(280, 23));

        pdb_layout_input->addWidget(pdb_lineEdit_input);

        pdb_pushButton_input = new QPushButton(pdb);
        pdb_pushButton_input->setObjectName(QString::fromUtf8("pdb_pushButton_input"));
        pdb_pushButton_input->setMinimumSize(QSize(80, 23));
        pdb_pushButton_input->setAutoDefault(true);

        pdb_layout_input->addWidget(pdb_pushButton_input);


        verticalLayout_5->addLayout(pdb_layout_input);

        pdb_layout_agl = new QHBoxLayout();
        pdb_layout_agl->setSpacing(6);
        pdb_layout_agl->setObjectName(QString::fromUtf8("pdb_layout_agl"));
        pdb_label_agl = new QLabel(pdb);
        pdb_label_agl->setObjectName(QString::fromUtf8("pdb_label_agl"));
        pdb_label_agl->setMinimumSize(QSize(150, 23));

        pdb_layout_agl->addWidget(pdb_label_agl);

        pdb_lineEdit_agl = new QLineEdit(pdb);
        pdb_lineEdit_agl->setObjectName(QString::fromUtf8("pdb_lineEdit_agl"));
        pdb_lineEdit_agl->setMinimumSize(QSize(280, 23));

        pdb_layout_agl->addWidget(pdb_lineEdit_agl);

        pdb_pushButton_agl = new QPushButton(pdb);
        pdb_pushButton_agl->setObjectName(QString::fromUtf8("pdb_pushButton_agl"));
        pdb_pushButton_agl->setMinimumSize(QSize(80, 23));
        pdb_pushButton_agl->setAutoDefault(true);

        pdb_layout_agl->addWidget(pdb_pushButton_agl);


        verticalLayout_5->addLayout(pdb_layout_agl);

        pdb_layout_cell = new QHBoxLayout();
        pdb_layout_cell->setSpacing(6);
        pdb_layout_cell->setObjectName(QString::fromUtf8("pdb_layout_cell"));
        pdb_label_cell = new QLabel(pdb);
        pdb_label_cell->setObjectName(QString::fromUtf8("pdb_label_cell"));
        pdb_label_cell->setMinimumSize(QSize(110, 23));

        pdb_layout_cell->addWidget(pdb_label_cell);

        pdb_label_cellX = new QLabel(pdb);
        pdb_label_cellX->setObjectName(QString::fromUtf8("pdb_label_cellX"));
        pdb_label_cellX->setMinimumSize(QSize(50, 23));

        pdb_layout_cell->addWidget(pdb_label_cellX);

        pdb_doubleSpinBox_cellX = new QDoubleSpinBox(pdb);
        pdb_doubleSpinBox_cellX->setObjectName(QString::fromUtf8("pdb_doubleSpinBox_cellX"));
        sizePolicy.setHeightForWidth(pdb_doubleSpinBox_cellX->sizePolicy().hasHeightForWidth());
        pdb_doubleSpinBox_cellX->setSizePolicy(sizePolicy);
        pdb_doubleSpinBox_cellX->setMinimumSize(QSize(55, 23));
        pdb_doubleSpinBox_cellX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pdb_doubleSpinBox_cellX->setDecimals(4);
        pdb_doubleSpinBox_cellX->setMinimum(0.1);
        pdb_doubleSpinBox_cellX->setMaximum(999.99);

        pdb_layout_cell->addWidget(pdb_doubleSpinBox_cellX);

        pdb_label_cellY = new QLabel(pdb);
        pdb_label_cellY->setObjectName(QString::fromUtf8("pdb_label_cellY"));
        pdb_label_cellY->setMinimumSize(QSize(50, 23));

        pdb_layout_cell->addWidget(pdb_label_cellY);

        pdb_doubleSpinBox_cellY = new QDoubleSpinBox(pdb);
        pdb_doubleSpinBox_cellY->setObjectName(QString::fromUtf8("pdb_doubleSpinBox_cellY"));
        sizePolicy.setHeightForWidth(pdb_doubleSpinBox_cellY->sizePolicy().hasHeightForWidth());
        pdb_doubleSpinBox_cellY->setSizePolicy(sizePolicy);
        pdb_doubleSpinBox_cellY->setMinimumSize(QSize(55, 23));
        pdb_doubleSpinBox_cellY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pdb_doubleSpinBox_cellY->setDecimals(4);
        pdb_doubleSpinBox_cellY->setMinimum(0.1);
        pdb_doubleSpinBox_cellY->setMaximum(999.99);

        pdb_layout_cell->addWidget(pdb_doubleSpinBox_cellY);

        pdb_label_cellZ = new QLabel(pdb);
        pdb_label_cellZ->setObjectName(QString::fromUtf8("pdb_label_cellZ"));
        pdb_label_cellZ->setMinimumSize(QSize(50, 23));

        pdb_layout_cell->addWidget(pdb_label_cellZ);

        pdb_doubleSpinBox_cellZ = new QDoubleSpinBox(pdb);
        pdb_doubleSpinBox_cellZ->setObjectName(QString::fromUtf8("pdb_doubleSpinBox_cellZ"));
        sizePolicy.setHeightForWidth(pdb_doubleSpinBox_cellZ->sizePolicy().hasHeightForWidth());
        pdb_doubleSpinBox_cellZ->setSizePolicy(sizePolicy);
        pdb_doubleSpinBox_cellZ->setMinimumSize(QSize(55, 23));
        pdb_doubleSpinBox_cellZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pdb_doubleSpinBox_cellZ->setDecimals(4);
        pdb_doubleSpinBox_cellZ->setMinimum(0.1);
        pdb_doubleSpinBox_cellZ->setMaximum(999.99);

        pdb_layout_cell->addWidget(pdb_doubleSpinBox_cellZ);


        verticalLayout_5->addLayout(pdb_layout_cell);

        pdb_layout_output = new QHBoxLayout();
        pdb_layout_output->setSpacing(6);
        pdb_layout_output->setObjectName(QString::fromUtf8("pdb_layout_output"));
        pdb_label_output = new QLabel(pdb);
        pdb_label_output->setObjectName(QString::fromUtf8("pdb_label_output"));
        pdb_label_output->setMinimumSize(QSize(110, 23));

        pdb_layout_output->addWidget(pdb_label_output);

        pdb_lineEdit_output = new QLineEdit(pdb);
        pdb_lineEdit_output->setObjectName(QString::fromUtf8("pdb_lineEdit_output"));
        pdb_lineEdit_output->setMinimumSize(QSize(280, 23));

        pdb_layout_output->addWidget(pdb_lineEdit_output);

        pdb_pushButton_output = new QPushButton(pdb);
        pdb_pushButton_output->setObjectName(QString::fromUtf8("pdb_pushButton_output"));
        pdb_pushButton_output->setMinimumSize(QSize(80, 23));
        pdb_pushButton_output->setAutoDefault(true);

        pdb_layout_output->addWidget(pdb_pushButton_output);


        verticalLayout_5->addLayout(pdb_layout_output);

        pdb_layout_opt = new QHBoxLayout();
        pdb_layout_opt->setSpacing(6);
        pdb_layout_opt->setObjectName(QString::fromUtf8("pdb_layout_opt"));
        pdb_checkBox_log = new QCheckBox(pdb);
        pdb_checkBox_log->setObjectName(QString::fromUtf8("pdb_checkBox_log"));
        pdb_checkBox_log->setMinimumSize(QSize(110, 23));
        pdb_checkBox_log->setChecked(true);

        pdb_layout_opt->addWidget(pdb_checkBox_log);

        pdb_lineEdit_log = new QLineEdit(pdb);
        pdb_lineEdit_log->setObjectName(QString::fromUtf8("pdb_lineEdit_log"));
        pdb_lineEdit_log->setMinimumSize(QSize(173, 23));

        pdb_layout_opt->addWidget(pdb_lineEdit_log);

        pdb_pushButton_log = new QPushButton(pdb);
        pdb_pushButton_log->setObjectName(QString::fromUtf8("pdb_pushButton_log"));
        pdb_pushButton_log->setMinimumSize(QSize(80, 23));
        pdb_pushButton_log->setAutoDefault(true);

        pdb_layout_opt->addWidget(pdb_pushButton_log);


        verticalLayout_5->addLayout(pdb_layout_opt);

        verticalSpacer_4 = new QSpacerItem(20, 147, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);

        pdb_layout_buttons = new QHBoxLayout();
        pdb_layout_buttons->setSpacing(6);
        pdb_layout_buttons->setObjectName(QString::fromUtf8("pdb_layout_buttons"));
        pdb_pushButton_clear = new QPushButton(pdb);
        pdb_pushButton_clear->setObjectName(QString::fromUtf8("pdb_pushButton_clear"));
        pdb_pushButton_clear->setMinimumSize(QSize(80, 23));
        pdb_pushButton_clear->setAutoDefault(true);

        pdb_layout_buttons->addWidget(pdb_pushButton_clear);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        pdb_layout_buttons->addItem(horizontalSpacer_15);

        pdb_pushButton_start = new QPushButton(pdb);
        pdb_pushButton_start->setObjectName(QString::fromUtf8("pdb_pushButton_start"));
        pdb_pushButton_start->setMinimumSize(QSize(80, 23));
        pdb_pushButton_start->setMaximumSize(QSize(16777215, 16777215));
        pdb_pushButton_start->setAutoDefault(true);

        pdb_layout_buttons->addWidget(pdb_pushButton_start);


        verticalLayout_5->addLayout(pdb_layout_buttons);

        tabWidget->addTab(pdb, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 564, 20));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuFile_creator = new QMenu(menuMenu);
        menuFile_creator->setObjectName(QString::fromUtf8("menuFile_creator"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(tabWidget, trj_lineEdit_workDir);
        QWidget::setTabOrder(trj_lineEdit_workDir, trj_pushButton_workDir);
        QWidget::setTabOrder(trj_pushButton_workDir, trj_lineEdit_input);
        QWidget::setTabOrder(trj_lineEdit_input, trj_pushButton_input);
        QWidget::setTabOrder(trj_pushButton_input, trj_comboBox_type);
        QWidget::setTabOrder(trj_comboBox_type, trj_spinBox_steps);
        QWidget::setTabOrder(trj_spinBox_steps, trj_lineEdit_atoms);
        QWidget::setTabOrder(trj_lineEdit_atoms, trj_pushButton_atoms);
        QWidget::setTabOrder(trj_pushButton_atoms, trj_lineEdit_output);
        QWidget::setTabOrder(trj_lineEdit_output, trj_spinBox_totalTypes);
        QWidget::setTabOrder(trj_spinBox_totalTypes, trj_checkBox_log);
        QWidget::setTabOrder(trj_checkBox_log, trj_lineEdit_log);
        QWidget::setTabOrder(trj_lineEdit_log, trj_pushButton_log);
        QWidget::setTabOrder(trj_pushButton_log, trj_pushButton_clear);
        QWidget::setTabOrder(trj_pushButton_clear, trj_pushButton_start);
        QWidget::setTabOrder(trj_pushButton_start, statgen_lineEdit_workDir);
        QWidget::setTabOrder(statgen_lineEdit_workDir, statgen_pushButton_workDir);
        QWidget::setTabOrder(statgen_pushButton_workDir, statgen_lineEdit_input);
        QWidget::setTabOrder(statgen_lineEdit_input, statgen_spinBox_stepsFirst);
        QWidget::setTabOrder(statgen_spinBox_stepsFirst, statgen_spinBox_stepsLast);
        QWidget::setTabOrder(statgen_spinBox_stepsLast, statgen_doubleSpinBox_cellX);
        QWidget::setTabOrder(statgen_doubleSpinBox_cellX, statgen_doubleSpinBox_cellY);
        QWidget::setTabOrder(statgen_doubleSpinBox_cellY, statgen_doubleSpinBox_cellZ);
        QWidget::setTabOrder(statgen_doubleSpinBox_cellZ, statgen_spinBox_atoms0);
        QWidget::setTabOrder(statgen_spinBox_atoms0, statgen_checkBox_atoms1);
        QWidget::setTabOrder(statgen_checkBox_atoms1, statgen_spinBox_atoms1);
        QWidget::setTabOrder(statgen_spinBox_atoms1, statgen_checkBox_atoms2);
        QWidget::setTabOrder(statgen_checkBox_atoms2, statgen_spinBox_atoms2);
        QWidget::setTabOrder(statgen_spinBox_atoms2, statgen_checkBox_atoms3);
        QWidget::setTabOrder(statgen_checkBox_atoms3, statgen_spinBox_atoms3);
        QWidget::setTabOrder(statgen_spinBox_atoms3, statgen_comboBox_int);
        QWidget::setTabOrder(statgen_comboBox_int, statgen_doubleSpinBox_int);
        QWidget::setTabOrder(statgen_doubleSpinBox_int, stagen_pushButton_intSave);
        QWidget::setTabOrder(stagen_pushButton_intSave, statgen_pushButton_intAdd);
        QWidget::setTabOrder(statgen_pushButton_intAdd, statgen_listWidget_int);
        QWidget::setTabOrder(statgen_listWidget_int, stagen_pushButton_intRem);
        QWidget::setTabOrder(stagen_pushButton_intRem, statgen_lineEdit_output);
        QWidget::setTabOrder(statgen_lineEdit_output, statgen_pushButton_output);
        QWidget::setTabOrder(statgen_pushButton_output, statgen_checkBox_depth);
        QWidget::setTabOrder(statgen_checkBox_depth, statgen_spinBox_depth);
        QWidget::setTabOrder(statgen_spinBox_depth, statgen_checkBox_log);
        QWidget::setTabOrder(statgen_checkBox_log, statgen_lineEdit_log);
        QWidget::setTabOrder(statgen_lineEdit_log, statgen_pushButton_log);
        QWidget::setTabOrder(statgen_pushButton_log, statgen_pushButton_clear);
        QWidget::setTabOrder(statgen_pushButton_clear, statgen_pushButton_start);
        QWidget::setTabOrder(statgen_pushButton_start, envir_lineEdit_workDir);
        QWidget::setTabOrder(envir_lineEdit_workDir, envir_pushButton_workDir);
        QWidget::setTabOrder(envir_pushButton_workDir, envir_lineEdit_input);
        QWidget::setTabOrder(envir_lineEdit_input, envir_pushButton_input);
        QWidget::setTabOrder(envir_pushButton_input, envir_doubleSpinBox_cellX);
        QWidget::setTabOrder(envir_doubleSpinBox_cellX, envir_doubleSpinBox_cellY);
        QWidget::setTabOrder(envir_doubleSpinBox_cellY, envir_doubleSpinBox_cellZ);
        QWidget::setTabOrder(envir_doubleSpinBox_cellZ, envir_lineEdit_output);
        QWidget::setTabOrder(envir_lineEdit_output, envir_pushButton_output);
        QWidget::setTabOrder(envir_pushButton_output, envir_spinBox_molecule);
        QWidget::setTabOrder(envir_spinBox_molecule, envir_doubleSpinBox_radius);
        QWidget::setTabOrder(envir_doubleSpinBox_radius, envir_checkBox_log);
        QWidget::setTabOrder(envir_checkBox_log, envir_lineEdit_log);
        QWidget::setTabOrder(envir_lineEdit_log, envir_pushButton_log);
        QWidget::setTabOrder(envir_pushButton_log, envir_pushButton_clear);
        QWidget::setTabOrder(envir_pushButton_clear, envir_pushButton_start);
        QWidget::setTabOrder(envir_pushButton_start, radf_lineEdit_workDir);
        QWidget::setTabOrder(radf_lineEdit_workDir, radf_pushButton_workDir);
        QWidget::setTabOrder(radf_pushButton_workDir, radf_lineEdit_input);
        QWidget::setTabOrder(radf_lineEdit_input, radf_spinBox_stepsFirst);
        QWidget::setTabOrder(radf_spinBox_stepsFirst, radf_spinBox_stepsLast);
        QWidget::setTabOrder(radf_spinBox_stepsLast, radf_doubleSpinBox_cellX);
        QWidget::setTabOrder(radf_doubleSpinBox_cellX, radf_doubleSpinBox_cellY);
        QWidget::setTabOrder(radf_doubleSpinBox_cellY, radf_doubleSpinBox_cellZ);
        QWidget::setTabOrder(radf_doubleSpinBox_cellZ, radf_lineEdit_output);
        QWidget::setTabOrder(radf_lineEdit_output, radf_pushButton_output);
        QWidget::setTabOrder(radf_pushButton_output, radf_comboBox_atom);
        QWidget::setTabOrder(radf_comboBox_atom, radf_spinBox_atoms0);
        QWidget::setTabOrder(radf_spinBox_atoms0, radf_spinBox_atoms1);
        QWidget::setTabOrder(radf_spinBox_atoms1, radf_spinBox_atoms2);
        QWidget::setTabOrder(radf_spinBox_atoms2, radf_spinBox_atoms3);
        QWidget::setTabOrder(radf_spinBox_atoms3, radf_spinBox_atoms4);
        QWidget::setTabOrder(radf_spinBox_atoms4, radf_spinBox_atoms5);
        QWidget::setTabOrder(radf_spinBox_atoms5, radf_doubleSpinBox_radMin);
        QWidget::setTabOrder(radf_doubleSpinBox_radMin, radf_doubleSpinBox_radMax);
        QWidget::setTabOrder(radf_doubleSpinBox_radMax, radf_doubleSpinBox_radStep);
        QWidget::setTabOrder(radf_doubleSpinBox_radStep, radf_checkBox_ang);
        QWidget::setTabOrder(radf_checkBox_ang, radf_doubleSpinBox_angMin);
        QWidget::setTabOrder(radf_doubleSpinBox_angMin, radf_doubleSpinBox_angMax);
        QWidget::setTabOrder(radf_doubleSpinBox_angMax, radf_doubleSpinBox_angStep);
        QWidget::setTabOrder(radf_doubleSpinBox_angStep, radf_checkBox_matrix);
        QWidget::setTabOrder(radf_checkBox_matrix, radf_checkBox_log);
        QWidget::setTabOrder(radf_checkBox_log, radf_lineEdit_log);
        QWidget::setTabOrder(radf_lineEdit_log, radf_pushButton_log);
        QWidget::setTabOrder(radf_pushButton_log, radf_pushButton_clear);
        QWidget::setTabOrder(radf_pushButton_clear, radf_pushButton_start);
        QWidget::setTabOrder(radf_pushButton_start, pdb_comboBox_mode);
        QWidget::setTabOrder(pdb_comboBox_mode, pdb_lineEdit_workDir);
        QWidget::setTabOrder(pdb_lineEdit_workDir, pdb_pushButton_workDir);
        QWidget::setTabOrder(pdb_pushButton_workDir, pdb_lineEdit_input);
        QWidget::setTabOrder(pdb_lineEdit_input, pdb_pushButton_input);
        QWidget::setTabOrder(pdb_pushButton_input, pdb_lineEdit_agl);
        QWidget::setTabOrder(pdb_lineEdit_agl, pdb_pushButton_agl);
        QWidget::setTabOrder(pdb_pushButton_agl, pdb_doubleSpinBox_cellX);
        QWidget::setTabOrder(pdb_doubleSpinBox_cellX, pdb_doubleSpinBox_cellY);
        QWidget::setTabOrder(pdb_doubleSpinBox_cellY, pdb_doubleSpinBox_cellZ);
        QWidget::setTabOrder(pdb_doubleSpinBox_cellZ, pdb_lineEdit_output);
        QWidget::setTabOrder(pdb_lineEdit_output, pdb_pushButton_output);
        QWidget::setTabOrder(pdb_pushButton_output, pdb_checkBox_log);
        QWidget::setTabOrder(pdb_checkBox_log, pdb_lineEdit_log);
        QWidget::setTabOrder(pdb_lineEdit_log, pdb_pushButton_log);
        QWidget::setTabOrder(pdb_pushButton_log, pdb_pushButton_clear);
        QWidget::setTabOrder(pdb_pushButton_clear, pdb_pushButton_start);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuMenu->addAction(menuFile_creator->menuAction());
        menuMenu->addAction(actionExit);
        menuFile_creator->addAction(actionAtom_types_file);
        menuFile_creator->addAction(actionAgglomerate_file);
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Mathematical Molecular Mechanics", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "&Quit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
        actionHelp->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionAtom_types_file->setText(QApplication::translate("MainWindow", "Atom &types file", 0, QApplication::UnicodeUTF8));
        actionAgglomerate_file->setText(QApplication::translate("MainWindow", "&Agglomerate file", 0, QApplication::UnicodeUTF8));
        trj_label_workDir->setText(QApplication::translate("MainWindow", "Work directory", 0, QApplication::UnicodeUTF8));
        trj_pushButton_workDir->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        trj_label_input->setText(QApplication::translate("MainWindow", "Input file", 0, QApplication::UnicodeUTF8));
        trj_pushButton_input->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        trj_label_type->setText(QApplication::translate("MainWindow", "Type of trajectory", 0, QApplication::UnicodeUTF8));
        trj_comboBox_type->clear();
        trj_comboBox_type->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "GROMACS text", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "PUMA", 0, QApplication::UnicodeUTF8)
        );
        trj_label_steps->setText(QApplication::translate("MainWindow", "Number of steps", 0, QApplication::UnicodeUTF8));
        trj_label_atoms->setText(QApplication::translate("MainWindow", "Atom type file", 0, QApplication::UnicodeUTF8));
        trj_pushButton_atoms->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        trj_label_output->setText(QApplication::translate("MainWindow", "Mask of output files", 0, QApplication::UnicodeUTF8));
        trj_label_totalTypes->setText(QApplication::translate("MainWindow", "Total atom types", 0, QApplication::UnicodeUTF8));
        trj_checkBox_log->setText(QApplication::translate("MainWindow", "Log", 0, QApplication::UnicodeUTF8));
        trj_pushButton_log->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        trj_pushButton_clear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        trj_pushButton_start->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(trj), QApplication::translate("MainWindow", "Generate trajectory", 0, QApplication::UnicodeUTF8));
        statgen_label_workDir->setText(QApplication::translate("MainWindow", "Work directory", 0, QApplication::UnicodeUTF8));
        statgen_pushButton_workDir->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        statgen_label_input->setText(QApplication::translate("MainWindow", "Mask of input files", 0, QApplication::UnicodeUTF8));
        statgen_label_steps->setText(QApplication::translate("MainWindow", "Steps", 0, QApplication::UnicodeUTF8));
        statgen_label_stepsFirst->setText(QApplication::translate("MainWindow", "first", 0, QApplication::UnicodeUTF8));
        statgen_label_stepsLast->setText(QApplication::translate("MainWindow", "last", 0, QApplication::UnicodeUTF8));
        statgen_label_cell->setText(QApplication::translate("MainWindow", "Cell, A", 0, QApplication::UnicodeUTF8));
        statgen_label_cellX->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        statgen_label_cellY->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        statgen_label_cellZ->setText(QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8));
        statgen_label_atoms0->setText(QApplication::translate("MainWindow", "atom 0", 0, QApplication::UnicodeUTF8));
        statgen_checkBox_atoms1->setText(QApplication::translate("MainWindow", "atom 1", 0, QApplication::UnicodeUTF8));
        statgen_checkBox_atoms2->setText(QApplication::translate("MainWindow", "atom 2", 0, QApplication::UnicodeUTF8));
        statgen_checkBox_atoms3->setText(QApplication::translate("MainWindow", "atom 3", 0, QApplication::UnicodeUTF8));
        statgen_label_int->setText(QApplication::translate("MainWindow", "Interaction", 0, QApplication::UnicodeUTF8));
        statgen_comboBox_int->clear();
        statgen_comboBox_int->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0-0", 0, QApplication::UnicodeUTF8)
        );
        stagen_pushButton_intSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        statgen_pushButton_intAdd->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        stagen_pushButton_intRem->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
        statgen_label_output->setText(QApplication::translate("MainWindow", "Output file", 0, QApplication::UnicodeUTF8));
        statgen_pushButton_output->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        statgen_checkBox_depth->setText(QApplication::translate("MainWindow", "Depth of search", 0, QApplication::UnicodeUTF8));
        statgen_checkBox_log->setText(QApplication::translate("MainWindow", "Log", 0, QApplication::UnicodeUTF8));
        statgen_pushButton_log->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        statgen_pushButton_clear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        statgen_pushButton_start->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(statgen), QApplication::translate("MainWindow", "Agglomeration", 0, QApplication::UnicodeUTF8));
        envir_label_workDir->setText(QApplication::translate("MainWindow", "Work directory", 0, QApplication::UnicodeUTF8));
        envir_pushButton_workDir->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        envir_label_input->setText(QApplication::translate("MainWindow", "Input file", 0, QApplication::UnicodeUTF8));
        envir_pushButton_input->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        envir_label_cell->setText(QApplication::translate("MainWindow", "Cell, A", 0, QApplication::UnicodeUTF8));
        envir_label_cellX->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        envir_label_cellY->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        envir_label_cellZ->setText(QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8));
        envir_label_output->setText(QApplication::translate("MainWindow", "Output file", 0, QApplication::UnicodeUTF8));
        envir_pushButton_output->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        envir_label_molecule->setText(QApplication::translate("MainWindow", "Molecule", 0, QApplication::UnicodeUTF8));
        envir_label_radius->setText(QApplication::translate("MainWindow", "Radius", 0, QApplication::UnicodeUTF8));
        envir_checkBox_log->setText(QApplication::translate("MainWindow", "Log", 0, QApplication::UnicodeUTF8));
        envir_pushButton_log->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        envir_pushButton_clear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        envir_pushButton_start->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(envir), QApplication::translate("MainWindow", "Environment", 0, QApplication::UnicodeUTF8));
        radf_label_workDir->setText(QApplication::translate("MainWindow", "Work directory", 0, QApplication::UnicodeUTF8));
        radf_pushButton_workDir->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        radf_label_input->setText(QApplication::translate("MainWindow", "Mask of input files", 0, QApplication::UnicodeUTF8));
        radf_label_steps->setText(QApplication::translate("MainWindow", "Steps", 0, QApplication::UnicodeUTF8));
        radf_label_stepsFirst->setText(QApplication::translate("MainWindow", "first", 0, QApplication::UnicodeUTF8));
        radf_label_stepsLast->setText(QApplication::translate("MainWindow", "last", 0, QApplication::UnicodeUTF8));
        radf_label_cell->setText(QApplication::translate("MainWindow", "Cell, A", 0, QApplication::UnicodeUTF8));
        radf_label_cellX->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        radf_label_cellY->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        radf_label_cellZ->setText(QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8));
        radf_label_output->setText(QApplication::translate("MainWindow", "Output file", 0, QApplication::UnicodeUTF8));
        radf_pushButton_output->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        radf_comboBox_atom->clear();
        radf_comboBox_atom->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "One atom function", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Three atom function", 0, QApplication::UnicodeUTF8)
        );
        radf_label_atoms0->setText(QApplication::translate("MainWindow", "atom 1", 0, QApplication::UnicodeUTF8));
        radf_label_atoms1->setText(QApplication::translate("MainWindow", "atom 2", 0, QApplication::UnicodeUTF8));
        radf_label_atoms2->setText(QApplication::translate("MainWindow", "atom 3", 0, QApplication::UnicodeUTF8));
        radf_label_atoms3->setText(QApplication::translate("MainWindow", "atom 1", 0, QApplication::UnicodeUTF8));
        radf_label_atoms4->setText(QApplication::translate("MainWindow", "atom 2", 0, QApplication::UnicodeUTF8));
        radf_label_atoms5->setText(QApplication::translate("MainWindow", "atom 3", 0, QApplication::UnicodeUTF8));
        radf_label_rad->setText(QApplication::translate("MainWindow", "R, A", 0, QApplication::UnicodeUTF8));
        radf_label_radMin->setText(QApplication::translate("MainWindow", "min", 0, QApplication::UnicodeUTF8));
        radf_label_radMax->setText(QApplication::translate("MainWindow", "max", 0, QApplication::UnicodeUTF8));
        radf_label_radStep->setText(QApplication::translate("MainWindow", "step", 0, QApplication::UnicodeUTF8));
        radf_checkBox_ang->setText(QApplication::translate("MainWindow", "Angle, deg", 0, QApplication::UnicodeUTF8));
        radf_label_angMin->setText(QApplication::translate("MainWindow", "min", 0, QApplication::UnicodeUTF8));
        radf_label_angMax->setText(QApplication::translate("MainWindow", "max", 0, QApplication::UnicodeUTF8));
        radf_label_angStep->setText(QApplication::translate("MainWindow", "step", 0, QApplication::UnicodeUTF8));
        radf_checkBox_matrix->setText(QApplication::translate("MainWindow", "Matrix", 0, QApplication::UnicodeUTF8));
        radf_checkBox_log->setText(QApplication::translate("MainWindow", "Log", 0, QApplication::UnicodeUTF8));
        radf_pushButton_log->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        radf_pushButton_clear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        radf_pushButton_start->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(radf), QApplication::translate("MainWindow", "RADF", 0, QApplication::UnicodeUTF8));
        pdb_comboBox_mode->clear();
        pdb_comboBox_mode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "From agglomerate", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "From trajectory snapshot", 0, QApplication::UnicodeUTF8)
        );
        pdb_label_workDir->setText(QApplication::translate("MainWindow", "Work directory", 0, QApplication::UnicodeUTF8));
        pdb_pushButton_workDir->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        pdb_label_input->setText(QApplication::translate("MainWindow", "Input file", 0, QApplication::UnicodeUTF8));
        pdb_pushButton_input->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        pdb_label_agl->setText(QApplication::translate("MainWindow", "File with agglomerate", 0, QApplication::UnicodeUTF8));
        pdb_pushButton_agl->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        pdb_label_cell->setText(QApplication::translate("MainWindow", "Cell, A", 0, QApplication::UnicodeUTF8));
        pdb_label_cellX->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        pdb_label_cellY->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        pdb_label_cellZ->setText(QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8));
        pdb_label_output->setText(QApplication::translate("MainWindow", "Output file", 0, QApplication::UnicodeUTF8));
        pdb_pushButton_output->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        pdb_checkBox_log->setText(QApplication::translate("MainWindow", "Log", 0, QApplication::UnicodeUTF8));
        pdb_pushButton_log->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        pdb_pushButton_clear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        pdb_pushButton_start->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(pdb), QApplication::translate("MainWindow", "Generate PDB", 0, QApplication::UnicodeUTF8));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0, QApplication::UnicodeUTF8));
        menuFile_creator->setTitle(QApplication::translate("MainWindow", "File creator", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
