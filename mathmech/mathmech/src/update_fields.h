/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
#ifndef UPDATE_FIELDS_H
#define UPDATE_FIELDS_H

#include <QWidget>

class MainWindow;

class Update_fields : public QWidget
{
  Q_OBJECT
public:
  explicit Update_fields(MainWindow *wid = 0);
  void setup_def_statgen();
  void setup_def_envir();
  void setup_def_radf();
  void setup_def_pdb();
  
signals:
  
public slots:

private:
  MainWindow *parent;
};

#endif /* UPDATE_FIELDS_H */
