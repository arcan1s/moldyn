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
  bool start_trj(QString mm_trj_path,
                 QString workDir,
                 QString input,
                 QString type,
                 QString steps,
                 QString atomType,
                 QString mask,
                 QString totalTypes,
                 QString log);
  bool start_statgen(QString mm_statgen_path,
                     QString workDir,
                     QString mask,
                     QString firstStep,
                     QString lastStep,
                     QString cellX, QString cellY, QString cellZ,
                     QString atom0, QString atom1, QString atom2, QString atom3,
                     QString inter,
                     QString output,
                     QString depth,
                     QString log);
  bool start_statgen_analysis(QString mm_statgen_path,
                              QString workDir,
                              QString mask,
                              QString firstStep,
                              QString lastStep,
                              QString cellX, QString cellY, QString cellZ,
                              QString atom0, QString atom1, QString atom2, QString atom3,
                              QString inter,
                              QString output,
                              QString depth,
                              QString log,
                              float int_step, int imax);
  bool start_envir(QString mm_envir_path,
                   QString workDir,
                   QString input,
                   QString cellX, QString cellY, QString cellZ,
                   QString output,
                   QString molecule,
                   QString radius,
                   QString log);
  bool start_radf(QString mm_radf_path,
                  QString workDir,
                  QString mask,
                  QString firstStep,
                  QString lastStep,
                  QString cellX, QString cellY, QString cellZ,
                  QString output,
                  QString atom0, QString atom1, QString atom2,
                  QString atom3, QString atom4, QString atom5,
                  QString radMin, QString radMax, QString radStep,
                  QString angMin, QString angMax, QString angStep,
                  QString log, int matrix);
  bool start_pdb(QString mm_pdb_path,
                 QString workDir,
                 QString input,
                 QString agl,
                 QString cellX, QString cellY, QString cellZ,
                 QString output,
                 QString log);
  
signals:
  
public slots:

private slots:

private:
  MainWindow *parent;
  ErrorWindow *errorwin;
};

#endif /* START_EVENTS_H */
