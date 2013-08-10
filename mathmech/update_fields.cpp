#include <QDir>
#include <math.h>

#include "update_fields.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

Update_fields::Update_fields(MainWindow *wid) :
  parent(wid)
{

}

void Update_fields::setup_def_statgen()
{
// set work directory
  parent->ui->statgen_lineEdit_workDir->setText(parent->ui->trj_lineEdit_workDir->text());
// set mask
  parent->ui->statgen_lineEdit_input->setText(parent->ui->trj_lineEdit_output->text());
// set steps
  parent->ui->statgen_spinBox_stepsLast->setValue(parent->ui->trj_spinBox_steps->value());
// set cell size
  float cellX, cellY, cellZ;
  QStringList tmp_str;
  QString input = parent->ui->trj_lineEdit_input->text();
  if (input.contains(QDir::separator()))
    input = QFileInfo(input).absoluteFilePath();
  else
    input = QFileInfo(QDir(parent->ui->trj_lineEdit_workDir->text()), input).absoluteFilePath();
  QFile inp_trj(input);
  bool exists = inp_trj.open(QIODevice::ReadOnly);
  if (!exists)
    return;
  if (parent->ui->trj_comboBox_type->currentIndex() == 0)
  {
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    if (tmp_str[1] != QString("frame"))
      return;
    for (int i=0; i<2; i++)
      inp_trj.readLine();
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    cellX = 10 * tmp_str[2].remove(tmp_str[2].count()-1, 1).toFloat();
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    cellY = 10 * tmp_str[3].remove(tmp_str[3].count()-1, 1).toFloat();
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    cellZ = 10 * tmp_str[4].remove(tmp_str[4].count()-2, 1).toFloat();
  }
  else if (parent->ui->trj_comboBox_type->currentIndex() == 1)
  {
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    bool ok = false;
    cellX = tmp_str[0].toInt(&ok, 10);
    if (!ok)
      return;
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    cellX = tmp_str[0].toFloat();
    cellY = tmp_str[1].toFloat();
    cellZ = tmp_str[2].toFloat();
  }
  else
    return;
  inp_trj.close();
  parent->ui->statgen_doubleSpinBox_cellX->setValue(cellX);
  parent->ui->statgen_doubleSpinBox_cellY->setValue(cellY);
  parent->ui->statgen_doubleSpinBox_cellZ->setValue(cellZ);
}

void Update_fields::setup_def_envir()
{
// set work directory
  parent->ui->envir_lineEdit_workDir->setText(parent->ui->trj_lineEdit_workDir->text());
// set cell size
  float cellX, cellY, cellZ;
  QStringList tmp_str;
  QString input = parent->ui->trj_lineEdit_input->text();
  if (input.contains(QDir::separator()))
    input = QFileInfo(input).absoluteFilePath();
  else
    input = QFileInfo(QDir(parent->ui->trj_lineEdit_workDir->text()), input).absoluteFilePath();
  QFile inp_trj(input);
  bool exists = inp_trj.open(QIODevice::ReadOnly);
  if (!exists)
    return;
  if (parent->ui->trj_comboBox_type->currentIndex() == 0)
  {
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    if (tmp_str[1] != QString("frame"))
      return;
    for (int i=0; i<2; i++)
      inp_trj.readLine();
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    cellX = 10 * tmp_str[2].remove(tmp_str[2].count()-1, 1).toFloat();
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    cellY = 10 * tmp_str[3].remove(tmp_str[3].count()-1, 1).toFloat();
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    cellZ = 10 * tmp_str[4].remove(tmp_str[4].count()-2, 1).toFloat();
  }
  else if (parent->ui->trj_comboBox_type->currentIndex() == 1)
  {
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    bool ok = false;
    cellX = tmp_str[0].toInt(&ok, 10);
    if (!ok)
      return;
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    cellX = tmp_str[0].toFloat();
    cellY = tmp_str[1].toFloat();
    cellZ = tmp_str[2].toFloat();
  }
  else
    return;
  inp_trj.close();
  parent->ui->envir_doubleSpinBox_cellX->setValue(cellX);
  parent->ui->envir_doubleSpinBox_cellY->setValue(cellY);
  parent->ui->envir_doubleSpinBox_cellZ->setValue(cellZ);
}

void Update_fields::setup_def_radf()
{
// set work directory
  parent->ui->radf_lineEdit_workDir->setText(parent->ui->trj_lineEdit_workDir->text());
// set mask
  parent->ui->radf_lineEdit_input->setText(parent->ui->trj_lineEdit_output->text());
// set steps
  parent->ui->radf_spinBox_stepsLast->setValue(parent->ui->trj_spinBox_steps->value());
// set cell size
  float cellX, cellY, cellZ;
  QStringList tmp_str;
  QString input = parent->ui->trj_lineEdit_input->text();
  if (input.contains(QDir::separator()))
    input = QFileInfo(input).absoluteFilePath();
  else
    input = QFileInfo(QDir(parent->ui->trj_lineEdit_workDir->text()), input).absoluteFilePath();
  QFile inp_trj(input);
  bool exists = inp_trj.open(QIODevice::ReadOnly);
  if (!exists)
    return;
  if (parent->ui->trj_comboBox_type->currentIndex() == 0)
  {
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    if (tmp_str[1] != QString("frame"))
      return;
    for (int i=0; i<2; i++)
      inp_trj.readLine();
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    cellX = 10 * tmp_str[2].remove(tmp_str[2].count()-1, 1).toFloat();
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    cellY = 10 * tmp_str[3].remove(tmp_str[3].count()-1, 1).toFloat();
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    cellZ = 10 * tmp_str[4].remove(tmp_str[4].count()-2, 1).toFloat();
  }
  else if (parent->ui->trj_comboBox_type->currentIndex() == 1)
  {
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    bool ok = false;
    cellX = tmp_str[0].toInt(&ok, 10);
    if (!ok)
      return;
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    cellX = tmp_str[0].toFloat();
    cellY = tmp_str[1].toFloat();
    cellZ = tmp_str[2].toFloat();
  }
  else
    return;
  inp_trj.close();
  parent->ui->radf_doubleSpinBox_cellX->setValue(cellX);
  parent->ui->radf_doubleSpinBox_cellY->setValue(cellY);
  parent->ui->radf_doubleSpinBox_cellZ->setValue(cellZ);
}

void Update_fields::setup_def_pdb()
{
// set work directory
  parent->ui->pdb_lineEdit_workDir->setText(parent->ui->trj_lineEdit_workDir->text());
// set cell size
  float cellX, cellY, cellZ;
  QStringList tmp_str;
  QString input = parent->ui->trj_lineEdit_input->text();
  if (input.contains(QDir::separator()))
    input = QFileInfo(input).absoluteFilePath();
  else
    input = QFileInfo(QDir(parent->ui->trj_lineEdit_workDir->text()), input).absoluteFilePath();
  QFile inp_trj(input);
  bool exists = inp_trj.open(QIODevice::ReadOnly);
  if (!exists)
    return;
  if (parent->ui->trj_comboBox_type->currentIndex() == 0)
  {
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    if (tmp_str[1] != QString("frame"))
      return;
    for (int i=0; i<2; i++)
      inp_trj.readLine();
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    cellX = 10 * tmp_str[2].remove(tmp_str[2].count()-1, 1).toFloat();
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    cellY = 10 * tmp_str[3].remove(tmp_str[3].count()-1, 1).toFloat();
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    cellZ = 10 * tmp_str[4].remove(tmp_str[4].count()-2, 1).toFloat();
  }
  else if (parent->ui->trj_comboBox_type->currentIndex() == 1)
  {
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    bool ok = false;
    cellX = tmp_str[0].toInt(&ok, 10);
    if (!ok)
      return;
    tmp_str = QString(inp_trj.readLine()).split(' ', QString::SkipEmptyParts);
    cellX = tmp_str[0].toFloat();
    cellY = tmp_str[1].toFloat();
    cellZ = tmp_str[2].toFloat();
  }
  else
    return;
  inp_trj.close();
  parent->ui->pdb_doubleSpinBox_cellX->setValue(cellX);
  parent->ui->pdb_doubleSpinBox_cellY->setValue(cellY);
  parent->ui->pdb_doubleSpinBox_cellZ->setValue(cellZ);
}
