/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file settingswindow.h
 * Header of mathmech
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

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
  void on_settings_comboBox_lang_currentIndexChanged(int index);

private:
  Ui::SettingsWindow *ui;
  QString configpath;
  MainWindow *_parent;
  ErrorWindow *errorwin;

// ESC pressed event
  void keyPressEvent(QKeyEvent *pressedKey);
};

#endif /* SETTINGSWINDOW_H */
