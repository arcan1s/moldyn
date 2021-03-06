/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file errorwindow.cpp
 * Source code of mathmech
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

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

void ErrorWindow::set_message(int mess)
{
  QString message;
  switch(mess)
  {
    case 0:
      message = QApplication::translate("ErrorWindow", "Work directory does not exists");
      break;
    case 1:
      message = QApplication::translate("ErrorWindow", "Input file is not set");
      break;
    case 2:
      message = QApplication::translate("ErrorWindow", "Atoms in plane must be different");
      break;
    case 3:
      message = QApplication::translate("ErrorWindow", "Atom types file is not set");
      break;
    case 4:
      message = QApplication::translate("ErrorWindow", "Output file is not set");
      break;
    case 5:
      message = QApplication::translate("ErrorWindow", "Atom type must contain 2 characters");
      break;
    case 6:
      message = QApplication::translate("ErrorWindow", "Log file is not set");
      break;
    case 7:
      message = QApplication::translate("ErrorWindow", "Component is not found");
      break;
    case 8:
      message = QApplication::translate("ErrorWindow", "Atom types is not set");
      break;
    case 9:
      message = QApplication::translate("ErrorWindow", "Something wrong");
      break;
    case 10:
      message = QApplication::translate("ErrorWindow", "Interactions are not set");
      break;
    case 11:
      message = QApplication::translate("ErrorWindow", "Invalid file type");
      break;
    case 12:
      message = QApplication::translate("ErrorWindow", "Interaction step is not set");
      break;
    default:
      message = QApplication::translate("ErrorWindow", "Unknown error");
      break;
  }

  ui->label->setText(message);
}
