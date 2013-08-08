#include <QDir>
#include <QFileDialog>
#include <QKeyEvent>
#include <QTextStream>

#include "atomtypeswindow.h"
#include "ui_atomtypeswindow.h"

#include "errorwindow.h"
#include "ui_errorwindow.h"

AtomTypesWindow::AtomTypesWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::AtomTypesWindow)
{
  ui->setupUi(this);
  num_of_mol = new int[100];
  for (int i=0; i<100; i++)
  {
    num_of_mol[i] = 1;
    atomTypes.append(QString(""));
  }
}

AtomTypesWindow::~AtomTypesWindow()
{
  delete ui;
  delete num_of_mol;
}

// ESC press event
void AtomTypesWindow::keyPressEvent(QKeyEvent *pressedKey)
{
  if (pressedKey->key() == Qt::Key_Escape)
    close();
}

// events
void AtomTypesWindow::on_atomTypes_pushButton_output_clicked()
{
  QString filename = QFileDialog::getSaveFileName(
                     this,
                     tr("Save file as..."),
                     QDir::currentPath(),
                     tr("Atom types files (*.types);;All files (*.*)"));
  if (!filename.isEmpty())
    ui->atomTypes_lineEdit_output->setText(filename);
}

void AtomTypesWindow::on_atomTypes_pushButton_add_clicked()
{
  errorwin = new ErrorWindow(this);
  QString charAtomType = ui->atomTypes_lineEdit_chType->text();
  QString intAtomType= QString::number(ui->atomTypes_spinBox_intType->value());

  if ((charAtomType.count() != 2) || (charAtomType.split(' ', QString::SkipEmptyParts)[0] != charAtomType))
  {
    errorwin->set_message(5);
    errorwin->show();
    return;
  }

  ui->atomTypes_listWidget->addItem(charAtomType + "=" + intAtomType);
  atomTypes[ui->atomTypes_comboBox_mol->currentIndex()] = QString("");
  for (int i=0; i<ui->atomTypes_listWidget->count(); i++)
    atomTypes[ui->atomTypes_comboBox_mol->currentIndex()].append(ui->atomTypes_listWidget->item(i)->text() + ",");

  delete errorwin;
}

void AtomTypesWindow::on_atomTypes_pushButton_typeRem_clicked()
{
  int curIndex = ui->atomTypes_listWidget->currentRow();
  if (curIndex > -1)
    delete ui->atomTypes_listWidget->item(curIndex);
}

void AtomTypesWindow::on_atomTypes_pushButton_clear_clicked()
{
  for (int i=0; i<100; i++)
  {
    num_of_mol[i] = 1;
    atomTypes[i] = QString("");
  }
  ui->atomTypes_lineEdit_output->clear();
  ui->atomTypes_comboBox_mol->clear();
  ui->atomTypes_comboBox_mol->addItem(QString("1"));
  ui->atomTypes_comboBox_mol->addItem(QApplication::translate("AtomTypesWindow", "Add new molecule"));
}

void AtomTypesWindow::on_atomTypes_spinBox_numOfMol_editingFinished()
{
  num_of_mol[ui->atomTypes_comboBox_mol->currentIndex()] = ui->atomTypes_spinBox_numOfMol->value();
}

void AtomTypesWindow::on_atomTypes_comboBox_mol_currentIndexChanged(int index)
{
  ui->atomTypes_lineEdit_chType->clear();
  ui->atomTypes_spinBox_intType->setValue(1);
  ui->atomTypes_listWidget->clear();
  if (ui->atomTypes_comboBox_mol->itemText(index) == (QApplication::translate("AtomTypesWindow", "Add new molecule")))
  {
    ui->atomTypes_comboBox_mol->setItemText(index, QString::number(index+1));
    ui->atomTypes_comboBox_mol->addItem(QApplication::translate("AtomTypesWindow", "Add new molecule"));
    ui->atomTypes_spinBox_numOfMol->setValue(num_of_mol[index]);
  }
  else if (index == -1)
    return;
  else
  {
    ui->atomTypes_spinBox_numOfMol->setValue(num_of_mol[index]);
    ui->atomTypes_listWidget->addItems(atomTypes[index].split(',', QString::SkipEmptyParts));
  }
}

void AtomTypesWindow::on_atomTypes_pushButton_create_clicked()
{
  errorwin = new ErrorWindow(this);
  QString output = ui->atomTypes_lineEdit_output->text();
  QString num_mol = QString::number(ui->atomTypes_comboBox_mol->count() - 1);

  for (int i=0; i<num_mol.toInt(); i++)
    if (atomTypes[i] == "")
    {
      errorwin->set_message(8);
      errorwin->show();
      return;
    }
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
  out << "NUMTYPES=" << num_mol << "\n";
  for (int i=0; i<num_mol.toInt(); i++)
  {
    out << "NUMMOL=" << num_of_mol[i] << "\n";
    out << "NUMAT=" << atomTypes[i].split(',', QString::SkipEmptyParts).count() << "\n";
    out << atomTypes[i].split(',', QString::SkipEmptyParts).join("\n") << "\n";
  }
  f_out.close();

  on_atomTypes_pushButton_clear_clicked();

  delete errorwin;
}
