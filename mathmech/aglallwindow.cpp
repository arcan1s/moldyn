#include "aglallwindow.h"
#include "ui_aglallwindow.h"

AglAllWindow::AglAllWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::AglAllWindow)
{
  ui->setupUi(this);
}

AglAllWindow::~AglAllWindow()
{
  delete ui;
}
