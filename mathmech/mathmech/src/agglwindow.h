/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
#ifndef AGGLWINDOW_H
#define AGGLWINDOW_H

#include <QMainWindow>

class ErrorWindow;

namespace Ui {
  class AgglWindow;
}

class AgglWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit AgglWindow(QWidget *parent = 0, QString inputfile = "");
  ~AgglWindow();
  
private slots:
// events
  void on_agl_pushButton_input_clicked();
  void on_pushButton_clicked();
  void on_agl_comboBox_currentIndexChanged(int index);
  void on_agl_listWidget_itemActivated();
  void on_agl_pushButton_output_clicked();
  void on_agl_pushButton_clear_clicked();
  void on_agl_pushButton_create_clicked();

private:
  Ui::AgglWindow *ui;
  ErrorWindow *errorwin;
  QStringList inp_file;
  QStringList aggl;
  QStringList aggl_mol;

// ESC pressed event
  void keyPressEvent(QKeyEvent *pressedKey);
};

#endif /* AGGLWINDOW_H */
