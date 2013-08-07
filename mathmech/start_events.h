#ifndef START_EVENTS_H
#define START_EVENTS_H

#include <QWidget>

class MainWindow;
class ErrorWindow;

class Start_events : public QWidget
{
  Q_OBJECT
public:
  explicit Start_events(MainWindow *wid = 0);
  void start_trj(QString mm_trj_path);
  void start_statgen(QString mm_statgen_path);
  void start_envir(QString mm_envir_path);
  void start_radf(QString mm_radf_path);
  void start_pdb(QString mm_pdb_path);
  
signals:
  
public slots:

private slots:

private:
  MainWindow *parent;
  ErrorWindow *errorwin;
};

#endif /* START_EVENTS_H */
