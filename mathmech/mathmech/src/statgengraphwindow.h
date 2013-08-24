#ifndef STATGENGRAPHWINDOW_H
#define STATGENGRAPHWINDOW_H

#include <QMainWindow>
#include <qwt/qwt_plot.h>

namespace Ui {
  class StatgenGraphWindow;
}

class StatgenGraphWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit StatgenGraphWindow(QWidget *parent = 0, QString inputfile = "");
  ~StatgenGraphWindow();
  void paintGraph();
  void readData();

private slots:
  void on_graph_pushButton_save_clicked();

private:
  Ui::StatgenGraphWindow *ui;
  QwtPlot *plot;
  QVector<double> x_axis;
  QVector<double> p_points;
  QVector<double> pn_points;
  int type;
  QString _inputfile;

  void keyPressEvent(QKeyEvent *pressedKey);
};

#endif /* STATGENGRAPHWINDOW_H */