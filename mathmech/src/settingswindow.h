#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QMainWindow>

class MainWindow;
class ErrorWindow;

namespace Ui {
  class SettingsWindow;
}

class SettingsWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit SettingsWindow(MainWindow *parent = 0);
  ~SettingsWindow();
  void applySettings();
  void printSettings();
  void readSettings();
  void setDefaults();
  void showSettings();
  
private slots:
  void on_settings_pushButton_save_clicked();
  void on_settings_pushButton_trj_clicked();
  void on_settings_pushButton_statgen_clicked();
  void on_settings_pushButton_envir_clicked();
  void on_settings_pushButton_radf_clicked();
  void on_settings_pushButton_trj2pdb_clicked();
  void on_settings_pushButton_agl_clicked();

private:
  Ui::SettingsWindow *ui;
  QString configpath;
  MainWindow *_parent;
  ErrorWindow *errorwin;

// ESC pressed event
  void keyPressEvent(QKeyEvent *pressedKey);
};

#endif /* SETTINGSWINDOW_H */
