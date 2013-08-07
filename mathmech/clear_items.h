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

private:
  MainWindow *parent;
};

#endif /* CLEAR_ITEMS_H */
