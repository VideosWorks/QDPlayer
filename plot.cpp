#include "plot.h"
#include "settings.h"
#include <qwt_date.h>
#include <qwt_date_scale_draw.h>
#include <qwt_date_scale_engine.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_layout.h>
#include <qwt_plot_picker.h>
#include<QDateTime>
#include <qwt_legend.h>
#include <qwt_plot_tradingcurve.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_zoneitem.h>
#include <qwt_plot_renderer.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_panner.h>
#include <qwt_legend_label.h>
#include <qwt_date.h>
#include <qwt_date_scale_engine.h>
#include <qwt_date_scale_draw.h>
#include<qwt_plot_curve.h>
#include <player.h>
#include<qwt_plot_renderer.h>
#include <iostream>
#include <qwt_symbol.h>
#include <qwt_picker_machine.h>
using namespace::std;
static int zoomin_cnt;
static int zoomout_cnt;
class TimeScaleDraw: public QwtScaleDraw
{
public:
    TimeScaleDraw(QString fmt):
        format(fmt)
    {
    }
    virtual QwtText label(double v) const
    {

        QDateTime t=QwtDate::toDateTime(v,Qt::UTC);
        return t.toString(format);
    }
private:
    QString format;
};
class  Pan:public QwtPlotPanner
{
public:
    Pan(QWidget  *canvas):QwtPlotPanner(canvas)
    {

    }
    //        virtual void widgetMouseMoveEvent (QMouseEvent *)
    //        {
    //  qDebug()<< QwtPanner::grab();
    //        qDebug()<<canvas()->rect().right();
    //        qDebug()<<canvas()->rect().top();
    //        qDebug()<<canvas()->rect().bottom();
    //        const QwtScaleMap map = this->canvasMap( QwtPlot::xBottom );
    //        qDebug() << "<<<<<<<<<<<<<<<<<";
    //        qDebug() << "Left (p): " << d->plot->canvas()->rect().left();
    //        qDebug() << "Right (p): " << d->plot->canvas()->rect().width();
    //        qDebug() << "Left : " << d->plot->invTransform(QwtPlot::xBottom, 0);
    //        qDebug() << "Right: " << d->plot->invTransform(QwtPlot::xBottom, d->plot->canvas()->rect().width());
    //        qDebug() << "dx (p): " << dx;
    //        qDebug() << "dx : " << d->plot->invTransform(QwtPlot::xBottom, fabs(dx));
    //  qDebug()<<"gayar";
    //}
    //        virtual void moveCanvas (int dx, int dy)
    //        {
    //            qDebug()<<"gayar          dx     "<<  dx   <<"    dy "<< dy;
    //         canvas()->move(dx,dy);
    //        }
    //      void panned(int dx, int dy)
    //    {
    //        qDebug()<<"gayar          dx     "<<  dx   <<"    dy "<< dy;
    //    }

};
class mag:public QwtPlotMagnifier
{
public :
    mag(QWidget *canvas):
        QwtPlotMagnifier(canvas)
    {
    }
    virtual void rescale(double factor)
    {
        qDebug()<<" fak   : "   <<factor;
        if(factor==0.9)
        {
            if(zoomout_cnt<50)
            {
                zoomout_cnt=zoomout_cnt+1;
                QwtPlotMagnifier::rescale(factor);
            }
        }
        if(factor==1.1111111111111112)
        {
            if(zoomout_cnt>0)
            {
                zoomout_cnt--;
                QwtPlotMagnifier::rescale(factor);
            }
        }
    }
};
class MyZoomer: public QwtPlotPicker
{
public:
    MyZoomer( QWidget *canvas ):
        QwtPlotPicker( canvas )
    {
        setTrackerMode( QwtPlotPicker::AlwaysOn );
        setRubberBandPen(QColor(Qt::darkGreen));
        setRubberBand( VLineRubberBand );
        setStateMachine( new QwtPickerTrackerMachine() );
    }
protected:
    virtual QwtText trackerTextF( const QPointF &pos ) const
    {
        const QDateTime dt = QwtDate::toDateTime( pos.x() );
        //      QString dt= QDateTime::fromTime_t(pos.x()).toUTC().toString("yyyy MMM dd hh:mm:ss:zz");
        QString s;
        s += QwtDate::toString( QwtDate::toDateTime( pos.x() ),
                                "yyyy MMM dd hh:mm:ss ", QwtDate::FirstDay);
        QwtText text( s );
        text.setColor( Qt::white );
        QColor c = rubberBandPen().color();
        text.setBorderPen( QPen( c ) );
        text.setBorderRadius( 6 );
        c.setAlpha( 170 );
        text.setBackgroundBrush( c );
        return text;
    }
};
double current_x;
static double current_space=600000;


Plot::Plot( QWidget *parent ):
    QwtPlot( parent )
{
    qDebug()<<"canvas border :  "<<canvas()->backingStore();
    zoomout_cnt=0;
    Carve.setStyle(QwtPlotCurve::Lines);
    Carve.setPen( Qt::white, 2),
            Carve.setRenderHint( QwtPlotItem::RenderAntialiased, true );
    Carve.setBrush(QBrush(QColor(Qt::black),Qt::SolidPattern));
    Carve.setBaseline(1000);
    Carve1.setStyle(QwtPlotCurve::Lines);
    Carve1.setPen( Qt::white, 2),
            Carve1.setRenderHint( QwtPlotItem::RenderAntialiased, true );
    Carve1.setBrush(QBrush(QColor(Qt::black),Qt::SolidPattern));
    Carve1.setBaseline(1000);
    this->setMaximumHeight(180);
    this->setMinimumHeight(180);
    //çercevedeki etikleteri gösterilmesini saglar
    setAutoFillBackground( true);
    //çerceve rengi
    setPalette( Qt::darkGray);
    // iç canvas rengi
    setCanvasBackground( Qt::white);
    zoomin_cnt=0;
    plotLayout()->setAlignCanvasToScales(false );
    initAxis( QwtPlot::xTop, "", Qt::UTC);
    initAxis( QwtPlot::xBottom,  "", Qt::UTC);
    // canvas kaydırılabilir hale getiriliyor
    QwtPlotPanner *panner = new Pan( canvas() );
    //mouse ile zoomlama özelligi ekleniyor
    QwtPlotMagnifier *magnifier  = new mag( canvas() );
    //imlec ile uzak bulma koordinatı verme özelliği
    magnifier ->setMouseButton( Qt::NoButton );   // cok fazla zoom yapınca 1970 tarihine gitmesini engeller
    for ( int axis = 0; axis < QwtPlot::axisCnt; axis++ )
    {
        const bool on = axis == QwtPlot::xBottom||axis == QwtPlot::xTop;
        enableAxis( axis, on );
        panner->setAxisEnabled( axis, on );
        magnifier ->setAxisEnabled( axis, on );
        setAxisAutoScale(axis,true);
    }
    // canvas ızgara özellği ekleniyor    kalın cizgi icin setmajorpen ince cizgiler icin setminorpen
    // x ekseni icin ızgara aktif   y ekseni icin kapatılıyor
    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->setMajorPen( Qt::black, 1, Qt::SolidLine );
    grid->setMinorPen( Qt::gray, 1 , Qt::SolidLine );
    grid->enableX( true );
    grid->enableXMin( true );
    grid->enableY( false);
    grid->enableYMin( false);
    grid->attach( this );
    QwtPlotPicker* zoomer = new MyZoomer( canvas() );
    QDate dt2=QDate::currentDate();
    current_x=QwtDate::toDouble(convertdate(dt2,720));
    Stick(convertdate(dt2,720));
}

void Plot::initAxis( int axis, const QString& title, Qt::TimeSpec timeSpec )
{
    //eksene baslık ekleniyor
    QwtScaleDraw  *scaleDraw =new TimeScaleDraw("hh:mm");
    setAxisLabelRotation( QwtPlot::xBottom, -50.0 );
    QwtDateScaleEngine *scaleEngine = new QwtDateScaleEngine( timeSpec );
#if 0
    if ( timeSpec == Qt::LocalTime )
    {
        scaleDraw->setTimeSpec( Qt::OffsetFromUTC );
        scaleDraw->setUtcOffset( 10 );
        scaleEngine->setTimeSpec( Qt::OffsetFromUTC );
        scaleEngine->setUtcOffset( 10 );
    }
#endif
    setAxisScaleDraw( axis, scaleDraw );
    setAxisScaleEngine( axis, scaleEngine );
    QDate dt1=QDate::currentDate();
    scaleEngine->setMaxWeeks(-1);
    setAxisMaxMinor(axis,0);
    setAxisMaxMajor( axis, 12);
    QDateTime startDate(dt1,QTime(0,0,0),Qt::UTC);
    QDateTime endDate(dt1,QTime(23,59,59),Qt::UTC);
    qDebug( )<< " Start Date : "<< startDate  << "        end date :    "<< endDate;
    QwtPlot::setAxisAutoScale(xTop,false);
    setAxisScale( QwtPlot::xTop, QwtDate::toDouble( startDate ),QwtDate::toDouble( endDate ));
    QwtPlot::setAxisAutoScale(xBottom, false);
    setAxisScale( QwtPlot::xBottom, QwtDate::toDouble( startDate ) ,QwtDate::toDouble( endDate ));
    setAxisScale(QwtPlot::yLeft,0,5);
    QDate dt2=QDate::currentDate();
    first_paint(convertdate(dt2,0),convertdate(dt2,1439),1);
    first_paint(convertdate(dt2,0),convertdate(dt2,1439),2);
    first_paint(convertdate(dt2,0),convertdate(dt2,1439),3);
    first_paint(convertdate(dt2,0),convertdate(dt2,1439),4);
    replot();
}

void Plot::applySettings(QDate date)
{
    applyAxisSettings( QwtPlot::xTop,date);
    applyAxisSettings( QwtPlot::xBottom,date);
    replot();
}

void Plot::applyAxisSettings( int axis,QDate date)
{
    QwtDateScaleEngine *scaleEngine =
            static_cast<QwtDateScaleEngine *>( axisScaleEngine( axis ) );
    scaleEngine->setMaxWeeks(-1);
    setAxisMaxMinor(axis,0);
    setAxisMaxMajor( axis, 13);
    QDateTime startDate(date, QTime(0, 0, 0),Qt::UTC);
    QDateTime endDate(date, QTime(23, 59, 59),Qt::UTC);
    setAxisScale( axis, QwtDate::toDouble( startDate ),
                  QwtDate::toDouble( endDate ));
    qDebug()<<QwtDate::toDouble(startDate);
    qDebug() << QwtDate::toDateTime(1341648221967.9634,Qt::LocalTime);
}

void Plot::paint(QDateTime date1,QDateTime date2,int point,int camera)
{

    double d1=QwtDate::toDouble(date1)+10800000;
    double d2=QwtDate::toDouble(date2)+10800000;

    QwtPlotCurve *curve = new QwtPlotCurve();
    curve->setPaintAttribute(QwtPlotCurve::ClipPolygons, true);
    if(point==1)
    {
        curve->setPen( Qt::blue, 20),
                curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );
    }
    if(point==2)
    {
        curve->setPen( Qt::red, 20),
                curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );
    }
    if(point==3)
    {
        curve->setPen( Qt::yellow, 20),
                curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );
    }
    if(point==4)
    {
        curve->setPen( Qt::green, 20),
                curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );
    }
    QPolygonF points;
    points << QPointF( d1, camera ) << QPointF( d2, camera );
    curve->setSamples( points );

    curve->attach( this);
    replot();

}

void Plot::first_paint(QDateTime date1,QDateTime date2,int point)
{
    current_space=600000;
    zoomout_cnt=0;
    double d1=QwtDate::toDouble(date1);
    current_x=d1;
    zoomout_cnt=0;
    double d2=QwtDate::toDouble(date2);
    QPolygonF points;
    points << QPointF( d1, point ) << QPointF( d2, point );
    if(point==1)
    {
        Curve1.setPen( Qt::lightGray, 20),
                Curve1.setRenderHint( QwtPlotItem::RenderAntialiased, true );
        Curve1.setSamples( points );
        Curve1.attach(this);
    }
    if(point==2)
    {
        Curve2.setPen( Qt::lightGray, 20),
                Curve2.setRenderHint( QwtPlotItem::RenderAntialiased, true );
        Curve2.setSamples( points );
        Curve2.attach(this);
    }
    if(point==3)
    {
        Curve3.setPen( Qt::lightGray, 20),
                Curve3.setRenderHint( QwtPlotItem::RenderAntialiased, true );
        Curve3.setSamples( points );
        Curve3.attach(this);
    }
    if(point==4)
    {
        Curve4.setPen( Qt::lightGray, 20),
                Curve4.setRenderHint( QwtPlotItem::RenderAntialiased, true );
        Curve4.setSamples( points );
        Curve4.attach(this);
    }

    replot();
}

QDateTime Plot::convertdate(QDate date,int value)
{
    QString time_str = QDateTime::fromTime_t(value*60).toUTC().toString("hh:mm");
    QTime time = QTime::fromString(time_str,"hh:mm");
    QDateTime return_date=QDateTime(date,time,Qt::UTC);
    return return_date;
}

void Plot::mousePressEvent(QMouseEvent* event)
{
    double x = this-> invTransform (this -> xBottom, event -> pos().x());
    current_x=x;
    double y = this -> invTransform (this -> yLeft, event -> pos().y());
    QDateTime tm1 = QwtDate::toDateTime(x,Qt::UTC);
    QString hour_and_minute_str=tm1.toString("hh:mm");
    bool ok(false);
    int select_time = hour_and_minute_str.mid(0,2).toInt(&ok)*60+ hour_and_minute_str.mid(3,2).toInt(&ok);
    qDebug()<<x;
    qDebug()<<x-1;
    QPolygonF points1;
    points1 << QPointF( x, 0.5 )<<QPointF(x-current_space,0) <<  QPointF(x+current_space,0)      << QPointF( x, 0.5)
            << QPointF( x, 4.5 )<<QPointF(x-current_space,5) <<  QPointF(x+current_space,5)      << QPointF( x, 4.5);

    if(curve_status==0)
    {
        Carve.setSamples(points1);
        Carve.attach(this);
    }

    if(curve_status==1)
    {
        Carve1.setSamples(points1);
        Carve1.attach(this);
    }
    replot();
    qDebug() << tm1;
    qDebug()<<y;
    if(y>0.60 & y < 1.38)
    {
        qDebug()<< "camera1";
    }
    if(y>1.60 & y < 2.35)
    {
        qDebug()<< "camera2";
    }
    if(y>2.60 & y < 3.40)
    {
        qDebug()<< "camera3";
    }
    if(y>3.60 & y < 4.40)
    {
        qDebug()<< "camera4";
    }
    player->find_basket_id_and_pos(select_time);
}

void Plot::Stick(QDateTime datetime1)
{
    qDebug()<< "current space : "<< current_space;
    double x=QwtDate::toDouble(datetime1);
    QPolygonF points1;
    points1 << QPointF( x, 0.5 )<<QPointF(x-current_space,0) <<  QPointF(x+current_space,0)      << QPointF( x, 0.5)
            << QPointF( x, 4.5 )<<QPointF(x-current_space,5) <<  QPointF(x+current_space,5)      << QPointF( x, 4.5);
    Carve.setSamples(points1);
    Carve.attach(this);
    replot();
}

void Plot::Stick1(QDateTime datetime1)
{
    current_space=600000;
    zoomout_cnt=0;
    curve_status=1;
    double x=QwtDate::toDouble(datetime1);
    QPolygonF points1;
    points1 << QPointF( x, 0.5 )<<QPointF(x-current_space,0) <<  QPointF(x+current_space,0)      << QPointF( x, 0.5)
            << QPointF( x, 4.5 )<<QPointF(x-current_space,5) <<  QPointF(x+current_space,5)      << QPointF( x, 4.5);
    Carve1.setSamples(points1);
    Carve1.attach(this);
    replot();
}

void Plot::wheelEvent(QWheelEvent *event)
{
    qDebug()<< QwtPlot::axisInterval(QwtPlot::xBottom);
    qDebug()<< "first  current space : "<< current_space;
    if(event->delta()>0)
    {
        qDebug()<<"zoom";
        current_space =current_space*1.1 ;
    }
    else
    {
        current_space =current_space/1.1;
    }
    if(current_space>800000)
    {
        current_space =600000;
    }
    if(current_space<3000)
    {
        current_space =3000;
    }
    qDebug()<< "last  current space : "<< current_space;
    QPolygonF points2;
    points2 << QPointF( current_x, 0.5 )<<QPointF(current_x - current_space,0) <<  QPointF(current_x+current_space,0)      << QPointF( current_x, 0.5)
            << QPointF( current_x, 4.5 )<<QPointF(current_x - current_space,5) <<  QPointF(current_x+current_space,5)      << QPointF(current_x, 4.5);
    if(curve_status==0)
    {
        Carve.setSamples(points2);
        Carve.attach(this);
    }
    if(curve_status==1)
    {
        Carve1.setSamples(points2);
        Carve1.attach(this);
    }
    replot();
}

void  Plot::set_player(Player *p)
{
    player = p;
}
