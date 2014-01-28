/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
#include "mainwindow.h"
#include <QApplication>
#include <QDir>
#include <QLocale>
#include <QTextStream>
#include <QTranslator>

int main(int argc, char *argv[])
{
  QLocale::setDefault(QLocale::C);

  QApplication a(argc, argv);
  QString configpath;
#ifdef _WIN32
  configpath = QFileInfo(QDir::currentPath(), ("mathmech.ini")).absoluteFilePath();
#elif __linux
  configpath = QFileInfo(QDir(QDir::homePath() + "/.config"), ("mathmech.conf")).absoluteFilePath();
#else
  return;
#endif
  QFile conf_file(configpath);
  conf_file.open(QIODevice::ReadOnly | QIODevice::Text);
  QString language, text;
  QTextStream out(&conf_file);
  while (!out.atEnd())
  {
    text = out.readLine();
    if (text.contains(QString("LANG=")))
      language = text.split(QString("LANG="), QString::SkipEmptyParts)[0];
  }
  conf_file.close();
  QTranslator translator;
  translator.load(QString(":/translations/") + language);
  a.installTranslator(&translator);

  MainWindow w;
  w.show();
  return a.exec();
}
