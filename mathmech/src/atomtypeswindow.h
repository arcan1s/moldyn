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
