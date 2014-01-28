/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file aboutwindow.h
 * Header of mathmech
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QMainWindow>

namespace Ui {
  class AboutWindow;
}

class AboutWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit AboutWindow(QWidget *parent = 0);
  ~AboutWindow();
  
private:
  Ui::AboutWindow *ui;

// ESC pressed event
  void keyPressEvent(QKeyEvent *pressedKey);
};

#endif /* ABOUTWINDOW_H */
