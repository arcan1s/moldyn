#ifndef STATGENGRAPHWINDOW_H
#define STATGENGRAPHWINDOW_H

#include <QMainWindow>

namespace Ui {
  class StatgenGraphWindow;
}

class StatgenGraphWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit StatgenGraphWindow(QWidget *parent = 0);
  ~StatgenGraphWindow();
  
private:
  Ui::StatgenGraphWindow *ui;
};

#endif /* STATGENGRAPHWINDOW_H */
