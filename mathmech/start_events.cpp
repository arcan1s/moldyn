#include <QDir>

#include "start_events.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "errorwindow.h"
#include "ui_errorwindow.h"

Start_events::Start_events(MainWindow *wid) :
  parent(wid)
{

}

void Start_events::start_trj(QString mm_trj_path)
{
  errorwin = new ErrorWindow(parent);
  parent->ui->statusBar->showMessage(QApplication::translate("Start_events", "Processing 'trj'..."));
  parent->ui->statusBar->showMessage(QApplication::translate("Start_events", "Processing 'trj'..."));

// read variables
  QString workDir = parent->ui->trj_lineEdit_workDir->text();
  QString input = parent->ui->trj_lineEdit_input->text();
  QString type;
  switch (parent->ui->trj_comboBox_type->currentIndex())
  {
    case 0:
      type = QString("gmx");
      break;
    case 1:
      type = QString("puma");
      break;
  }
  QString steps = QString::number(parent->ui->trj_spinBox_steps->value());
  QString atomType = parent->ui->trj_lineEdit_atoms->text();
  QString mask = parent->ui->trj_lineEdit_output->text();
  QString totalTypes = QString::number(parent->ui->trj_spinBox_totalTypes->value());
  QString log;
  if (parent->ui->trj_checkBox_log->checkState() == 2)
    log = parent->ui->trj_lineEdit_log->text();

// error check
  if ((workDir == "") || (!QDir(workDir).exists()))
  {
    errorwin->set_message(0);
    errorwin->show();
    return;
  }
  if ((input == "") || (!QFile(input).exists()))
  {
    errorwin->set_message(1);
    errorwin->show();
    return;
  }
  if ((atomType == "") || (!QFile(atomType).exists()))
  {
    errorwin->set_message(3);
    errorwin->show();
    return;
  }
  if (mask == "")
  {
    errorwin->set_message(4);
    errorwin->show();
    return;
  }
  if ((parent->ui->trj_checkBox_log->checkState() == 2) && (log == ""))
  {
    errorwin->set_message(6);
    errorwin->show();
    return;
  }
  if (!QFile(mm_trj_path).exists())
  {
    errorwin->set_message(7);
    errorwin->show();
    return;
  }

// exec
  parent->ui->tabWidget->setDisabled(true);
  QString command;
  command.append(mm_trj_path);
  if (input.contains(QDir::separator()))
    command.append(" -i " + QFileInfo(input).absoluteFilePath());
  else
    command.append(" -i " + QFileInfo(QDir(workDir), input).absoluteFilePath());
  command.append(" -t " + type);
  command.append(" -s " + steps);
  if (atomType.contains(QDir::separator()))
    command.append(" -a " + QFileInfo(atomType).absoluteFilePath());
  else
    command.append(" -a " + QFileInfo(QDir(workDir), atomType).absoluteFilePath());
  command.append(" -o " + QFileInfo(QDir(workDir), mask).absoluteFilePath());
  command.append(" -tt " + totalTypes);
  if (parent->ui->trj_checkBox_log->checkState() == 2)
  {
    if (log.contains(QDir::separator()))
      command.append(" -l " + QFileInfo(log).absoluteFilePath());
    else
      command.append(" -l " + QFileInfo(QDir(workDir), log).absoluteFilePath());
  }
  command.append(" -q");

  system(command.toStdString().c_str());
  parent->ui->tabWidget->setEnabled(true);
  parent->ui->statusBar->showMessage(QApplication::translate("Start_events", "Done"));
  delete errorwin;
}

void Start_events::start_statgen(QString mm_statgen_path)
{
  errorwin = new ErrorWindow(parent);
  parent->ui->statusBar->showMessage(QApplication::translate("Start_events", "Processing 'statgen'..."));
  parent->ui->statusBar->showMessage(QApplication::translate("Start_events", "Processing 'statgen'..."));

// read variables
  QString workDir = parent->ui->statgen_lineEdit_workDir->text();
  QString mask = parent->ui->statgen_lineEdit_input->text();
  QString firstStep = QString::number(parent->ui->statgen_spinBox_stepsFirst->value());
  QString lastStep = QString::number(parent->ui->statgen_spinBox_stepsLast->value());
  QString cellX, cellY, cellZ;
  cellX.setNum(parent->ui->statgen_doubleSpinBox_cellX->value(), 'f', 4);
  cellY.setNum(parent->ui->statgen_doubleSpinBox_cellY->value(), 'f', 4);
  cellZ.setNum(parent->ui->statgen_doubleSpinBox_cellZ->value(), 'f', 4);
  QString atom0 = QString::number(parent->ui->statgen_spinBox_atoms0->value());
  QString atom1, atom2, atom3;
  if (parent->ui->statgen_checkBox_atoms1->checkState() == 2)
    atom1.setNum(parent->ui->statgen_spinBox_atoms1->value());
  if (parent->ui->statgen_checkBox_atoms2->checkState() == 2)
    atom2.setNum(parent->ui->statgen_spinBox_atoms2->value());
  if (parent->ui->statgen_checkBox_atoms3->checkState() == 2)
    atom3.setNum(parent->ui->statgen_spinBox_atoms3->value());
  QString inter;
  for (int i=0; i<parent->ui->statgen_listWidget_int->count(); i++)
    inter.append(" -r " + parent->ui->statgen_listWidget_int->item(i)->text());
  QString output = parent->ui->statgen_lineEdit_output->text();
  QString depth;
  if (parent->ui->statgen_checkBox_depth->checkState() == 2)
    depth.setNum(parent->ui->statgen_spinBox_depth->value());
  QString log;
  if (parent->ui->statgen_checkBox_log->checkState() == 2)
    log = parent->ui->statgen_lineEdit_log->text();

// error check
  if ((workDir == "") || (!QDir(workDir).exists()))
  {
    errorwin->set_message(0);
    errorwin->show();
    return;
  }
  if (mask == "")
  {
    errorwin->set_message(1);
    errorwin->show();
    return;
  }
  if (parent->ui->statgen_listWidget_int->count() == 0)
  {
    errorwin->set_message(10);
    errorwin->show();
    return;
  }
  if (output == "")
  {
    errorwin->set_message(4);
    errorwin->show();
    return;
  }
  if ((parent->ui->statgen_checkBox_log->checkState() == 2) && (log == ""))
  {
    errorwin->set_message(6);
    errorwin->show();
    return;
  }
  if (!QFile(mm_statgen_path).exists())
  {
    errorwin->set_message(7);
    errorwin->show();
    return;
  }

// exec
  parent->ui->tabWidget->setDisabled(true);
  QString command;
  command.append(mm_statgen_path);
  if (mask.contains(QDir::separator()))
    command.append(" -i " + QFileInfo(mask).absoluteFilePath());
  else
    command.append(" -i " + QFileInfo(QDir(workDir), mask).absoluteFilePath());
  command.append(" -s " + firstStep + "," + lastStep);
  command.append(" -c " + cellX + "," + cellY + "," + cellZ);
  command.append(" -a " + atom0);
  if (parent->ui->statgen_checkBox_atoms1->checkState() == 2)
    command.append("," + atom1);
  if (parent->ui->statgen_checkBox_atoms2->checkState() == 2)
    command.append("," + atom2);
  if (parent->ui->statgen_checkBox_atoms3->checkState() == 2)
    command.append("," + atom3);
  command.append(inter);
  if (output.contains(QDir::separator()))
    command.append(" -o " + QFileInfo(output).absoluteFilePath());
  else
    command.append(" -o " + QFileInfo(QDir(workDir), output).absoluteFilePath());
  if (parent->ui->statgen_checkBox_depth->checkState() == 2)
    command.append(" -g " + depth);
  if (parent->ui->statgen_checkBox_log->checkState() == 2)
  {
    if (log.contains(QDir::separator()))
      command.append(" -l " + QFileInfo(log).absoluteFilePath());
    else
      command.append(" -l " + QFileInfo(QDir(workDir), log).absoluteFilePath());
  }
  command.append(" -q");

  system(command.toStdString().c_str());
  parent->ui->tabWidget->setEnabled(true);
  parent->ui->statusBar->showMessage(QApplication::translate("Start_events", "Done"));
  delete errorwin;
}

void Start_events::start_envir(QString mm_envir_path)
{
  errorwin = new ErrorWindow(parent);
  parent->ui->statusBar->showMessage(QApplication::translate("Start_events", "Processing 'envir'..."));
  parent->ui->statusBar->showMessage(QApplication::translate("Start_events", "Processing 'envir'..."));

// read variables
  QString workDir = parent->ui->envir_lineEdit_workDir->text();
  QString input = parent->ui->envir_lineEdit_input->text();
  QString cellX, cellY, cellZ;
  cellX.setNum(parent->ui->envir_doubleSpinBox_cellX->value(), 'f', 4);
  cellY.setNum(parent->ui->envir_doubleSpinBox_cellY->value(), 'f', 4);
  cellZ.setNum(parent->ui->envir_doubleSpinBox_cellZ->value(), 'f', 4);
  QString output = parent->ui->envir_lineEdit_output->text();
  QString molecule = QString::number(parent->ui->envir_spinBox_molecule->value());
  QString radius;
  radius.setNum(parent->ui->envir_doubleSpinBox_radius->value(), 'f', 4);
  QString log;
  if (parent->ui->envir_checkBox_log->checkState() == 2)
    log = parent->ui->envir_lineEdit_log->text();

// error check
  if ((workDir == "") || (!QDir(workDir).exists()))
  {
    errorwin->set_message(0);
    errorwin->show();
    return;
  }
  if (input == "")
  {
    errorwin->set_message(1);
    errorwin->show();
    return;
  }
  if (output == "")
  {
    errorwin->set_message(4);
    errorwin->show();
    return;
  }
  if ((parent->ui->envir_checkBox_log->checkState() == 2) && (log == ""))
  {
    errorwin->set_message(6);
    errorwin->show();
    return;
  }
  if (!QFile(mm_envir_path).exists())
  {
    errorwin->set_message(7);
    errorwin->show();
    return;
  }

  parent->ui->tabWidget->setDisabled(true);
  QString command;
  command.append(mm_envir_path);
  if (input.contains(QDir::separator()))
    command.append(" -i " + QFileInfo(input).absoluteFilePath());
  else
    command.append(" -i " + QFileInfo(QDir(workDir), input).absoluteFilePath());
  command.append(" -c " + cellX + "," + cellY + "," + cellZ);
  if (output.contains(QDir::separator()))
    command.append(" -o " + QFileInfo(output).absoluteFilePath());
  else
    command.append(" -o " + QFileInfo(QDir(workDir), output).absoluteFilePath());
  command.append(" -n " + molecule);
  command.append(" -r " + radius);
  if (parent->ui->statgen_checkBox_log->checkState() == 2)
  {
    if (log.contains(QDir::separator()))
      command.append(" -l " + QFileInfo(log).absoluteFilePath());
    else
      command.append(" -l " + QFileInfo(QDir(workDir), log).absoluteFilePath());
  }
  command.append(" -q");

  system(command.toStdString().c_str());
  parent->ui->tabWidget->setEnabled(true);
  parent->ui->statusBar->showMessage(QApplication::translate("Start_events", "Done"));
  delete errorwin;
}

void Start_events::start_radf(QString mm_radf_path)
{
  errorwin = new ErrorWindow(parent);
  parent->ui->statusBar->showMessage(QApplication::translate("Start_events", "Processing 'radf'..."));
  parent->ui->statusBar->showMessage(QApplication::translate("Start_events", "Processing 'radf'..."));

// read variables
  QString workDir = parent->ui->radf_lineEdit_workDir->text();
  QString mask = parent->ui->radf_lineEdit_input->text();
  QString firstStep = QString::number(parent->ui->radf_spinBox_stepsFirst->value());
  QString lastStep = QString::number(parent->ui->radf_spinBox_stepsLast->value());
  QString cellX, cellY, cellZ;
  cellX.setNum(parent->ui->radf_doubleSpinBox_cellX->value(), 'f', 4);
  cellY.setNum(parent->ui->radf_doubleSpinBox_cellY->value(), 'f', 4);
  cellZ.setNum(parent->ui->radf_doubleSpinBox_cellZ->value(), 'f', 4);
  QString output = parent->ui->radf_lineEdit_output->text();
  QString atom0 = QString::number(parent->ui->radf_spinBox_atoms0->value());
  QString atom3 = QString::number(parent->ui->radf_spinBox_atoms3->value());
  QString atom1, atom2, atom4, atom5;
  if (parent->ui->radf_comboBox_atom->currentIndex() == 1)
  {
    atom1 = QString::number(parent->ui->radf_spinBox_atoms1->value());
    atom2 = QString::number(parent->ui->radf_spinBox_atoms1->value());
    atom4 = QString::number(parent->ui->radf_spinBox_atoms1->value());
    atom5 = QString::number(parent->ui->radf_spinBox_atoms1->value());
  }
  QString radMin, radMax, radStep, angMin, angMax, angStep;
  radMin.setNum(parent->ui->radf_doubleSpinBox_radMin->value(), 'f', 3);
  radMax.setNum(parent->ui->radf_doubleSpinBox_radMax->value(), 'f', 3);
  radStep.setNum(parent->ui->radf_doubleSpinBox_radStep->value(), 'f', 3);
  if (parent->ui->radf_checkBox_ang->checkState() == 2)
  {
    angMin.setNum(parent->ui->radf_doubleSpinBox_angMin->value(), 'f', 2);
    angMax.setNum(parent->ui->radf_doubleSpinBox_angMax->value(), 'f', 2);
    angStep.setNum(parent->ui->radf_doubleSpinBox_angStep->value(), 'f', 2);
  }
  QString log;
  if (parent->ui->radf_checkBox_log->checkState() == 2)
    log = parent->ui->radf_lineEdit_log->text();

// error check
  if ((workDir == "") || (!QDir(workDir).exists()))
  {
    errorwin->set_message(0);
    errorwin->show();
    return;
  }
  if (mask == "")
  {
    errorwin->set_message(1);
    errorwin->show();
    return;
  }
  if (output == "")
  {
    errorwin->set_message(4);
    errorwin->show();
    return;
  }
  if (parent->ui->radf_comboBox_atom->currentIndex() == 1)
    if ((atom0 == atom1) || (atom0 == atom2) || (atom1 == atom2) ||
        (atom3 == atom4) || (atom3 == atom5) || (atom4 == atom5))
    {
      errorwin->set_message(2);
      errorwin->show();
      return;
    }
  if ((parent->ui->radf_checkBox_log->checkState() == 2) && (log == ""))
  {
    errorwin->set_message(6);
    errorwin->show();
    return;
  }
  if (!QFile(mm_radf_path).exists())
  {
    errorwin->set_message(7);
    errorwin->show();
    return;
  }

// exec
  parent->ui->tabWidget->setDisabled(true);
  QString command;
  command.append(mm_radf_path);
  if (mask.contains(QDir::separator()))
    command.append(" -i " + QFileInfo(mask).absoluteFilePath());
  else
    command.append(" -i " + QFileInfo(QDir(workDir), mask).absoluteFilePath());
  command.append(" -s " + firstStep + "," + lastStep);
  command.append(" -c " + cellX + "," + cellY + "," + cellZ);
  if (parent->ui->radf_comboBox_atom->currentIndex() == 0)
    command.append(" -at " + atom0 + "-" + atom3);
  else if (parent->ui->radf_comboBox_atom->currentIndex() == 1)
    command.append(" -at " + atom0 + "," + atom1 + "," + atom2 +
                   "-" + atom3 + "," + atom4 + "," + atom5);
  if (output.contains(QDir::separator()))
    command.append(" -o " + QFileInfo(output).absoluteFilePath());
  else
    command.append(" -o " + QFileInfo(QDir(workDir), output).absoluteFilePath());
  command.append(" -r " + radMin + "," + radMax);
  command.append(" -rs " + radStep);
  if (parent->ui->radf_checkBox_ang->checkState() == 2)
  {
    command.append(" -a " + angMin + "," + angMax);
    command.append(" -as " + angStep);
  }
  if (parent->ui->radf_checkBox_matrix->checkState() == 2)
    command.append(" -m ");
  if (parent->ui->radf_checkBox_log->checkState() == 2)
  {
    if (log.contains(QDir::separator()))
      command.append(" -l " + QFileInfo(log).absoluteFilePath());
    else
      command.append(" -l " + QFileInfo(QDir(workDir), log).absoluteFilePath());
  }
  command.append(" -q");

  system(command.toStdString().c_str());
  parent->ui->tabWidget->setEnabled(true);
  parent->ui->statusBar->showMessage(QApplication::translate("Start_events", "Done"));
  delete errorwin;
}

void Start_events::start_pdb(QString mm_pdb_path)
{
  errorwin = new ErrorWindow(parent);
  if (parent->ui->pdb_comboBox_mode->currentIndex() == 0)
  {
    parent->ui->statusBar->showMessage(QApplication::translate("Start_events", "Processing 'agl'..."));
    parent->ui->statusBar->showMessage(QApplication::translate("Start_events", "Processing 'agl'..."));
  }
  else if (parent->ui->pdb_comboBox_mode->currentIndex() == 1)
  {
    parent->ui->statusBar->showMessage(QApplication::translate("Start_events", "Processing 'trj2pdb'..."));
    parent->ui->statusBar->showMessage(QApplication::translate("Start_events", "Processing 'trj2pdb'..."));
  }

// read variables
  QString workDir = parent->ui->pdb_lineEdit_workDir->text();
  QString input = parent->ui->pdb_lineEdit_input->text();
  QString agl, cellX, cellY, cellZ;
  if (parent->ui->pdb_comboBox_mode->currentIndex() == 0)
  {
    agl = parent->ui->pdb_lineEdit_agl->text();
    cellX.setNum(parent->ui->pdb_doubleSpinBox_cellX->value(), 'f', 4);
    cellY.setNum(parent->ui->pdb_doubleSpinBox_cellY->value(), 'f', 4);
    cellZ.setNum(parent->ui->pdb_doubleSpinBox_cellZ->value(), 'f', 4);
  }
  QString output = parent->ui->pdb_lineEdit_output->text();
  QString log;
  if (parent->ui->pdb_checkBox_log->checkState() == 2)
    log = parent->ui->pdb_lineEdit_log->text();

// error check
  if ((workDir == "") || (!QDir(workDir).exists()))
  {
    errorwin->set_message(0);
    errorwin->show();
    return;
  }
  if (input == "")
  {
    errorwin->set_message(1);
    errorwin->show();
    return;
  }
  if ((parent->ui->pdb_comboBox_mode->currentIndex() == 0) && (agl == ""))
  {
    errorwin->set_message(1);
    errorwin->show();
    return;
  }
  if (output == "")
  {
    errorwin->set_message(4);
    errorwin->show();
    return;
  }
  if ((parent->ui->pdb_checkBox_log->checkState() == 2) && (log == ""))
  {
    errorwin->set_message(6);
    errorwin->show();
    return;
  }
  if (!QFile(mm_pdb_path).exists())
  {
    errorwin->set_message(7);
    errorwin->show();
    return;
  }

// exec
  parent->ui->tabWidget->setDisabled(true);
  QString command;
  command.append(mm_pdb_path);
  if (parent->ui->pdb_comboBox_mode->currentIndex() == 0)
  {
    if (agl.contains(QDir::separator()))
      command.append(" -a " + QFileInfo(agl).absoluteFilePath());
    else
      command.append(" -a " + QFileInfo(QDir(workDir), agl).absoluteFilePath());
  }
  if (input.contains(QDir::separator()))
    command.append(" -i " + QFileInfo(input).absoluteFilePath());
  else
    command.append(" -i " + QFileInfo(QDir(workDir), input).absoluteFilePath());
  if (parent->ui->pdb_comboBox_mode->currentIndex() == 0)
    command.append(" -c " + cellX + "," + cellY + "," + cellZ);
  if (output.contains(QDir::separator()))
    command.append(" -o " + QFileInfo(output).absoluteFilePath());
  else
    command.append(" -o " + QFileInfo(QDir(workDir), output).absoluteFilePath());
  if (parent->ui->statgen_checkBox_log->checkState() == 2)
  {
    if (log.contains(QDir::separator()))
      command.append(" -l " + QFileInfo(log).absoluteFilePath());
    else
      command.append(" -l " + QFileInfo(QDir(workDir), log).absoluteFilePath());
  }
  command.append(" -q");

//  system(command.toStdString().c_str());
  printf ("%s\n", command.toStdString().c_str());
  parent->ui->tabWidget->setEnabled(true);
  parent->ui->statusBar->showMessage(QApplication::translate("Start_events", "Done"));
  delete errorwin;
}
