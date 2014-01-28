/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QMainWindow>

class ErrorWindow;

namespace Ui {
  class HelpWindow;
}

class HelpWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit HelpWindow(QWidget *parent = 0);
  ~HelpWindow();

private slots:
  void on_pushButton_save_clicked();

private:
  Ui::HelpWindow *ui;
  ErrorWindow *errorwin;

// ESC pressed event
  void keyPressEvent(QKeyEvent *pressedKey);
};

#endif /* HELPWINDOW_H */
