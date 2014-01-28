/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
#include <QDir>
#include <QFileDialog>
#include <QKeyEvent>
#include <QTextStream>

#include "errorwindow.h"

#include "aglallwindow.h"
#include "ui_aglallwindow.h"

AglAllWindow::AglAllWindow(QWidget *parent, QString mm_agl_path) :
  QMainWindow(parent),
  ui(new Ui::AglAllWindow)
{
  ui->setupUi(this);
  _mm_agl_path = mm_agl_path;
}

AglAllWindow::~AglAllWindow()
{
  delete ui;
}

// ESC press event
void AglAllWindow::keyPressEvent(QKeyEvent *pressedKey)
{
  if (pressedKey->key() == Qt::Key_Escape)
    close();
}

void AglAllWindow::on_aglall_pushButton_clear_clicked()
{
  ui->aglall_lineEdit_workDir->clear();
  ui->aglall_lineEdit_input->clear();
  ui->aglall_lineEdit_output->clear();
  ui->aglall_spinBox_file->setValue(0);
  ui->aglall_spinBox_num->setValue(0);
}

void AglAllWindow::on_aglall_pushButton_workDir_clicked()
{
  QString dirname = QFileDialog::getExistingDirectory(
                    this,
                    tr("Select work directory"),
                    QDir::currentPath());
  if (!dirname.isEmpty())
    ui->aglall_lineEdit_workDir->setText(dirname);
}

void AglAllWindow::on_pdb_pushButton_input_clicked()
{
  QString filename = QFileDialog::getOpenFileName(
                     this,
                     tr("Select trajectory file"),
                     QDir(ui->aglall_lineEdit_workDir->text()).absolutePath(),
                     tr("'statgen' output files (*.dat);;All files (*.*)"));
  if (!filename.isEmpty())
    ui->aglall_lineEdit_input->setText(filename);
}

void AglAllWindow::on_aglall_pushButton_output_clicked()
{
  QString filename = QFileDialog::getSaveFileName(
                       this,
                       tr("Save file as..."),
                       QDir(ui->aglall_lineEdit_workDir->text()).absolutePath(),
                       tr("PDB files (*.pdb);;All files (*.*)"));
  if (!filename.isEmpty())
    ui->aglall_lineEdit_output->setText(filename.split(QString("."))[0]);
}

void AglAllWindow::on_aglall_pushButton_start_clicked()
{
  ui->centralwidget->setDisabled(true);
  start_agl();
  ui->centralwidget->setEnabled(true);
}

void AglAllWindow::start_agl()
{
  errorwin = new ErrorWindow(this);
  ui->statusbar->showMessage(QApplication::translate("AglAll", "Processing 'agl'..."));
  ui->statusbar->showMessage(QApplication::translate("AglAll", "Processing 'agl'..."));

// read variables
  QString workDir = ui->aglall_lineEdit_workDir->text();
  QString input = ui->aglall_lineEdit_input->text();
  QString output = ui->aglall_lineEdit_output->text();

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
  if (!QFile(_mm_agl_path).exists())
  {
    errorwin->set_message(7);
    errorwin->show();
    return;
  }
  if (output.contains(QString(".pdb")))
    output = output.split(QString(".pdb"), QString::SkipEmptyParts)[0];
  if (output.contains(QDir::separator()))
    output = QFileInfo(output).absoluteFilePath();
  else
    output = QFileInfo(QDir(workDir), output).absoluteFilePath();

// reading file
  QString tmp_str;
  QFile inp_agl(input);
  bool exists = inp_agl.open(QIODevice::ReadOnly);
  if (!exists)
  {
    errorwin->set_message(1);
    errorwin->show();
    return;
  }
  tmp_str = QString(inp_agl.readLine());
  if (!tmp_str.contains(QString("statgen")))
  {
    errorwin->set_message(11);
    errorwin->show();
    return;
  }

  QString mask;
  float cellX, cellY, cellZ;
  while (!tmp_str.contains(QString("END")))
  {
    if (tmp_str.contains(QString("MASK=")))
      mask = tmp_str.split(QString("MASK="), QString::SkipEmptyParts)[0];
    else if (tmp_str.contains(QString("CELL=")))
    {
      cellX = tmp_str.split(QString("CELL="), QString::SkipEmptyParts)[0].
              split(QString(","), QString::SkipEmptyParts)[0].toFloat();
      cellY = tmp_str.split(QString("CELL="), QString::SkipEmptyParts)[0].
              split(QString(","), QString::SkipEmptyParts)[1].toFloat();
      cellZ = tmp_str.split(QString("CELL="), QString::SkipEmptyParts)[0].
              split(QString(","), QString::SkipEmptyParts)[2].toFloat();
    }
    tmp_str = QString(inp_agl.readLine());
  }
  char cell[256];
  sprintf (cell, "%.4f,%.4f,%.4f", cellX, cellY, cellZ);

  int num_file = ui->aglall_spinBox_file->value();
  int num_mol = ui->aglall_spinBox_num->value();
  int agl_num = 0, cur_agl_size = -1, cur_file = -1;
  QString agl_output, cur_file_name;
  while (!tmp_str.contains(QString("SUMMARY STATISTIC")))
  {
    if (tmp_str.contains(QString("FILE=")))
    {
      cur_file = tmp_str.split(QString("FILE="), QString::SkipEmptyParts)[0].
                 split(QString("\n"), QString::SkipEmptyParts)[0].
                 split(QString("."), QString::SkipEmptyParts).last().toInt();
      cur_file_name = tmp_str.split(QString("FILE="), QString::SkipEmptyParts)[0].
                      split(QString("\n"), QString::SkipEmptyParts)[0];
    }
    else if ((tmp_str.contains(QString("AGL="))) &&
             ((cur_file == num_file) || (num_file == 0)))
    {
      cur_agl_size = tmp_str.split(QString("="), QString::SkipEmptyParts)[1].toInt();
      if ((cur_agl_size == num_mol) || (num_mol == 0))
      {
        agl_output = workDir + QString("/temp_agl.agl");
        QFile f_out(agl_output);
        if (!f_out.open(QIODevice::WriteOnly | QIODevice::Text))
        {
          errorwin->set_message(9);
          errorwin->show();
          return;
        }
        QTextStream out(&f_out);
        out << tmp_str;
        for (int i=0; i<cur_agl_size; i++)
        {
          tmp_str = QString(inp_agl.readLine());
          out << tmp_str;
        }
        f_out.close();
// start event
        agl_num++;
        start_agl_event(agl_output, cur_file_name, QString(cell),
                        output + QString("_") + QString::number(cur_file) +
                        QString("_") + QString::number(agl_num) + QString(".pdb"));
      }
    }
    tmp_str = QString(inp_agl.readLine());
  }
  inp_agl.close();

  ui->statusbar->showMessage(QApplication::translate("AglAll", "Done"));
  delete errorwin;
}

void AglAllWindow::start_agl_event(QString aglfile, QString trjfile, QString cellsize, QString out_file)
{
  QString command;
  command.append(_mm_agl_path);
  command.append(" -a " + aglfile);
  command.append(" -i " + trjfile);
  command.append(" -c " + cellsize);
  command.append(" -o " + out_file);
  command.append(" -q");

  system(command.toStdString().c_str());
}
