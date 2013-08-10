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
