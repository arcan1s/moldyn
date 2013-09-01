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
