#include <QDir>
#include <QFileDialog>
#include <QKeyEvent>
#include <QTextStream>

#include "errorwindow.h"

#include "agglwindow.h"
#include "ui_agglwindow.h"

AgglWindow::AgglWindow(QWidget *parent, QString inputfile) :
  QMainWindow(parent),
  ui(new Ui::AgglWindow)
{
  ui->setupUi(this);

  ui->agl_lineEdit_input->setText(inputfile);
}

AgglWindow::~AgglWindow()
{
  delete ui;
}

// ESC press event
void AgglWindow::keyPressEvent(QKeyEvent *pressedKey)
{
  if (pressedKey->key() == Qt::Key_Escape)
    close();
}

// events
void AgglWindow::on_agl_pushButton_input_clicked()
{
  QString filename = QFileDialog::getOpenFileName(
                     this,
                     tr("Select file"),
                     QDir::currentPath(),
                     tr("'statgen' output files (*.dat);;All files (*.*)"));
  if (!filename.isEmpty())
    ui->agl_lineEdit_input->setText(filename);
}

void AgglWindow::on_pushButton_clicked()
{
  errorwin = new ErrorWindow(this);

  QString input = ui->agl_lineEdit_input->text();
  QString tmp_str;
  QFile inp_agl(input);
  bool exists = inp_agl.open(QIODevice::ReadOnly);
  if ((input == "") || (!exists))
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

  while (!tmp_str.contains(QString("END")))
    tmp_str = QString(inp_agl.readLine());

  QStringList cur_aggl_mol, one_file_aggl, one_file_aggl_mol;
  int mol;
  while (!tmp_str.contains(QString("SUMMARY STATISTIC")))
  {
    tmp_str = QString(inp_agl.readLine());
    if (tmp_str.contains(QString("FILE=")))
    {
      inp_file.append(tmp_str.split(QString("FILE="), QString::SkipEmptyParts)[0].
          split(QString("\n"), QString::SkipEmptyParts)[0]);
      aggl.append(one_file_aggl.join(QString(";")));
      one_file_aggl.clear();
      aggl_mol.append(one_file_aggl_mol.join(QString(";")));
      one_file_aggl_mol.clear();
    }
    else if (tmp_str.contains(QString("AGL=")))
    {
      cur_aggl_mol.clear();
      mol = tmp_str.split('=')[1].toInt();
      one_file_aggl.append(tmp_str.split(QString("AGL="), QString::SkipEmptyParts)[0].
          split(QString("\n"), QString::SkipEmptyParts)[0]);
      for (int i=0; i<mol; i++)
      {
        tmp_str = QString(inp_agl.readLine());
        cur_aggl_mol.append(tmp_str);
      }
      one_file_aggl_mol.append(cur_aggl_mol.join(QString("")));
    }
  }
  aggl.append(one_file_aggl.join(QString(";")));
  one_file_aggl.clear();
  aggl.removeFirst();
  aggl_mol.append(one_file_aggl_mol.join(QString(";")));
  one_file_aggl_mol.clear();
  aggl_mol.removeFirst();
  inp_agl.close();

  ui->agl_comboBox->clear();
  ui->agl_comboBox->addItems(inp_file);

  delete errorwin;
}

void AgglWindow::on_agl_comboBox_currentIndexChanged(int index)
{
  ui->agl_listWidget->clear();
  ui->agl_textBrowser->clear();
  if (index != -1)
  {
    ui->agl_listWidget->addItems(aggl[index].split(QString(";")));
    ui->agl_listWidget->setCurrentRow(0);
  }
}

void AgglWindow::on_agl_listWidget_itemActivated()
{
  int index = ui->agl_listWidget->currentRow();
  ui->agl_textBrowser->clear();
  ui->agl_textBrowser->setText(aggl_mol[ui->agl_comboBox->currentIndex()].split(QString(";"))[index]);
  ui->agl_lineEdit_output->setText(QFileInfo(ui->agl_lineEdit_input->text()).canonicalPath() + QDir::separator() +
                                   QFileInfo(ui->agl_lineEdit_input->text()).completeBaseName() +
                                   QString("_") + QString::number(ui->agl_comboBox->currentIndex()) +
                                   QString("_") + QString::number(index) + QString(".agl"));
}

void AgglWindow::on_agl_pushButton_output_clicked()
{
  QString filename = QFileDialog::getSaveFileName(
                     this,
                     tr("Save file as..."),
                     QDir::currentPath(),
                     tr("Agglomerate files (*.agl);;All files (*.*)"));
  if (!filename.isEmpty())
    ui->agl_lineEdit_output->setText(filename);
}

void AgglWindow::on_agl_pushButton_clear_clicked()
{
  aggl.clear();
  aggl_mol.clear();
  inp_file.clear();
  ui->agl_comboBox->clear();
  ui->agl_lineEdit_input->clear();
  ui->agl_lineEdit_output->clear();
}

void AgglWindow::on_agl_pushButton_create_clicked()
{
  errorwin = new ErrorWindow(this);

  QString output = ui->agl_lineEdit_output->text();
  int file_num = ui->agl_comboBox->currentIndex();
  int aggl_num = ui->agl_listWidget->currentRow();

  if (output == "")
  {
    errorwin->set_message(4);
    errorwin->show();
    return;
  }

  output = QFileInfo(output).absoluteFilePath();
  QFile f_out(output);
  if (!f_out.open(QIODevice::WriteOnly | QIODevice::Text))
  {
    errorwin->set_message(9);
    errorwin->show();
    return;
  }
  QTextStream out(&f_out);
  out << "AGL=" << aggl[file_num].split(QString(";"))[aggl_num] << "\n";
  out << aggl_mol[file_num].split(QString(";"))[aggl_num];
  f_out.close();

  ui->agl_lineEdit_output->clear();

  delete errorwin;
}
