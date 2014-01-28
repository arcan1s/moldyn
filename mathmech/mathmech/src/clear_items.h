/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
#ifndef CLEAR_ITEMS_H
#define CLEAR_ITEMS_H

#include <QWidget>

class MainWindow;

class Clear_items : public QWidget
{
  Q_OBJECT
public:
  explicit Clear_items(MainWindow *wid = 0);
  void clear_trj();
  void clear_statgen();
  void clear_envir();
  void clear_radf();
  void clear_pdb();
  
signals:
  
public slots:

private slots:

private:
  MainWindow *parent;
};

#endif /* CLEAR_ITEMS_H */
