/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file mainwindow.h
 * Header of mathmech
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Clear_items;
class SettingsWindow;
class Start_events;
class Update_fields;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
    
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  QString language;
  QString mm_agl_path;
  QString mm_envir_path;
  QString mm_radf_path;
  QString mm_statgen_path;
  QString mm_trj_path;
  QString mm_trj2pdb_path;
    
private slots:
// enable/disable signals
  void on_trj_checkBox_log_stateChanged (int arg1);
  void on_statgen_checkBox_depth_stateChanged (int arg1);
  void on_statgen_checkBox_log_stateChanged (int arg1);
  void on_statgen_checkBox_atoms1_stateChanged(int arg1);
  void on_statgen_checkBox_atoms2_stateChanged(int arg1);
  void on_statgen_checkBox_atoms3_stateChanged(int arg1);
  void on_statgen_checkBox_anal_stateChanged(int arg1);
  void on_envir_checkBox_log_stateChanged(int arg1);
  void on_radf_comboBox_atom_currentIndexChanged(int index);
  void on_radf_checkBox_ang_stateChanged(int arg1);
  void on_radf_checkBox_log_stateChanged(int arg1);
  void on_pdb_comboBox_mode_currentIndexChanged(int index);
  void on_pdb_checkBox_log_stateChanged(int arg1);
// select directory signals
  void on_trj_pushButton_workDir_clicked();
  void on_trj_pushButton_input_clicked();
  void on_trj_pushButton_atoms_clicked();
  void on_trj_pushButton_output_clicked();
  void on_trj_pushButton_log_clicked();
  void on_statgen_pushButton_workDir_clicked();
  void on_statgen_pushButton_input_clicked();
  void on_statgen_pushButton_output_clicked();
  void on_statgen_pushButton_log_clicked();
  void on_envir_pushButton_workDir_clicked();
  void on_envir_pushButton_input_clicked();
  void on_envir_pushButton_output_clicked();
  void on_envir_pushButton_log_clicked();
  void on_radf_pushButton_workDir_clicked();
  void on_radf_pushButton_input_clicked();
  void on_radf_pushButton_output_clicked();
  void on_radf_pushButton_log_clicked();
  void on_pdb_pushButton_workDir_clicked();
  void on_pdb_pushButton_input_clicked();
  void on_pdb_pushButton_agl_clicked();
  void on_pdb_pushButton_output_clicked();
  void on_pdb_pushButton_log_clicked();
// clear signals
  void on_trj_pushButton_clear_clicked();
  void on_statgen_pushButton_clear_clicked();
  void on_envir_pushButton_clear_clicked();
  void on_radf_pushButton_clear_clicked();
  void on_pdb_pushButton_clear_clicked();
// interaction (statgen)
  void on_statgen_comboBox_int_currentIndexChanged(int index);
  void on_stagen_pushButton_intSave_clicked();
  void on_statgen_doubleSpinBox_int_editingFinished();
  void on_statgen_pushButton_intAdd_clicked();
  void on_stagen_pushButton_intRem_clicked();
// start events
  void on_trj_pushButton_start_clicked();
  void on_statgen_pushButton_start_clicked();
  void on_envir_pushButton_start_clicked();
  void on_radf_pushButton_start_clicked();
  void on_pdb_pushButton_start_clicked();
// completion
  void on_tabWidget_currentChanged(int index);
// window signals
  void aboutWin();
  void aglallWinShow();
  void createAgglFile();
  void createAtomTypes();
  void settingsWinShow();
  void helpWindow();

private:
  Ui::MainWindow *ui;
  void update_interaction();
  float *statgen_crit;

  void start_events_trj();
  void start_events_statgen();
  void start_events_envir();
  void start_events_radf();
  void start_events_pdb();

  Clear_items *clear_items;
  friend class Clear_items;
  Update_fields *update_fields;
  friend class Update_fields;
  Start_events *start_events;

// window signals
  void createActions();
};

#endif /* MAINWINDOW_H */
