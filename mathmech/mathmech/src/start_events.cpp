/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
#include <QDir>
#include <math.h>

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
                                          float int_step, int imax)
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
  QStringList inter_list = inter.split(QString(" -r "), QString::SkipEmptyParts);
  float *inter_list_one;
  inter_list_one = new float[16*inter_list.count()];
  for (int i=0; i<16*inter_list.count(); i++)
    inter_list_one[i] = 0.0;
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
  QList<int> inter_list_index;
  for (int i=0; i<16*inter_list.count(); i++)
    if (inter_list_one[i] != 0.0)
      inter_list_index.append(i);
  int files = pow((float)2*imax+1, inter_list_index.count());

// exec
  char file[32];
  int first, second, step;
  float *cur_inter;
  cur_inter = new float[16*inter_list.count()];
  QString one_inter;
  for (int i=0; i<16*inter_list.count(); i++)
    cur_inter[i] = 0.0;
  for (int i=0; i<files; i++)
  {
    QString command;
    inter = QString("");
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
    if (depth != QString("#"))
      command.append(" -g " + depth);
    command.append(" -q");

    step = i;
    for (int j=0; j<inter_list_index.count(); j++)
    {
      index = step % (2 * imax + 1);
      cur_inter[inter_list_index[j]] = inter_list_one[inter_list_index[j]] + int_step * (index - imax);
      if (cur_inter[inter_list_index[j]] < 0.0)
        cur_inter[inter_list_index[j]] = 0.1;
      step = step / (2 * imax + 1);
    }
    for (int j=0; j<inter_list.count(); j++)
    {
      one_inter = " -r ";
      for (int k=0; k<16; k++)
        if (cur_inter[16*j+k] != 0.0)
        {
          first = k % 4;
          second = k / 4;
          one_inter.append(QString::number(first) + "-" + QString::number(second) +
                           ":" + QString::number(cur_inter[16*j+k], 'f', 3) + ",");
        }
      one_inter.remove(one_inter.count()-1, 1);
      inter.append(one_inter);
    }
    command.append(inter);
    sprintf(file, "_%06i", i);
    if (output.contains(QDir::separator()))
      command.append(" -o " + QFileInfo(output).absoluteFilePath() + QString(file) + ".dat");
    else
      command.append(" -o " + QFileInfo(QDir(workDir), output).absoluteFilePath() + QString(file) + ".dat");
    if (log != QString("#"))
    {
      if (log.contains(QDir::separator()))
        command.append(" -l " + QFileInfo(log).absoluteFilePath() + QString(file) + ".log");
      else
        command.append(" -l " + QFileInfo(QDir(workDir), log).absoluteFilePath() + QString(file) + ".log");
    }
    system(command.toStdString().c_str());
  }
  delete inter_list_one;
  delete cur_inter;
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
