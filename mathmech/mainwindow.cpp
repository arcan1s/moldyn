#include <QFileDialog>
#include <QDir>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clear_items.h"
#include "start_events.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  clear_items(new Clear_items(this)),
  start_events(new Start_events(this))
{
  ui->setupUi(this);
  statgen_crit = new float[10];

  ui->statusBar->showMessage(QString("Ready"));

// TODO: read config
//  language = QString("eng");
  mm_agl_path = QString("/home/arcanis/Documents/github/moldyn/mathmech/bin/mm_agl");
  mm_envir_path = QString("/home/arcanis/Documents/github/moldyn/mathmech/bin/mm_envir");
  mm_radf_path = QString("/home/arcanis/Documents/github/moldyn/mathmech/bin/mm_radf");
  mm_statgen_path = QString("/home/arcanis/Documents/github/moldyn/mathmech/bin/mm_statgen");
  mm_trj_path = QString("/home/arcanis/Documents/github/moldyn/mathmech/bin/mm_trj");
  mm_trj2pdb_path = QString("/home/arcanis/Documents/github/moldyn/bin/mm_trj2pdb");
}

MainWindow::~MainWindow()
{
  delete ui;
  delete clear_items;
  delete start_events;
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
    ui->trj_lineEdit_log->clear();
  }
}

void MainWindow::on_statgen_checkBox_depth_stateChanged(int arg1)
{
  if (arg1 == 0)
    ui->statgen_spinBox_depth->setDisabled(true);
  else if (arg1 == 2)
  {
    ui->statgen_spinBox_depth->setEnabled(true);
    ui->statgen_spinBox_depth->setValue(10);
  }
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
    ui->statgen_lineEdit_log->clear();
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
    ui->statgen_spinBox_atoms1->setValue(0);
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
    ui->statgen_spinBox_atoms2->setValue(0);
    ui->statgen_checkBox_atoms3->setEnabled(true);
  }
  update_interaction();
}

void MainWindow::on_statgen_checkBox_atoms3_stateChanged(int arg1)
{
  if (arg1 == 0)
    ui->statgen_spinBox_atoms3->setDisabled(true);
  else if (arg1 == 2)
  {
    ui->statgen_spinBox_atoms3->setEnabled(true);
    ui->statgen_spinBox_atoms3->setValue(0);
  }
  update_interaction();
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
    ui->envir_lineEdit_log->clear();
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
    ui->radf_spinBox_atoms1->setValue(0);
    ui->radf_spinBox_atoms2->setValue(0);
    ui->radf_spinBox_atoms4->setValue(0);
    ui->radf_spinBox_atoms5->setValue(0);
  }
}

void MainWindow::on_radf_checkBox_ang_stateChanged(int arg1)
{
  if (arg1 == 0)
  {
    ui->radf_doubleSpinBox_angMax->setDisabled(true);
    ui->radf_doubleSpinBox_angMin->setDisabled(true);
    ui->radf_doubleSpinBox_angStep->setDisabled(true);
  }
  else if (arg1 == 2)
  {
    ui->radf_doubleSpinBox_angMax->setEnabled(true);
    ui->radf_doubleSpinBox_angMin->setEnabled(true);
    ui->radf_doubleSpinBox_angStep->setEnabled(true);
    ui->radf_doubleSpinBox_angMax->setValue(90.0);
    ui->radf_doubleSpinBox_angMin->setValue(0.0);
    ui->radf_doubleSpinBox_angStep->setValue(15.0);
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
    ui->radf_lineEdit_log->clear();
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
    ui->pdb_lineEdit_agl->clear();
    ui->pdb_doubleSpinBox_cellX->setValue(0.1);
    ui->pdb_doubleSpinBox_cellY->setValue(0.1);
    ui->pdb_doubleSpinBox_cellZ->setValue(0.1);
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
    ui->pdb_lineEdit_log->clear();
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

void MainWindow::on_radf_pushButton_output_clicked()
{
  QString filename = QFileDialog::getSaveFileName(
                     this,
                     tr("Save output file as..."),
                     QDir(ui->radf_lineEdit_workDir->text()).absolutePath(),
                     tr("Output files (*.dat)"));
  if (!filename.isEmpty())
    ui->envir_lineEdit_output->setText(filename);
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
                     tr("Agglomerate files (*.agl]);;All files (*.*)"));
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
  if (int curIndex = ui->statgen_listWidget_int->currentRow() > -1)
    delete ui->statgen_listWidget_int->item(curIndex-1);
}

// start signals
void MainWindow::on_trj_pushButton_start_clicked()
{
  start_events->start_trj(mm_trj_path);
}

void MainWindow::on_statgen_pushButton_start_clicked()
{
  start_events->start_statgen(mm_statgen_path);
}

void MainWindow::on_envir_pushButton_start_clicked()
{
  start_events->stat_envir(mm_envir_path);
}

void MainWindow::on_radf_pushButton_start_clicked()
{
  start_events->stat_radf(mm_radf_path);
}
