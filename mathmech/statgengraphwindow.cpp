#include "statgengraphwindow.h"
#include "ui_statgengraphwindow.h"

StatgenGraphWindow::StatgenGraphWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::StatgenGraphWindow)
{
  ui->setupUi(this);
}

StatgenGraphWindow::~StatgenGraphWindow()
{
  delete ui;
}
