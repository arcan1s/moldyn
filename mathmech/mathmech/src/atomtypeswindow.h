/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file atomtypeswindow.h
 * Header of mathmech
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#ifndef ATOMTYPESWINDOW_H
#define ATOMTYPESWINDOW_H

#include <QMainWindow>

class ErrorWindow;

namespace Ui {
  class AtomTypesWindow;
}

class AtomTypesWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit AtomTypesWindow(QWidget *parent = 0);
  ~AtomTypesWindow();
  
private slots:
// events
  void on_atomTypes_pushButton_output_clicked();
  void on_atomTypes_pushButton_add_clicked();
  void on_atomTypes_pushButton_typeRem_clicked();
  void on_atomTypes_pushButton_clear_clicked();
  void on_atomTypes_spinBox_numOfMol_editingFinished();
  void on_atomTypes_comboBox_mol_currentIndexChanged(int index);
  void on_atomTypes_pushButton_create_clicked();

private:
  Ui::AtomTypesWindow *ui;
  ErrorWindow *errorwin;
  int *num_of_mol;
  QStringList atomTypes;

// ESC pressed event
  void keyPressEvent(QKeyEvent *pressedKey);
};

#endif /* ATOMTYPESWINDOW_H */
