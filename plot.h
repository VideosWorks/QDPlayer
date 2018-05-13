#ifndef _PLOT_H_
#define _PLOT_H_

#include <qwt_plot.h>
#include <QDateTime>
#include <player.h>
#include <qwt_plot_curve.h>
class Settings;
class Player;

class Plot: public QwtPlot
{
    Q_OBJECT


public:
    Plot( QWidget *parent = NULL );
    QwtPlotCurve   Carve;
    QwtPlotCurve   Carve1;
    QwtPlotCurve   Curve1;
    QwtPlotCurve  Curve2;
    QwtPlotCurve  Curve3;
    QwtPlotCurve  Curve4;

    QwtPlotCurve  rec_curve1;
    QwtPlotCurve  rec_curve2;
    QwtPlotCurve  rec_curve3;
    QwtPlotCurve  rec_curve4;
    void set_player(Player *p);
    int curve_status=0;
    void   Stick(QDateTime datetime1);
    void   Stick1(QDateTime datetime1);


public Q_SLOTS:
    void applySettings(QDate date);
    void paint(QDateTime date1,QDateTime date2,int point,int camera);
    void  first_paint(QDateTime date1,QDateTime date2,int point);
    void mousePressEvent(QMouseEvent* event);
    void  wheelEvent(QWheelEvent *event);
    QDateTime  convertdate(QDate date,int value);

private:
    void initAxis( int axis, const QString& title, Qt::TimeSpec );
    void applyAxisSettings( int axis,QDate date);
    Player *player;


    //protected:
    // virtual void  wheelEvent(QWheelEvent *event);
};

#endif
