#include "widget.h"
#include "ui_widget.h"
#include "signaldata.h"

#include <cmath>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    d(-7, 8)
{
    ui->setupUi(this);

    d_plot = new Plot( this );
    d_plot->setIntervalLength( 100 * 1); // sec

    QHBoxLayout *layout = new QHBoxLayout( this );
    layout->addWidget( d_plot, 10 );
    this->setLayout(layout);

    timer = new QTimer();
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerHandler()));
    timer->start();
    d_plot->start();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerHandler()
{
    static double elapsed = 0.0;

#if 0
    // square wave
    double square_wave[] = {0, 1.57078};
    static int index = 0;

    if(index == 0)
    {
        index = 1;
        const QPointF s( elapsed, 0 );
        const QPointF s1(elapsed, 1);
        SignalData::instance().append( s );
        SignalData::instance().append( s1 );
    }
    else
    {
        index = 0;
        const QPointF s( elapsed, 1 );
        const QPointF s1(elapsed, 0 );
        SignalData::instance().append( s );
        SignalData::instance().append( s1 );
    }

#else

    //double angle = (int(elapsed) % 360) * M_PI/180.0;
    //const QPointF s( elapsed, sin(angle) );
    //const QPointF s( elapsed, d(e) );
    double value = (int(elapsed) % 10);
    const QPointF s( elapsed, value );
    SignalData::instance().append( s );

#endif

    elapsed += 1.0;

    if ( elapsed > d_plot->d_interval.maxValue() )
        d_plot->incrementInterval();
}

int Widget::signFunc(double angle)
{
    if(angle < 0.0)
        return -1;
    else if(angle > 0.0)
        return 1;
    else
        return 0;

}
