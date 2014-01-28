/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file errorwindow.h
 * Header of mathmech
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#ifndef ERRORWINDOW_H
#define ERRORWINDOW_H

#include <QMainWindow>

namespace Ui {
  class ErrorWindow;
}

class ErrorWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit ErrorWindow(QWidget *parent = 0);
  ~ErrorWindow();
  void set_message(int mess);
  
private:
  Ui::ErrorWindow *ui;
};

#endif /* ERRORWINDOW_H */
