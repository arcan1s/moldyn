#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QMainWindow>

namespace Ui {
  class HelpWindow;
}

class HelpWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit HelpWindow(QWidget *parent = 0);
  ~HelpWindow();

private:
  Ui::HelpWindow *ui;

// ESC pressed event
  void keyPressEvent(QKeyEvent *pressedKey);
};

#endif /* HELPWINDOW_H */
