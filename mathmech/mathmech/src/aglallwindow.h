/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file aglallwindow.h
 * Header of mathmech
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#ifndef AGLALLWINDOW_H
#define AGLALLWINDOW_H

#include <QMainWindow>

class ErrorWindow;

namespace Ui {
  class AglAllWindow;
}

class AglAllWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit AglAllWindow(QWidget *parent = 0, QString mm_agl_path = "");
  ~AglAllWindow();
  
private slots:
  void on_aglall_pushButton_clear_clicked();
  void on_aglall_pushButton_workDir_clicked();
  void on_pdb_pushButton_input_clicked();
  void on_aglall_pushButton_output_clicked();
  void on_aglall_pushButton_start_clicked();

private:
  Ui::AglAllWindow *ui;
  ErrorWindow *errorwin;
  QString _mm_agl_path;

  void start_agl();
  void start_agl_event(QString aglfile, QString trjfile,
                       QString cellsize, QString out_file);
// ESC pressed event
  void keyPressEvent(QKeyEvent *pressedKey);
};

#endif /* AGLALLWINDOW_H */
