#ifndef AGLALLWINDOW_H
#define AGLALLWINDOW_H

#include <QMainWindow>

namespace Ui {
  class AglAllWindow;
}

class AglAllWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit AglAllWindow(QWidget *parent = 0);
  ~AglAllWindow();
  
private:
  Ui::AglAllWindow *ui;
};

#endif // AGLALLWINDOW_H
