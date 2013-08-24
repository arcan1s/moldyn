#include "mainwindow.h"
#include <QApplication>
#include <QLocale>

int main(int argc, char *argv[])
{
  QLocale::setDefault(QLocale::C);

  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();
}
