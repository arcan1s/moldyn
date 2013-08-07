#include "errorwindow.h"
#include "ui_errorwindow.h"

ErrorWindow::ErrorWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::ErrorWindow)
{
  ui->setupUi(this);
}

ErrorWindow::~ErrorWindow()
{
  delete ui;
}

void ErrorWindow::set_message(QString language, int mess)
{
  QString message;
  if (language == QString("eng"))
  {
    switch(mess)
    {
      case 0:
        message = QString("Work directory does not exists");
        break;
      case 1:
        message = QString("Input file does not exists");
        break;
      case 2:
        message = QString("Number of steps is not set");
        break;
      case 3:
        message = QString("Atom types file does not exists");
        break;
      case 4:
        message = QString("Output file is not set");
        break;
      case 5:
        message = QString("Number of total types is not set");
        break;
      case 6:
        message = QString("Log file is not set");
        break;
      case 7:
        message = QString("Component is not found");
        break;
      case 8:
        message = QString("Cell size is not set");
        break;
      case 9:
        message = QString("Atom types are not set");
        break;
      case 10:
        message = QString ("Interactions are not set");
        break;
      case 11:
        message = QString ("Depth is not set");
        break;
    }
  }

  ui->label->setText(message);
}
