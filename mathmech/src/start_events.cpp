#include <QDir>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "errorwindow.h"

#include "start_events.h"

Start_events::Start_events(MainWindow *wid) :
  parent(wid)
{

}

bool Start_events::start_trj(QString mm_trj_path,
                             QString workDir,
                             QString input,
                             QString type,
                             QString steps,
                             QString atomType,
                             QString mask,
                             QString totalTypes,
                             QString log)
{
// error check
  errorwin = new ErrorWindow(parent);
  if ((workDir == "") || (!QDir(workDir).exists()))
  {
    errorwin->set_message(0);
    errorwin->show();
    return false;
  }
  if ((input == "") || (!QFile(input).exists()))
  {
    errorwin->set_message(1);
    errorwin->show();
    return false;
  }
  if ((atomType == "") || (!QFile(atomType).exists()))
  {
    errorwin->set_message(3);
    errorwin->show();
    return false;
  }
  if (mask == "")
  {
    errorwin->set_message(4);
    errorwin->show();
    return false;
  }
  if ((log != QString("#")) && (log == ""))
  {
    errorwin->set_message(6);
    errorwin->show();
    return false;
  }
  if (!QFile(mm_trj_path).exists())
  {
    errorwin->set_message(7);
    errorwin->show();
    return false;
  }
  delete errorwin;

// exec
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
  if (log != QString("#"))
  {
    if (log.contains(QDir::separator()))
      command.append(" -l " + QFileInfo(log).absoluteFilePath());
    else
      command.append(" -l " + QFileInfo(QDir(workDir), log).absoluteFilePath());
  }
  command.append(" -q");

  system(command.toStdString().c_str());
  return true;
}

bool Start_events::start_statgen(QString mm_statgen_path,
                                 QString workDir,
                                 QString mask,
                                 QString firstStep,
                                 QString lastStep,
                                 QString cellX, QString cellY, QString cellZ,
                                 QString atom0, QString atom1, QString atom2, QString atom3,
                                 QString inter,
                                 QString output,
                                 QString depth,
                                 QString log)
{
// error check
  errorwin = new ErrorWindow(parent);
  if ((workDir == "") || (!QDir(workDir).exists()))
  {
    errorwin->set_message(0);
    errorwin->show();
    return false;
  }
  if (mask == "")
  {
    errorwin->set_message(1);
    errorwin->show();
    return false;
  }
  if (inter == "")
  {
    errorwin->set_message(10);
    errorwin->show();
    return false;
  }
  if (output == "")
  {
    errorwin->set_message(4);
    errorwin->show();
    return false;
  }
  if ((log != QString("#")) && (log == ""))
  {
    errorwin->set_message(6);
    errorwin->show();
    return false;
  }
  if (!QFile(mm_statgen_path).exists())
  {
    errorwin->set_message(7);
    errorwin->show();
    return false;
  }
  delete errorwin;

// exec
  QString command;
  command.append(mm_statgen_path);
  if (mask.contains(QDir::separator()))
    command.append(" -i " + QFileInfo(mask).absoluteFilePath());
  else
    command.append(" -i " + QFileInfo(QDir(workDir), mask).absoluteFilePath());
  command.append(" -s " + firstStep + "," + lastStep);
  command.append(" -c " + cellX + "," + cellY + "," + cellZ);
  command.append(" -a " + atom0);
  if (atom1 != QString("#"))
    command.append("," + atom1);
  if (atom2 != QString("#"))
    command.append("," + atom2);
  if (atom3 != QString("#"))
    command.append("," + atom3);
  command.append(inter);
  if (output.contains(QDir::separator()))
    command.append(" -o " + QFileInfo(output).absoluteFilePath());
  else
    command.append(" -o " + QFileInfo(QDir(workDir), output).absoluteFilePath());
  if (depth != QString("#"))
    command.append(" -g " + depth);
  if (log != QString("#"))
  {
    if (log.contains(QDir::separator()))
      command.append(" -l " + QFileInfo(log).absoluteFilePath());
    else
      command.append(" -l " + QFileInfo(QDir(workDir), log).absoluteFilePath());
  }
  command.append(" -q");

  system(command.toStdString().c_str());
  return true;
}

bool Start_events::start_statgen_analysis(QString mm_statgen_path,
                                          QString workDir,
                                          QString mask,
                                          QString firstStep,
                                          QString lastStep,
                                          QString cellX, QString cellY, QString cellZ,
                                          QString atom0, QString atom1, QString atom2, QString atom3,
                                          QString inter,
                                          QString output,
                                          QString depth,
                                          QString log,
                                          float int_step)
{
// error check
  errorwin = new ErrorWindow(parent);
  if ((workDir == "") || (!QDir(workDir).exists()))
  {
    errorwin->set_message(0);
    errorwin->show();
    return false;
  }
  if (mask == "")
  {
    errorwin->set_message(1);
    errorwin->show();
    return false;
  }
  if (inter == "")
  {
    errorwin->set_message(10);
    errorwin->show();
    return false;
  }
  if (output == "")
  {
    errorwin->set_message(4);
    errorwin->show();
    return false;
  }
  if ((log != QString("#")) && (log == ""))
  {
    errorwin->set_message(6);
    errorwin->show();
    return false;
  }
  if (int_step == 0.0)
  {
    errorwin->set_message(12);
    errorwin->show();
    return false;
  }
  if (!QFile(mm_statgen_path).exists())
  {
    errorwin->set_message(7);
    errorwin->show();
    return false;
  }
  delete errorwin;

// parsing criteria
  int imax = 10;
  QStringList inter_list = inter.split(QString(" -r "), QString::SkipEmptyParts);
  float *inter_list_one;
  inter_list_one = new float[16*inter_list.count()];
  for (int i=0; i<16*inter_list.count(); i++)
    inter_list_one[i] = -1.0;
  float item;
  int index;
  for (int i=0; i<inter_list.count(); i++)
    for (int j=0; j<inter_list[i].split(QString(","), QString::SkipEmptyParts).count(); j++)
    {
      item = inter_list[i].split(QString(","), QString::SkipEmptyParts)[j].
             split(QString(":"), QString::SkipEmptyParts)[1].toFloat();
      index = inter_list[i].split(QString(","), QString::SkipEmptyParts)[j].
              split(QString(":"), QString::SkipEmptyParts)[0].
              split(QString("-"), QString::SkipEmptyParts)[0].toInt() +
              inter_list[i].split(QString(","), QString::SkipEmptyParts)[j].
              split(QString(":"), QString::SkipEmptyParts)[0].
              split(QString("-"), QString::SkipEmptyParts)[1].toInt() * 4;
      inter_list_one[16*i+index] = item;
    }
  for (int i=0; i<16*inter_list.count(); i++)
    if (inter_list_one[i] > 0.0)
      while (imax*int_step > inter_list_one[i])
        imax--;

// exec
  for (int i=-imax; i<=imax; i++)
  {
    QString command;
    command.append(mm_statgen_path);
    if (mask.contains(QDir::separator()))
      command.append(" -i " + QFileInfo(mask).absoluteFilePath());
    else
      command.append(" -i " + QFileInfo(QDir(workDir), mask).absoluteFilePath());
    command.append(" -s " + firstStep + "," + lastStep);
    command.append(" -c " + cellX + "," + cellY + "," + cellZ);
    command.append(" -a " + atom0);
    if (atom1 != QString("#"))
      command.append("," + atom1);
    if (atom2 != QString("#"))
      command.append("," + atom2);
    if (atom3 != QString("#"))
      command.append("," + atom3);
    command.append(inter);
    if (output.contains(QDir::separator()))
      command.append(" -o " + QFileInfo(output).absoluteFilePath());
    else
      command.append(" -o " + QFileInfo(QDir(workDir), output).absoluteFilePath());
    if (depth != QString("#"))
      command.append(" -g " + depth);
    if (log != QString("#"))
    {
      if (log.contains(QDir::separator()))
        command.append(" -l " + QFileInfo(log).absoluteFilePath());
      else
        command.append(" -l " + QFileInfo(QDir(workDir), log).absoluteFilePath());
    }
    command.append(" -q");

    system(command.toStdString().c_str());
  }
  delete inter_list_one;
  return true;
}

bool Start_events::start_envir(QString mm_envir_path,
                               QString workDir,
                               QString input,
                               QString cellX, QString cellY, QString cellZ,
                               QString output,
                               QString molecule,
                               QString radius,
                               QString log)
{
// error check
  errorwin = new ErrorWindow(parent);
  if ((workDir == "") || (!QDir(workDir).exists()))
  {
    errorwin->set_message(0);
    errorwin->show();
    return false;
  }
  if (input == "")
  {
    errorwin->set_message(1);
    errorwin->show();
    return false;
  }
  if (output == "")
  {
    errorwin->set_message(4);
    errorwin->show();
    return false;
  }
  if ((log != QString("#")) && (log == ""))
  {
    errorwin->set_message(6);
    errorwin->show();
    return false;
  }
  if (!QFile(mm_envir_path).exists())
  {
    errorwin->set_message(7);
    errorwin->show();
    return false;
  }
  delete errorwin;

// exec
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
  if (log != QString("#"))
  {
    if (log.contains(QDir::separator()))
      command.append(" -l " + QFileInfo(log).absoluteFilePath());
    else
      command.append(" -l " + QFileInfo(QDir(workDir), log).absoluteFilePath());
  }
  command.append(" -q");

  system(command.toStdString().c_str());
  return true;
}

bool Start_events::start_radf(QString mm_radf_path,
                              QString workDir,
                              QString mask,
                              QString firstStep,
                              QString lastStep,
                              QString cellX, QString cellY, QString cellZ,
                              QString output,
                              QString atom0, QString atom1, QString atom2,
                              QString atom3, QString atom4, QString atom5,
                              QString radMin, QString radMax, QString radStep,
                              QString angMin, QString angMax, QString angStep,
                              QString log, int matrix)
{
// error check
  errorwin = new ErrorWindow(parent);
  if ((workDir == "") || (!QDir(workDir).exists()))
  {
    errorwin->set_message(0);
    errorwin->show();
    return false;
  }
  if (mask == "")
  {
    errorwin->set_message(1);
    errorwin->show();
    return false;
  }
  if (output == "")
  {
    errorwin->set_message(4);
    errorwin->show();
    return false;
  }
  if (atom1 != QString("#"))
    if ((atom0 == atom1) || (atom0 == atom2) || (atom1 == atom2) ||
        (atom3 == atom4) || (atom3 == atom5) || (atom4 == atom5))
    {
      errorwin->set_message(2);
      errorwin->show();
      return false;
    }
  if ((log != QString("#")) && (log == ""))
  {
    errorwin->set_message(6);
    errorwin->show();
    return false;
  }
  if (!QFile(mm_radf_path).exists())
  {
    errorwin->set_message(7);
    errorwin->show();
    return false;
  }
  delete errorwin;

// exec
  QString command;
  command.append(mm_radf_path);
  if (mask.contains(QDir::separator()))
    command.append(" -i " + QFileInfo(mask).absoluteFilePath());
  else
    command.append(" -i " + QFileInfo(QDir(workDir), mask).absoluteFilePath());
  command.append(" -s " + firstStep + "," + lastStep);
  command.append(" -c " + cellX + "," + cellY + "," + cellZ);
  if (atom1 == QString("#"))
    command.append(" -at " + atom0 + "-" + atom3);
  else
    command.append(" -at " + atom0 + "," + atom1 + "," + atom2 +
                   "-" + atom3 + "," + atom4 + "," + atom5);
  if (output.contains(QDir::separator()))
    command.append(" -o " + QFileInfo(output).absoluteFilePath());
  else
    command.append(" -o " + QFileInfo(QDir(workDir), output).absoluteFilePath());
  command.append(" -r " + radMin + "," + radMax);
  command.append(" -rs " + radStep);
  if (angStep != QString("#"))
  {
    command.append(" -a " + angMin + "," + angMax);
    command.append(" -as " + angStep);
  }
  if (matrix == 1)
    command.append(" -m ");
  if (log != QString("#"))
  {
    if (log.contains(QDir::separator()))
      command.append(" -l " + QFileInfo(log).absoluteFilePath());
    else
      command.append(" -l " + QFileInfo(QDir(workDir), log).absoluteFilePath());
  }
  command.append(" -q");

  system(command.toStdString().c_str());
  return true;
}

bool Start_events::start_pdb(QString mm_pdb_path,
                             QString workDir,
                             QString input,
                             QString agl,
                             QString cellX, QString cellY, QString cellZ,
                             QString output,
                             QString log)
{
// error check
  errorwin = new ErrorWindow(parent);
  if ((workDir == "") || (!QDir(workDir).exists()))
  {
    errorwin->set_message(0);
    errorwin->show();
    return false;
  }
  if (input == "")
  {
    errorwin->set_message(1);
    errorwin->show();
    return false;
  }
  if ((agl != QString("#")) && (agl == ""))
  {
    errorwin->set_message(1);
    errorwin->show();
    return false;
  }
  if (output == "")
  {
    errorwin->set_message(4);
    errorwin->show();
    return false;
  }
  if ((log != QString("#")) && (log == ""))
  {
    errorwin->set_message(6);
    errorwin->show();
    return false;
  }
  if (!QFile(mm_pdb_path).exists())
  {
    errorwin->set_message(7);
    errorwin->show();
    return false;
  }
  delete errorwin;

// exec
  QString command;
  command.append(mm_pdb_path);
  if (agl != QString("#"))
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
  if (agl != QString("#"))
    command.append(" -c " + cellX + "," + cellY + "," + cellZ);
  if (output.contains(QDir::separator()))
    command.append(" -o " + QFileInfo(output).absoluteFilePath());
  else
    command.append(" -o " + QFileInfo(QDir(workDir), output).absoluteFilePath());
  if (log != QString("#"))
  {
    if (log.contains(QDir::separator()))
      command.append(" -l " + QFileInfo(log).absoluteFilePath());
    else
      command.append(" -l " + QFileInfo(QDir(workDir), log).absoluteFilePath());
  }
  command.append(" -q");

  system(command.toStdString().c_str());
  return true;
}
