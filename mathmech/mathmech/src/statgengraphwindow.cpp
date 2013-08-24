#include <QDir>
#include <QFileDialog>
#include <QKeyEvent>
#include <QTextStream>

#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_series_data.h>

#include "statgengraphwindow.h"
#include "ui_statgengraphwindow.h"

StatgenGraphWindow::StatgenGraphWindow(QWidget *parent, QString inputfile) :
  QMainWindow(parent),
  ui(new Ui::StatgenGraphWindow)
{
  ui->setupUi(this);

  _inputfile = inputfile;

  readData();
  paintGraph();
}

StatgenGraphWindow::~StatgenGraphWindow()
{
  delete ui;
}

// ESC press event
void StatgenGraphWindow::keyPressEvent(QKeyEvent *pressedKey)
{
  if (pressedKey->key() == Qt::Key_Escape)
    close();
}

void StatgenGraphWindow::paintGraph()
{
  plot = new QwtPlot(ui->centralwidget);
  plot->setMinimumSize(QSize(322, 280));
  ui->verticalLayout->addWidget(plot);

  plot->setFont(QFont("Times New Roman", 8, QFont::Bold));
  plot->setAxisFont(QwtPlot::xBottom, QFont("Times New Roman", 8, QFont::Bold));
  plot->setAxisFont(QwtPlot::yLeft, QFont("Times New Roman", 8, QFont::Bold));
  plot->setAxisAutoScale(QwtPlot::xBottom, true);
  plot->setAxisAutoScale(QwtPlot::yLeft, true);
  plot->setAutoReplot(true);

  QPen pen;
  switch (type)
  {
    case 0:
      plot->setAxisTitle(QwtPlot::xBottom, trUtf8("N"));
      plot->setAxisTitle(QwtPlot::yLeft, trUtf8("p"));

      pen = QPen(QColor(0,0,0));
      QwtPlotCurve *p_curve;
      p_curve = new QwtPlotCurve(QString("p"));
      p_curve->setPen(pen);
      p_curve->attach(plot);
      p_curve->setSamples(x_axis, p_points);

      QwtPlotCurve *pn_curve;
      pen = QPen(QColor(255,0,0));
      pn_curve = new QwtPlotCurve(QString("pn"));
      pn_curve->setPen(pen);
      pn_curve->attach(plot);
      pn_curve->setSamples(x_axis, pn_points);
      break;
    case 1:
      plot->setAxisTitle(QwtPlot::xBottom, trUtf8("r"));
      plot->setAxisTitle(QwtPlot::yLeft, trUtf8("g"));

      pen = QPen(QColor(0,0,0));
      QwtPlotCurve *radf_curve;
      radf_curve = new QwtPlotCurve(QString("RDF"));
      radf_curve->setPen(pen);
      radf_curve->attach(plot);
      radf_curve->setSamples(x_axis, p_points);
      break;
  }
  plot->replot();
}

void StatgenGraphWindow::readData()
{
  QString tmp_str;
  QFile inp_file(_inputfile);
  inp_file.open(QIODevice::ReadOnly);
  tmp_str = QString(inp_file.readLine());
  int matrix=0;
  if (tmp_str.contains(QString("statgen")))
    type = 0;
  else if (tmp_str.contains(QString("radf")))
    type = 1;
  while (!tmp_str.contains(QString("SUMMARY STATISTIC")))
  {
    tmp_str = QString(inp_file.readLine());
    if ((type == 1) && (tmp_str.contains(QString("MATRIX="))))
      matrix = tmp_str.split(QString("MATRIX="), QString::SkipEmptyParts)[0].toInt();
  }
  if (matrix == 0)
  {
    tmp_str = QString(inp_file.readLine());
    tmp_str = QString(inp_file.readLine());
  }

  switch(type)
  {
    case 0:
      tmp_str = QString(inp_file.readLine());
      while (!tmp_str.contains(QString("---")))
      {
        x_axis.append(tmp_str.split(QString(" "), QString::SkipEmptyParts)[0].toDouble());
        p_points.append(tmp_str.split(QString(" "), QString::SkipEmptyParts)[3].toDouble());
        pn_points.append(tmp_str.split(QString(" "), QString::SkipEmptyParts)[4].toDouble());
        tmp_str = QString(inp_file.readLine());
      }
      break;
    case 1:
      tmp_str = QString(inp_file.readLine());
      while (!tmp_str.contains(QString("---")))
      {
        x_axis.append(tmp_str.split(QString(" "), QString::SkipEmptyParts)[0].toDouble());
        switch(matrix)
        {
          case 0:
            p_points.append(tmp_str.split(QString(" "), QString::SkipEmptyParts)[3].toDouble());
            break;
          case 1:
            p_points.append(tmp_str.split(QString(" "), QString::SkipEmptyParts)[1].toDouble());
            break;
        }
        tmp_str = QString(inp_file.readLine());
      }
      break;
  }
  inp_file.close();
}

void StatgenGraphWindow::on_graph_pushButton_save_clicked()
{
  QPixmap qPix = QPixmap::grabWidget(plot);
  QString filename = QFileDialog::getSaveFileName(
                     this,
                     tr("Save image as..."),
                     QDir::currentPath(),
                     tr("JPEG file (*.jpeg);;Portable Network Graphics file (*.png);;Bitmap file (*.bmp)"));
  if (!filename.isEmpty())
  {
    if (filename.contains(QRegExp("jpeg")))
      qPix.save(filename, "JPEG");
    else if (filename.contains(QRegExp("png")))
      qPix.save(filename, "PNG");
    else if (filename.contains(QRegExp("bmp")))
      qPix.save(filename, "BMP");
  }
}
