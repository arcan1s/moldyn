#include <QDir>
#include <QKeyEvent>
#include <QFileDialog>
#include <QTextStream>

#include "errorwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(MainWindow *parent) :
  QMainWindow(parent),
  ui(new Ui::SettingsWindow)
{
  ui->setupUi(this);
  _parent = parent;

#ifdef _WIN32
  configpath = QFileInfo(QDir::currentPath(), ("mathmech.ini")).absoluteFilePath();
#elif __linux
  configpath = QFileInfo(QDir(QDir::homePath() + "/.config"), ("mathmech.conf")).absoluteFilePath();
#else
  return;
#endif
  if (QFileInfo(configpath).exists())
    readSettings();
  else
  {
    setDefaults();
    applySettings();
  }
  showSettings();
}

SettingsWindow::~SettingsWindow()
{
  delete ui;
}

// ESC press event
void SettingsWindow::keyPressEvent(QKeyEvent *pressedKey)
{
  if (pressedKey->key() == Qt::Key_Escape)
    close();
}

void SettingsWindow::applySettings()
{
  errorwin = new ErrorWindow(this);

  QString mm_trj_path = ui->settings_lineEdit_trj->text();
  QString mm_statgen_path = ui->settings_lineEdit_statgen->text();
  QString mm_envir_path = ui->settings_lineEdit_envir->text();
  QString mm_agl_path = ui->settings_lineEdit_agl->text();
  QString mm_radf_path = ui->settings_lineEdit_radf->text();
  QString mm_trj2pdb_path = ui->settings_lineEdit_trj2pdb->text();

  if ((!QFile(mm_trj_path).exists()) || (mm_trj_path == "") ||
      (!QFile(mm_statgen_path).exists()) || (mm_statgen_path == "") ||
      (!QFile(mm_envir_path).exists()) || (mm_envir_path == "") ||
      (!QFile(mm_agl_path).exists()) || (mm_agl_path == "") ||
      (!QFile(mm_radf_path).exists()) || (mm_radf_path == "") ||
      (!QFile(mm_trj2pdb_path).exists()) || (mm_trj2pdb_path == ""))
  {
    errorwin->set_message(7);
    errorwin->show();
    return;
  }

  if (ui->settings_comboBox_lang->currentIndex() == 0)
    _parent->language = QString("eng");
  else if (ui->settings_comboBox_lang->currentIndex() == 1)
    _parent->language = QString("rus");
  _parent->mm_trj_path = mm_trj_path;
  _parent->mm_statgen_path = mm_statgen_path;
  _parent->mm_envir_path = mm_envir_path;
  _parent->mm_radf_path = mm_radf_path;
  _parent->mm_trj2pdb_path = mm_trj2pdb_path;
  _parent->mm_agl_path = mm_agl_path;

  delete errorwin;
  printSettings();
}

void SettingsWindow::printSettings()
{
  errorwin = new ErrorWindow(this);

  QFile conf_file(configpath);
  if (!conf_file.open(QIODevice::WriteOnly | QIODevice::Text))
  {
    errorwin->set_message(9);
    errorwin->show();
    return;
  }
  QTextStream out(&conf_file);
  out << "LANG=" << _parent->language << "\n";
  out << "MM_TRJ_PATH=" << _parent->mm_trj_path << "\n";
  out << "MM_STATGEN_PATH=" << _parent->mm_statgen_path << "\n";
  out << "MM_ENVIR_PATH=" << _parent->mm_envir_path << "\n";
  out << "MM_RADF_PATH=" << _parent->mm_radf_path << "\n";
  out << "MM_TRJ2PDB_PATH=" << _parent->mm_trj2pdb_path << "\n";
  out << "MM_AGL_PATH=" << _parent->mm_agl_path << "\n";
  conf_file.close();

  delete errorwin;
}

void SettingsWindow::setDefaults()
{
  QString suffix = "";
#ifdef _WIN32
  suffix = QString(".exe");
#endif
  _parent->language = QString("eng");
  _parent->mm_trj_path = QDir::currentPath() + QDir::separator() + "mm_trj" + suffix;
  _parent->mm_statgen_path = QDir::currentPath() + QDir::separator() + "mm_statgen" + suffix;
  _parent->mm_envir_path = QDir::currentPath() + QDir::separator() + "mm_envir" + suffix;
  _parent->mm_radf_path = QDir::currentPath() + QDir::separator() + "mm_radf" + suffix;
  _parent->mm_trj2pdb_path = QDir::currentPath() + QDir::separator() + "mm_trj2pdb" + suffix;
  _parent->mm_agl_path = QDir::currentPath() + QDir::separator() + "mm_agl" + suffix;
}

void SettingsWindow::readSettings()
{
  errorwin = new ErrorWindow(this);

  QFile conf_file(configpath);
  if (!conf_file.open(QIODevice::ReadOnly | QIODevice::Text))
  {
    errorwin->set_message(9);
    errorwin->show();
    return;
  }
  QTextStream out(&conf_file);
  QStringList text = out.readAll().split(QString("\n"), QString::SkipEmptyParts);
  conf_file.close();

  for (int i=0; i<text.count(); i++)
    if (text[i].contains(QString("LANG=")))
      _parent->language = text[i].split(QString("LANG="), QString::SkipEmptyParts)[0];
    else if (text[i].contains(QString("MM_TRJ_PATH=")))
      _parent->mm_trj_path = text[i].split(QString("MM_TRJ_PATH="), QString::SkipEmptyParts)[0];
    else if (text[i].contains(QString("MM_STATGEN_PATH=")))
      _parent->mm_statgen_path = text[i].split(QString("MM_STATGEN_PATH="), QString::SkipEmptyParts)[0];
    else if (text[i].contains(QString("MM_ENVIR_PATH=")))
      _parent->mm_envir_path = text[i].split(QString("MM_ENVIR_PATH="), QString::SkipEmptyParts)[0];
    else if (text[i].contains(QString("MM_RADF_PATH=")))
      _parent->mm_radf_path = text[i].split(QString("MM_RADF_PATH="), QString::SkipEmptyParts)[0];
    else if (text[i].contains(QString("MM_TRJ2PDB_PATH=")))
      _parent->mm_trj2pdb_path = text[i].split(QString("MM_TRJ2PDB_PATH="), QString::SkipEmptyParts)[0];
    else if (text[i].contains(QString("MM_AGL_PATH=")))
      _parent->mm_agl_path = text[i].split(QString("MM_AGL_PATH="), QString::SkipEmptyParts)[0];

  delete errorwin;
}

void SettingsWindow::showSettings()
{
  ui->settings_lineEdit_trj->setText(_parent->mm_trj_path);
  ui->settings_lineEdit_statgen->setText(_parent->mm_statgen_path);
  ui->settings_lineEdit_envir->setText(_parent->mm_envir_path);
  ui->settings_lineEdit_radf->setText(_parent->mm_radf_path);
  ui->settings_lineEdit_agl->setText(_parent->mm_agl_path);
  ui->settings_lineEdit_trj2pdb->setText(_parent->mm_trj2pdb_path);
  if (_parent->language == QString("eng"))
    ui->settings_comboBox_lang->setCurrentIndex(0);
  else if (_parent->language == QString("rus"))
    ui->settings_comboBox_lang->setCurrentIndex(1);
}

void SettingsWindow::on_settings_pushButton_save_clicked()
{
  applySettings();
  close();
}

// browse signals
void SettingsWindow::on_settings_pushButton_trj_clicked()
{
  QString filename = QFileDialog::getOpenFileName(
                     this,
                     tr("Select component"),
                     QDir::currentPath(),
                     tr("All files (*)"));
  if (!filename.isEmpty())
    ui->settings_lineEdit_trj->setText(filename);
}

void SettingsWindow::on_settings_pushButton_statgen_clicked()
{
  QString filename = QFileDialog::getOpenFileName(
                     this,
                     tr("Select component"),
                     QDir::currentPath(),
                     tr("All files (*)"));
  if (!filename.isEmpty())
    ui->settings_lineEdit_statgen->setText(filename);
}

void SettingsWindow::on_settings_pushButton_envir_clicked()
{
  QString filename = QFileDialog::getOpenFileName(
                     this,
                     tr("Select component"),
                     QDir::currentPath(),
                     tr("All files (*)"));
  if (!filename.isEmpty())
    ui->settings_lineEdit_envir->setText(filename);
}

void SettingsWindow::on_settings_pushButton_radf_clicked()
{
  QString filename = QFileDialog::getOpenFileName(
                     this,
                     tr("Select component"),
                     QDir::currentPath(),
                     tr("All files (*)"));
  if (!filename.isEmpty())
    ui->settings_lineEdit_radf->setText(filename);
}

void SettingsWindow::on_settings_pushButton_trj2pdb_clicked()
{
  QString filename = QFileDialog::getOpenFileName(
                     this,
                     tr("Select component"),
                     QDir::currentPath(),
                     tr("All files (*)"));
  if (!filename.isEmpty())
    ui->settings_lineEdit_trj2pdb->setText(filename);
}

void SettingsWindow::on_settings_pushButton_agl_clicked()
{
  QString filename = QFileDialog::getOpenFileName(
                     this,
                     tr("Select component"),
                     QDir::currentPath(),
                     tr("All files (*)"));
  if (!filename.isEmpty())
    ui->settings_lineEdit_agl->setText(filename);
}
