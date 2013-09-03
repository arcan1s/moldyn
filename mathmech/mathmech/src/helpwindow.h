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
