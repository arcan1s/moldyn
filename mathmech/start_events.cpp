#include <QDir>

#include "start_events.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "errorwindow.h"
#include "ui_errorwindow.h"

#include <stdio.h>
#include <unistd.h>

Start_events::Start_events(MainWindow *wid) :
  parent(wid)
{

}

void Start_events::start_trj(QString mm_trj_path)
{
  errorwin = new ErrorWindow(parent);
  parent->ui->statusBar->showMessage(QApplication::translate("MainWindow", "Processing 'trj'..."));
  parent->ui->statusBar->showMessage(QApplication::translate("MainWindow", "Processing 'trj'..."));

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
    errorwin->set_message(parent->language, 0);
    errorwin->show();
    return;
  }
  if ((input == "") || (!QFile(input).exists()))
  {
    errorwin->set_message(parent->language, 1);
    errorwin->show();
    return;
  }
  if (steps == "")
  {
    errorwin->set_message(parent->language, 2);
    errorwin->show();
    return;
  }
  if ((atomType == "") || (!QFile(atomType).exists()))
  {
    errorwin->set_message(parent->language, 3);
    errorwin->show();
    return;
  }
  if (mask == "")
  {
    errorwin->set_message(parent->language, 4);
    errorwin->show();
    return;
  }
  if (totalTypes == "")
  {
    errorwin->set_message(parent->language, 5);
    errorwin->show();
    return;
  }
  if ((parent->ui->trj_checkBox_log->checkState() == 2) && (log == ""))
  {
    errorwin->set_message(parent->language, 6);
    errorwin->show();
    return;
  }
  if (!QFile(mm_trj_path).exists())
  {
    errorwin->set_message(parent->language, 7);
    errorwin->show();
    return;
  }

// exec
  parent->ui->tabWidget->setDisabled(true);
  QString command;
  command.append(mm_trj_path);
#ifdef _WIN32
  if (input.contains("\\"))
#elif __linux
  if (input.contains("/"))
#else
  return;
#endif
    command.append(" -i " + QFileInfo(input).absoluteFilePath());
  else
    command.append(" -i " + QFileInfo(QDir(workDir), input).absoluteFilePath());
  command.append(" -t " + type);
  command.append(" -s " + steps);
#ifdef _WIN32
  if (atomType.contains("\\"))
#elif __linux
  if (atomType.contains("/"))
#else
  return;
#endif
    command.append(" -a " + QFileInfo(atomType).absoluteFilePath());
  else
    command.append(" -a " + QFileInfo(QDir(workDir), atomType).absoluteFilePath());
  command.append(" -o " + QFileInfo(QDir(workDir), mask).absoluteFilePath());
  command.append(" -tt " + totalTypes);
  if (parent->ui->trj_checkBox_log->checkState() == 2)
#ifdef _WIN32
    if (log.contains("\\"))
#elif __linux
    if (log.contains("/"))
#else
  return;
#endif
      command.append(" -l " + QFileInfo(log).absoluteFilePath());
    else
      command.append(" -l " + QFileInfo(QDir(workDir), log).absoluteFilePath());
  command.append(" -q");

  system(command.toStdString().c_str());
  parent->ui->tabWidget->setEnabled(true);
  parent->ui->statusBar->showMessage(QApplication::translate("MainWindow", "Done"));
  delete errorwin;
}

void Start_events::start_statgen(QString mm_statgen_path)
{
  errorwin = new ErrorWindow(parent);
  parent->ui->statusBar->showMessage(QApplication::translate("MainWindow", "Processing 'statgen'..."));
  parent->ui->statusBar->showMessage(QApplication::translate("MainWindow", "Processing 'statgen'..."));

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
    errorwin->set_message(parent->language, 0);
    errorwin->show();
    return;
  }
  if (mask == "")
  {
    errorwin->set_message(parent->language, 1);
    errorwin->show();
    return;
  }
  if ((firstStep == "") || (lastStep == ""))
  {
    errorwin->set_message(parent->language, 2);
    errorwin->show();
    return;
  }
  if ((cellX == "") || (cellY == "") || (cellZ == ""))
  {
    errorwin->set_message(parent->language, 8);
    errorwin->show();
    return;
  }
  if ((atom0 == "") ||
    ((atom1 == "") && (parent->ui->statgen_checkBox_atoms1->checkState() == 2)) ||
    ((atom2 == "") && (parent->ui->statgen_checkBox_atoms2->checkState() == 2)) ||
    ((atom3 == "") && (parent->ui->statgen_checkBox_atoms3->checkState() == 2)))
  {
    errorwin->set_message(parent->language, 9);
    errorwin->show();
    return;
  }
  if (parent->ui->statgen_listWidget_int->count() == 0)
  {
    errorwin->set_message(parent->language, 10);
    errorwin->show();
    return;
  }
  if (output == "")
  {
    errorwin->set_message(parent->language, 4);
    errorwin->show();
    return;
  }
  if ((parent->ui->statgen_checkBox_depth->checkState() == 2) && (depth == ""))
  {
    errorwin->set_message(parent->language, 11);
    errorwin->show();
    return;
  }
  if ((parent->ui->statgen_checkBox_log->checkState() == 2) && (log == ""))
  {
    errorwin->set_message(parent->language, 6);
    errorwin->show();
    return;
  }
  if (!QFile(mm_statgen_path).exists())
  {
    errorwin->set_message(parent->language, 7);
    errorwin->show();
    return;
  }

// exec
  parent->ui->tabWidget->setDisabled(true);
  QString command;
  command.append(mm_statgen_path);
#ifdef _WIN32
  if (mask.contains("\\"))
#elif __linux
  if (mask.contains("/"))
#else
  return;
#endif
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
#ifdef _WIN32
  if (output.contains("\\"))
#elif __linux
  if (output.contains("/"))
#else
  return;
#endif
    command.append(" -o " + QFileInfo(output).absoluteFilePath());
  else
    command.append(" -o " + QFileInfo(QDir(workDir), output).absoluteFilePath());
  if (parent->ui->statgen_checkBox_depth->checkState() == 2)
    command.append(" -g " + depth);
  if (parent->ui->statgen_checkBox_log->checkState() == 2)
#ifdef _WIN32
    if (log.contains("\\"))
#elif __linux
    if (log.contains("/"))
#else
  return;
#endif
      command.append(" -l " + QFileInfo(log).absoluteFilePath());
    else
      command.append(" -l " + QFileInfo(QDir(workDir), log).absoluteFilePath());
  command.append(" -q");

  system(command.toStdString().c_str());
//  execv(command.toStdString().c_str(), NULL);
  parent->ui->tabWidget->setEnabled(true);
  parent->ui->statusBar->showMessage(QApplication::translate("MainWindow", "Done"));
  delete errorwin;
}
