/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
#ifndef STATGENGRAPHWINDOW_H
#define STATGENGRAPHWINDOW_H

#include <QMainWindow>
#include <qwt_plot.h>

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
