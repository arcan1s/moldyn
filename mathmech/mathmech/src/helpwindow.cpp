/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file helpwindow.cpp
 * Source code of mathmech
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#include <QDir>
#include <QFileDialog>
#include <QKeyEvent>
#include <QTextStream>

#include "errorwindow.h"

#include "helpwindow.h"
#include "ui_helpwindow.h"

HelpWindow::HelpWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::HelpWindow)
{
  ui->setupUi(this);
}

HelpWindow::~HelpWindow()
{
  delete ui;
}

// ESC press event
void HelpWindow::keyPressEvent(QKeyEvent *pressedKey)
{
  if (pressedKey->key() == Qt::Key_Escape)
    close();
}

void HelpWindow::on_pushButton_save_clicked()
{
  errorwin = new ErrorWindow(this);

  QString filename = QFileDialog::getSaveFileName(
                     this,
                     tr("Save file as"),
                     QDir::currentPath(),
                     tr("html files (*.html);;All files (*.*)"));
  if (filename.isEmpty())
    return;
  filename = QFileInfo(filename).absoluteFilePath();
  QFile f_out(filename);
  if (!f_out.open(QIODevice::WriteOnly | QIODevice::Text))
  {
    errorwin->set_message(9);
    errorwin->show();
    return;
  }
  QTextStream out(&f_out);
  QString text = QString("");
  int page = ui->toolBox->currentIndex();
  if (page == 0)
    text = ui->textBrowser_trj->toHtml();
  else if (page == 1)
    text = ui->textBrowser_statgen->toHtml();
  else if (page == 2)
    text = ui->textBrowser_envir->toHtml();
  else if (page == 3)
    text = ui->textBrowser_radf->toHtml();
  else if (page == 4)
    text = ui->textBrowser_agl->toHtml();
  else if (page == 5)
    text = ui->textBrowser_trj2pdb->toHtml();
  out << text;
  f_out.close();

  delete errorwin;
}
