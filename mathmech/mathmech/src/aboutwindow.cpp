/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
#include <QKeyEvent>

#include "aboutwindow.h"
#include "ui_aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::AboutWindow)
{
  ui->setupUi(this);
}

AboutWindow::~AboutWindow()
{
  delete ui;
}

// ESC press event
void AboutWindow::keyPressEvent(QKeyEvent *pressedKey)
{
  if (pressedKey->key() == Qt::Key_Escape)
    close();
}
