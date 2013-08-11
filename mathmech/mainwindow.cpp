#include <QFileDialog>
#include <QDir>

#include "aboutwindow.h"
#include "agglwindow.h"
#include "aglallwindow.h"
#include "atomtypeswindow.h"
#include "settingswindow.h"
#include "clear_items.h"
#include "start_events.h"
#include "statgengraphwindow.h"
#include "update_fields.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  clear_items(new Clear_items(this)),
  update_fields(new Update_fields(this))
{
  ui->setupUi(this);
  statgen_crit = new float[10];

  ui->statusBar->showMessage(QApplication::translate("MainWindow", "Ready"));

  createActions();

  SettingsWindow *settingsWindow;
  settingsWindow = new SettingsWindow(this);
  delete settingsWindow;
}

MainWindow::~MainWindow()
{
  delete ui;
  delete clear_items;
  delete start_events;
  delete update_fields;
  delete statgen_crit;
}

// signals
void MainWindow::on_trj_checkBox_log_stateChanged(int arg1)
{
  if (arg1 == 0)
  {
    ui->trj_lineEdit_log->setDisabled(true);
    ui->trj_pushButton_log->setDisabled(true);
  }
  else if (arg1 == 2)
  {
    ui->trj_lineEdit_log->setEnabled(true);
    ui->trj_pushButton_log->setEnabled(true);
  }
}

void MainWindow::on_statgen_checkBox_depth_stateChanged(int arg1)
{
  if (arg1 == 0)
    ui->statgen_spinBox_depth->setDisabled(true);
  else if (arg1 == 2)
    ui->statgen_spinBox_depth->setEnabled(true);
}

void MainWindow::on_statgen_checkBox_log_stateChanged(int arg1)
{
  if (arg1 == 0)
  {
    ui->statgen_lineEdit_log->setDisabled(true);
    ui->statgen_pushButton_log->setDisabled(true);
  }
  else if (arg1 == 2)
  {
    ui->statgen_lineEdit_log->setEnabled(true);
    ui->statgen_pushButton_log->setEnabled(true);
  }
}

void MainWindow::on_statgen_checkBox_atoms1_stateChanged(int arg1)
{
  if (arg1 == 0)
  {
    ui->statgen_spinBox_atoms1->setDisabled(true);
    ui->statgen_checkBox_atoms2->setCheckState(Qt::Unchecked);
    ui->statgen_checkBox_atoms2->setDisabled(true);
  }
  else if (arg1 == 2)
  {
    ui->statgen_spinBox_atoms1->setEnabled(true);
    ui->statgen_checkBox_atoms2->setEnabled(true);
  }
  update_interaction();
}

void MainWindow::on_statgen_checkBox_atoms2_stateChanged(int arg1)
{
  if (arg1 == 0)
  {
    ui->statgen_spinBox_atoms2->setDisabled(true);
    ui->statgen_checkBox_atoms3->setCheckState(Qt::Unchecked);
    ui->statgen_checkBox_atoms3->setDisabled(true);
  }
  else if (arg1 == 2)
  {
    ui->statgen_spinBox_atoms2->setEnabled(true);
    ui->statgen_checkBox_atoms3->setEnabled(true);
  }
  update_interaction();
}

void MainWindow::on_statgen_checkBox_atoms3_stateChanged(int arg1)
{
  if (arg1 == 0)
    ui->statgen_spinBox_atoms3->setDisabled(true);
  else if (arg1 == 2)
    ui->statgen_spinBox_atoms3->setEnabled(true);
  update_interaction();
}

void MainWindow::on_statgen_checkBox_anal_stateChanged(int arg1)
{
  if (arg1 == 0)
    ui->statgen_doubleSpinBox_anal->setDisabled(true);
  else if (arg1 == 2)
    ui->statgen_doubleSpinBox_anal->setEnabled(true);
}

void MainWindow::on_envir_checkBox_log_stateChanged(int arg1)
{
  if (arg1 == 0)
  {
    ui->envir_lineEdit_log->setDisabled(true);
    ui->envir_pushButton_log->setDisabled(true);
  }
  else if (arg1 == 2)
  {
    ui->envir_lineEdit_log->setEnabled(true);
    ui->envir_pushButton_log->setEnabled(true);
  }
}

void MainWindow::on_radf_comboBox_atom_currentIndexChanged(int index)
{
  if (index == 0)
  {
    ui->radf_spinBox_atoms1->setDisabled(true);
    ui->radf_spinBox_atoms2->setDisabled(true);
    ui->radf_spinBox_atoms4->setDisabled(true);
    ui->radf_spinBox_atoms5->setDisabled(true);
  }
  else if (index == 1)
  {
    ui->radf_spinBox_atoms1->setEnabled(true);
    ui->radf_spinBox_atoms2->setEnabled(true);
    ui->radf_spinBox_atoms4->setEnabled(true);
    ui->radf_spinBox_atoms5->setEnabled(true);
  }
}

void MainWindow::on_radf_checkBox_ang_stateChanged(int arg1)
{
  if (arg1 == 0)
  {
    ui->radf_checkBox_graph->setCheckState(Qt::Checked);
    ui->radf_doubleSpinBox_angMax->setDisabled(true);
    ui->radf_doubleSpinBox_angMin->setDisabled(true);
    ui->radf_doubleSpinBox_angStep->setDisabled(true);
    ui->radf_checkBox_graph->setEnabled(true);
  }
  else if (arg1 == 2)
  {
    ui->radf_checkBox_graph->setCheckState(Qt::Unchecked);
    ui->radf_doubleSpinBox_angMax->setEnabled(true);
    ui->radf_doubleSpinBox_angMin->setEnabled(true);
    ui->radf_doubleSpinBox_angStep->setEnabled(true);
    ui->radf_checkBox_graph->setDisabled(true);
  }
}

void MainWindow::on_radf_checkBox_log_stateChanged(int arg1)
{
  if (arg1 == 0)
  {
    ui->radf_lineEdit_log->setDisabled(true);
    ui->radf_pushButton_log->setDisabled(true);
  }
  else if (arg1 == 2)
  {
    ui->radf_lineEdit_log->setEnabled(true);
    ui->radf_pushButton_log->setEnabled(true);
  }
}

void MainWindow::on_pdb_comboBox_mode_currentIndexChanged(int index)
{
  if (index == 1)
  {
    ui->pdb_lineEdit_agl->setDisabled(true);
    ui->pdb_pushButton_agl->setDisabled(true);
    ui->pdb_doubleSpinBox_cellX->setDisabled(true);
    ui->pdb_doubleSpinBox_cellY->setDisabled(true);
    ui->pdb_doubleSpinBox_cellZ->setDisabled(true);
  }
  else if (index == 0)
  {
    ui->pdb_lineEdit_agl->setEnabled(true);
    ui->pdb_pushButton_agl->setEnabled(true);
    ui->pdb_doubleSpinBox_cellX->setEnabled(true);
    ui->pdb_doubleSpinBox_cellY->setEnabled(true);
    ui->pdb_doubleSpinBox_cellZ->setEnabled(true);
  }
}

void MainWindow::on_pdb_checkBox_log_stateChanged(int arg1)
{
  if (arg1 == 0)
  {
    ui->pdb_lineEdit_log->setDisabled(true);
    ui->pdb_pushButton_log->setDisabled(true);
  }
  else if (arg1 == 2)
  {
    ui->pdb_lineEdit_log->setEnabled(true);
    ui->pdb_pushButton_log->setEnabled(true);
  }
}

// file dialogs
void MainWindow::on_trj_pushButton_workDir_clicked()
{
  QString dirname = QFileDialog::getExistingDirectory(
                    this,
                    tr("Select work directory"),
                    QDir::currentPath());
  if (!dirname.isEmpty())
    ui->trj_lineEdit_workDir->setText(dirname);
}

void MainWindow::on_trj_pushButton_input_clicked()
{
  QString filename = QFileDialog::getOpenFileName(
                     this,
                     tr("Select trajectory file"),
                     QDir(ui->trj_lineEdit_workDir->text()).absolutePath(),
                     tr("All files (*.*)"));
  if (!filename.isEmpty())
    ui->trj_lineEdit_input->setText(filename);
}

void MainWindow::on_trj_pushButton_atoms_clicked()
{
  QString filename = QFileDialog::getOpenFileName(
                     this,
                     tr("Select atom types file"),
                     QDir(ui->trj_lineEdit_workDir->text()).absolutePath(),
                     tr("Atom types files (*.types);;All files (*.*)"));
  if (!filename.isEmpty())
    ui->trj_lineEdit_atoms->setText(filename);
}

void MainWindow::on_trj_pushButton_output_clicked()
{
  QString filename = QFileDialog::getSaveFileName(
                     this,
                     tr("Save files as"),
                     QDir(ui->trj_lineEdit_workDir->text()).absolutePath(),
                     tr("Mask of trajectory files"));
  if (!filename.isEmpty())
    ui->trj_lineEdit_output->setText(filename);
}

void MainWindow::on_trj_pushButton_log_clicked()
{
  QString filename = QFileDialog::getSaveFileName(
                     this,
                     tr("Save log file as..."),
                     QDir(ui->trj_lineEdit_workDir->text()).absolutePath(),
                     tr("Log files (*.log)"));
  if (!filename.isEmpty())
    ui->trj_lineEdit_log->setText(filename);
}

void MainWindow::on_statgen_pushButton_workDir_clicked()
{
  QString dirname = QFileDialog::getExistingDirectory(
                    this,
                    tr("Select work directory"),
                    QDir::currentPath());
  if (!dirname.isEmpty())
    ui->statgen_lineEdit_workDir->setText(dirname);
}

void MainWindow::on_statgen_pushButton_input_clicked()
{
  QString filename = QFileDialog::getOpenFileName(
                     this,
                     tr("Select trajectory files"),
                     QDir(ui->statgen_lineEdit_workDir->text()).absolutePath(),
                     tr("Trajectory files (*.*[0-9])"));
  if (!filename.isEmpty())
    ui->statgen_lineEdit_input->setText(filename.split(QString("."))[0]);
}

void MainWindow::on_statgen_pushButton_output_clicked()
{
  QString filename = QFileDialog::getSaveFileName(
                     this,
                     tr("Save output file as..."),
                     QDir(ui->statgen_lineEdit_workDir->text()).absolutePath(),
                     tr("Output files (*.dat)"));
  if (!filename.isEmpty())
    ui->statgen_lineEdit_output->setText(filename);
}

void MainWindow::on_statgen_pushButton_log_clicked()
{
  QString filename = QFileDialog::getSaveFileName(
                     this,
                     tr("Save log file as..."),
                     QDir(ui->statgen_lineEdit_workDir->text()).absolutePath(),
                     tr("Log files (*.log)"));
  if (!filename.isEmpty())
    ui->statgen_lineEdit_log->setText(filename);
}

void MainWindow::on_envir_pushButton_workDir_clicked()
{
  QString dirname = QFileDialog::getExistingDirectory(
                    this,
                    tr("Select work directory"),
                    QDir::currentPath());
  if (!dirname.isEmpty())
    ui->envir_lineEdit_workDir->setText(dirname);
}

void MainWindow::on_envir_pushButton_input_clicked()
{
  QString filename = QFileDialog::getOpenFileName(
                     this,
                     tr("Select trajectory file"),
                     QDir(ui->envir_lineEdit_workDir->text()).absolutePath(),
                     tr("Trajectory files (*.*[0-9])"));
  if (!filename.isEmpty())
    ui->envir_lineEdit_input->setText(filename);
}

void MainWindow::on_envir_pushButton_output_clicked()
{
  QString filename = QFileDialog::getSaveFileName(
                     this,
                     tr("Save PDB file as..."),
                     QDir(ui->envir_lineEdit_workDir->text()).absolutePath(),
                     tr("PDB files (*.pdb)"));
  if (!filename.isEmpty())
    ui->envir_lineEdit_output->setText(filename);
}

void MainWindow::on_envir_pushButton_log_clicked()
{
  QString filename = QFileDialog::getSaveFileName(
                     this,
                     tr("Save log file as..."),
                     QDir(ui->envir_lineEdit_workDir->text()).absolutePath(),
                     tr("Log files (*.log)"));
  if (!filename.isEmpty())
    ui->envir_lineEdit_log->setText(filename);
}

void MainWindow::on_radf_pushButton_workDir_clicked()
{
  QString dirname = QFileDialog::getExistingDirectory(
                    this,
                    tr("Select work directory"),
                    QDir::currentPath());
  if (!dirname.isEmpty())
    ui->radf_lineEdit_workDir->setText(dirname);
}

void MainWindow::on_radf_pushButton_input_clicked()
{
  QString filename = QFileDialog::getOpenFileName(
                     this,
                     tr("Select trajectory files"),
                     QDir(ui->radf_lineEdit_workDir->text()).absolutePath(),
                     tr("Trajectory files (*.*[0-9])"));
  if (!filename.isEmpty())
    ui->radf_lineEdit_input->setText(filename.split(QString("."))[0]);
}

void MainWindow::on_radf_pushButton_output_clicked()
{
  QString filename = QFileDialog::getSaveFileName(
                     this,
                     tr("Save output file as..."),
                     QDir(ui->radf_lineEdit_workDir->text()).absolutePath(),
                     tr("Output files (*.dat)"));
  if (!filename.isEmpty())
    ui->radf_lineEdit_output->setText(filename);
}

void MainWindow::on_radf_pushButton_log_clicked()
{
  QString filename = QFileDialog::getSaveFileName(
                     this,
                     tr("Save log file as..."),
                     QDir(ui->radf_lineEdit_workDir->text()).absolutePath(),
                     tr("Log files (*.log)"));
  if (!filename.isEmpty())
    ui->radf_lineEdit_log->setText(filename);
}

void MainWindow::on_pdb_pushButton_workDir_clicked()
{
  QString dirname = QFileDialog::getExistingDirectory(
                    this,
                    tr("Select work directory"),
                    QDir::currentPath());
  if (!dirname.isEmpty())
    ui->pdb_lineEdit_workDir->setText(dirname);
}

void MainWindow::on_pdb_pushButton_input_clicked()
{
  QString filename = QFileDialog::getOpenFileName(
                     this,
                     tr("Select trajectory file"),
                     QDir(ui->pdb_lineEdit_workDir->text()).absolutePath(),
                     tr("Trajectory files (*.*[0-9])"));
  if (!filename.isEmpty())
    ui->pdb_lineEdit_input->setText(filename);
}

void MainWindow::on_pdb_pushButton_agl_clicked()
{
  QString filename = QFileDialog::getOpenFileName(
                     this,
                     tr("Select agglomerate file"),
                     QDir(ui->pdb_lineEdit_workDir->text()).absolutePath(),
                     tr("Agglomerate files (*.agl);;All files (*.*)"));
  if (!filename.isEmpty())
    ui->pdb_lineEdit_agl->setText(filename);
}

void MainWindow::on_pdb_pushButton_output_clicked()
{
  QString filename = QFileDialog::getSaveFileName(
                     this,
                     tr("Save PDB file as..."),
                     QDir(ui->pdb_lineEdit_workDir->text()).absolutePath(),
                     tr("PDB files (*.pdb)"));
  if (!filename.isEmpty())
    ui->pdb_lineEdit_output->setText(filename);
}

void MainWindow::on_pdb_pushButton_log_clicked()
{
  QString filename = QFileDialog::getSaveFileName(
                     this,
                     tr("Save log file as..."),
                     QDir(ui->pdb_lineEdit_workDir->text()).absolutePath(),
                     tr("Log files (*.log)"));
  if (!filename.isEmpty())
    ui->pdb_lineEdit_log->setText(filename);
}

// clear actions
void MainWindow::on_trj_pushButton_clear_clicked()
{
  clear_items->clear_trj();
}

void MainWindow::on_statgen_pushButton_clear_clicked()
{
  clear_items->clear_statgen();
}

void MainWindow::on_envir_pushButton_clear_clicked()
{
  clear_items->clear_envir();
}

void MainWindow::on_radf_pushButton_clear_clicked()
{
  clear_items->clear_radf();
}

void MainWindow::on_pdb_pushButton_clear_clicked()
{
  clear_items->clear_pdb();
}

// set interaction (statgen)
void MainWindow::update_interaction()
{
  int num_inter = 0;

  if (ui->statgen_checkBox_atoms1->checkState() == 2)
    num_inter++;
  if (ui->statgen_checkBox_atoms2->checkState() == 2)
    num_inter++;
  if (ui->statgen_checkBox_atoms3->checkState() == 2)
    num_inter++;

  ui->statgen_comboBox_int->clear();
  ui->statgen_comboBox_int->addItem("0-0");
  if (num_inter >= 1)
  {
    ui->statgen_comboBox_int->addItem("0-1");
    ui->statgen_comboBox_int->addItem("1-1");
  }
  if (num_inter >= 2)
  {
    ui->statgen_comboBox_int->addItem("0-2");
    ui->statgen_comboBox_int->addItem("1-2");
    ui->statgen_comboBox_int->addItem("2-2");
  }
  if (num_inter >= 3)
  {
    ui->statgen_comboBox_int->addItem("0-3");
    ui->statgen_comboBox_int->addItem("1-3");
    ui->statgen_comboBox_int->addItem("2-3");
    ui->statgen_comboBox_int->addItem("3-3");
  }

  for (int i=0; i<10; i++)
    statgen_crit[i] = 0.0;
}

void MainWindow::on_statgen_comboBox_int_currentIndexChanged(int index)
{
  ui->statgen_doubleSpinBox_int->setValue(statgen_crit[index]);
}

void MainWindow::on_stagen_pushButton_intSave_clicked()
{
  int index;
  index = ui->statgen_comboBox_int->currentIndex();
  statgen_crit[index] = ui->statgen_doubleSpinBox_int->value();
}

void MainWindow::on_statgen_doubleSpinBox_int_editingFinished()
{
  int index;
  index = ui->statgen_comboBox_int->currentIndex();
  statgen_crit[index] = ui->statgen_doubleSpinBox_int->value();
}

void MainWindow::on_statgen_pushButton_intAdd_clicked()
{
  QString interaction;
  QString crit;

  int num_inter = ui->statgen_comboBox_int->count();
  for (int i=0; i<num_inter; i++)
  {
    interaction.append(ui->statgen_comboBox_int->itemText(i));
    interaction.append(QString(":"));
    crit.setNum(statgen_crit[i], 'f', 3);
    interaction.append(crit);
    interaction.append(QString(","));
  }
  interaction.remove(interaction.count()-1, 1);
  ui->statgen_listWidget_int->addItem(interaction);
  ui->statgen_doubleSpinBox_int->setValue(0.0);
  for (int i=0; i<10; i++)
    statgen_crit[i] = 0.0;
}

void MainWindow::on_stagen_pushButton_intRem_clicked()
{
  int curIndex = ui->statgen_listWidget_int->currentRow();
  if (curIndex > -1)
    delete ui->statgen_listWidget_int->item(curIndex);
}

// start signals
void MainWindow::on_trj_pushButton_start_clicked()
{
  QString workDir = ui->trj_lineEdit_workDir->text();
  QString input = ui->trj_lineEdit_input->text();
  QString type;
  switch (ui->trj_comboBox_type->currentIndex())
  {
    case 0:
      type = QString("gmx");
      break;
    case 1:
      type = QString("puma");
      break;
  }
  QString steps = QString::number(ui->trj_spinBox_steps->value());
  QString atomType = ui->trj_lineEdit_atoms->text();
  QString mask = ui->trj_lineEdit_output->text();
  QString totalTypes = QString::number(ui->trj_spinBox_totalTypes->value());
  QString log;
  if (ui->trj_checkBox_log->checkState() == 2)
    log = ui->trj_lineEdit_log->text();
  else
    log = QString("#");

  ui->tabWidget->setDisabled(true);
  ui->statusBar->showMessage(QApplication::translate("MainWindow", "Processing 'trj'..."));
  start_events = new Start_events(this);
  bool check = start_events->start_trj(mm_trj_path,
                                       workDir,
                                       input,
                                       type,
                                       steps,
                                       atomType,
                                       mask,
                                       totalTypes,
                                       log);
  delete start_events;
  ui->tabWidget->setEnabled(true);
  ui->statusBar->showMessage(QApplication::translate("MainWindow", "Done"));
}

void MainWindow::on_statgen_pushButton_start_clicked()
{
  QString workDir = ui->statgen_lineEdit_workDir->text();
  QString mask = ui->statgen_lineEdit_input->text();
  QString firstStep = QString::number(ui->statgen_spinBox_stepsFirst->value());
  QString lastStep = QString::number(ui->statgen_spinBox_stepsLast->value());
  QString cellX, cellY, cellZ;
  cellX.setNum(ui->statgen_doubleSpinBox_cellX->value(), 'f', 4);
  cellY.setNum(ui->statgen_doubleSpinBox_cellY->value(), 'f', 4);
  cellZ.setNum(ui->statgen_doubleSpinBox_cellZ->value(), 'f', 4);
  QString atom0 = QString::number(ui->statgen_spinBox_atoms0->value());
  QString atom1, atom2, atom3;
  if (ui->statgen_checkBox_atoms1->checkState() == 2)
    atom1.setNum(ui->statgen_spinBox_atoms1->value());
  else
    atom1 = QString("#");
  if (ui->statgen_checkBox_atoms2->checkState() == 2)
    atom2.setNum(ui->statgen_spinBox_atoms2->value());
  else
    atom2 = QString("#");
  if (ui->statgen_checkBox_atoms3->checkState() == 2)
    atom3.setNum(ui->statgen_spinBox_atoms3->value());
  else
    atom3 = QString("#");
  QString inter;
  inter = QString("");
  for (int i=0; i<ui->statgen_listWidget_int->count(); i++)
    inter.append(" -r " + ui->statgen_listWidget_int->item(i)->text());
  QString output = ui->statgen_lineEdit_output->text();
  QString depth;
  if (ui->statgen_checkBox_depth->checkState() == 2)
    depth.setNum(ui->statgen_spinBox_depth->value());
  else
    depth = QString("#");
  QString log;
  if (ui->statgen_checkBox_log->checkState() == 2)
    log = ui->statgen_lineEdit_log->text();
  else
    log = QString("#");

  ui->statusBar->showMessage(QApplication::translate("MainWindow", "Processing 'statgen'..."));
  ui->tabWidget->setDisabled(true);
  start_events = new Start_events(this);
  bool check = start_events->start_statgen(mm_statgen_path,
                                           workDir,
                                           mask,
                                           firstStep,
                                           lastStep,
                                           cellX, cellY, cellZ,
                                           atom0, atom1, atom2, atom3,
                                           inter,
                                           output,
                                           depth,
                                           log);
  delete start_events;
  ui->tabWidget->setEnabled(true);
  ui->statusBar->showMessage(QApplication::translate("MainWindow", "Done"));

  if ((ui->statgen_checkBox_graph->checkState() == 2) && (check == true))
  {
    QString filename = output;
    if (!filename.contains(QDir::separator()))
      filename = QFileInfo(QDir(workDir), filename).absoluteFilePath();
    StatgenGraphWindow *graphwin;
    graphwin = new StatgenGraphWindow(this, filename);
    graphwin->show();
  }
}

void MainWindow::on_envir_pushButton_start_clicked()
{
  QString workDir = ui->envir_lineEdit_workDir->text();
  QString input = ui->envir_lineEdit_input->text();
  QString cellX, cellY, cellZ;
  cellX.setNum(ui->envir_doubleSpinBox_cellX->value(), 'f', 4);
  cellY.setNum(ui->envir_doubleSpinBox_cellY->value(), 'f', 4);
  cellZ.setNum(ui->envir_doubleSpinBox_cellZ->value(), 'f', 4);
  QString output = ui->envir_lineEdit_output->text();
  QString molecule = QString::number(ui->envir_spinBox_molecule->value());
  QString radius;
  radius.setNum(ui->envir_doubleSpinBox_radius->value(), 'f', 4);
  QString log;
  if (ui->envir_checkBox_log->checkState() == 2)
    log = ui->envir_lineEdit_log->text();
  else
    log = QString("#");

  ui->statusBar->showMessage(QApplication::translate("MainWindow", "Processing 'envir'..."));
  ui->tabWidget->setDisabled(true);
  start_events = new Start_events(this);
  bool check = start_events->start_envir(mm_envir_path,
                                         workDir,
                                         input,
                                         cellX, cellY, cellZ,
                                         output,
                                         molecule,
                                         radius,
                                         log);
  delete start_events;
  ui->tabWidget->setEnabled(true);
  ui->statusBar->showMessage(QApplication::translate("MainWindow", "Done"));
}

void MainWindow::on_radf_pushButton_start_clicked()
{
  QString workDir = ui->radf_lineEdit_workDir->text();
  QString mask = ui->radf_lineEdit_input->text();
  QString firstStep = QString::number(ui->radf_spinBox_stepsFirst->value());
  QString lastStep = QString::number(ui->radf_spinBox_stepsLast->value());
  QString cellX, cellY, cellZ;
  cellX.setNum(ui->radf_doubleSpinBox_cellX->value(), 'f', 4);
  cellY.setNum(ui->radf_doubleSpinBox_cellY->value(), 'f', 4);
  cellZ.setNum(ui->radf_doubleSpinBox_cellZ->value(), 'f', 4);
  QString output = ui->radf_lineEdit_output->text();
  QString atom0 = QString::number(ui->radf_spinBox_atoms0->value());
  QString atom3 = QString::number(ui->radf_spinBox_atoms3->value());
  QString atom1, atom2, atom4, atom5;
  if (ui->radf_comboBox_atom->currentIndex() == 1)
  {
    atom1 = QString::number(ui->radf_spinBox_atoms1->value());
    atom2 = QString::number(ui->radf_spinBox_atoms1->value());
    atom4 = QString::number(ui->radf_spinBox_atoms1->value());
    atom5 = QString::number(ui->radf_spinBox_atoms1->value());
  }
  else
    atom1 = QString("#");
  QString radMin, radMax, radStep, angMin, angMax, angStep;
  radMin.setNum(ui->radf_doubleSpinBox_radMin->value(), 'f', 3);
  radMax.setNum(ui->radf_doubleSpinBox_radMax->value(), 'f', 3);
  radStep.setNum(ui->radf_doubleSpinBox_radStep->value(), 'f', 3);
  if (ui->radf_checkBox_ang->checkState() == 2)
  {
    angMin.setNum(ui->radf_doubleSpinBox_angMin->value(), 'f', 2);
    angMax.setNum(ui->radf_doubleSpinBox_angMax->value(), 'f', 2);
    angStep.setNum(ui->radf_doubleSpinBox_angStep->value(), 'f', 2);
  }
  else
    angStep = QString("#");
  QString log;
  if (ui->radf_checkBox_log->checkState() == 2)
    log = ui->radf_lineEdit_log->text();
  else
    log = QString("#");
  int matrix;
  if (ui->radf_checkBox_matrix->checkState() == 2)
    matrix = 1;
  else
    matrix = 0;

  ui->statusBar->showMessage(QApplication::translate("MainWindow", "Processing 'radf'..."));
  ui->tabWidget->setDisabled(true);
  start_events = new Start_events(this);
  bool check = start_events->start_radf(mm_radf_path,
                                        workDir,
                                        mask,
                                        firstStep,
                                        lastStep,
                                        cellX, cellY, cellZ,
                                        output,
                                        atom0, atom1, atom2,
                                        atom3, atom4, atom5,
                                        radMin, radMax, radStep,
                                        angMin, angMax, angStep,
                                        log, matrix);
  delete start_events;
  ui->tabWidget->setEnabled(true);
  ui->statusBar->showMessage(QApplication::translate("MainWindow", "Done"));

  if ((ui->radf_checkBox_graph->checkState() == 2) && (check == true))
  {
    QString filename = output;
    if (!filename.contains(QDir::separator()))
      filename = QFileInfo(QDir(workDir), filename).absoluteFilePath();
    StatgenGraphWindow *graphwin;
    graphwin = new StatgenGraphWindow(this, filename);
    graphwin->show();
  }
}

void MainWindow::on_pdb_pushButton_start_clicked()
{
  QString workDir = ui->pdb_lineEdit_workDir->text();
  QString input = ui->pdb_lineEdit_input->text();
  QString agl, cellX, cellY, cellZ;
  if (ui->pdb_comboBox_mode->currentIndex() == 0)
  {
    agl = ui->pdb_lineEdit_agl->text();
    cellX.setNum(ui->pdb_doubleSpinBox_cellX->value(), 'f', 4);
    cellY.setNum(ui->pdb_doubleSpinBox_cellY->value(), 'f', 4);
    cellZ.setNum(ui->pdb_doubleSpinBox_cellZ->value(), 'f', 4);
  }
  else
    agl = QString("#");
  QString output = ui->pdb_lineEdit_output->text();
  QString log;
  if (ui->pdb_checkBox_log->checkState() == 2)
    log = ui->pdb_lineEdit_log->text();
  else
    log = QString("#");

  if (ui->pdb_comboBox_mode->currentIndex() == 0)
    ui->statusBar->showMessage(QApplication::translate("MainWindow", "Processing 'agl'..."));
  else if (ui->pdb_comboBox_mode->currentIndex() == 1)
    ui->statusBar->showMessage(QApplication::translate("MainWindow", "Processing 'trj2pdb'..."));
  ui->tabWidget->setDisabled(true);
  start_events = new Start_events(this);
  bool check;
  if (ui->pdb_comboBox_mode->currentIndex() == 0)
    check = start_events->start_pdb(mm_agl_path,
                                    workDir,
                                    input,
                                    agl,
                                    cellX, cellY, cellZ,
                                    output,
                                    log);
  else if (ui->pdb_comboBox_mode->currentIndex() == 1)
    check = start_events->start_pdb(mm_trj2pdb_path,
                                    workDir,
                                    input,
                                    agl,
                                    cellX, cellY, cellZ,
                                    output,
                                    log);
  delete start_events;
  ui->tabWidget->setEnabled(true);
  ui->statusBar->showMessage(QApplication::translate("MainWindow", "Done"));
}

// completion
void MainWindow::on_tabWidget_currentChanged(int index)
{
  switch(index)
  {
    case 1:
      update_fields->setup_def_statgen();
      break;
    case 2:
      update_fields->setup_def_envir();
      break;
    case 3:
      update_fields->setup_def_radf();
      break;
    case 4:
      update_fields->setup_def_pdb();
      break;
  }
}

// window signals
void MainWindow::createActions()
{
  connect(ui->actionAtom_types_file, SIGNAL(triggered()), this, SLOT(createAtomTypes()));
  connect(ui->actionAgglomerate_file, SIGNAL(triggered()), this, SLOT(createAgglFile()));
  connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(aboutWin()));
  connect(ui->actionSettings, SIGNAL(triggered()), this, SLOT(settingsWinShow()));
  connect(ui->actionAgl_all, SIGNAL(triggered()), this, SLOT(aglallWinShow()));
}

void MainWindow::createAtomTypes()
{
  AtomTypesWindow *atomTypes;
  atomTypes = new AtomTypesWindow(this);
  atomTypes->show();
}

void MainWindow::createAgglFile()
{
  AgglWindow *agglWindow;
  agglWindow = new AgglWindow(this, ui->statgen_lineEdit_output->text());
  agglWindow->show();
}

void MainWindow::aboutWin()
{
  AboutWindow *aboutWindow;
  aboutWindow = new AboutWindow(this);
  aboutWindow->show();
}

void MainWindow::settingsWinShow()
{
  SettingsWindow *settingsWindow;
  settingsWindow = new SettingsWindow(this);
  settingsWindow->show();
}

void MainWindow::aglallWinShow()
{
  AglAllWindow *aglallWin;
  aglallWin = new AglAllWindow(this, mm_agl_path);
  aglallWin->show();
}
