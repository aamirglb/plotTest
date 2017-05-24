#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "plot.h"

#include <random>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void timerHandler();
    int signFunc(double angle);
private:
    Ui::Widget *ui;

    Plot *d_plot;

    QTimer *timer;

    std::default_random_engine e;
    std::uniform_int_distribution<int> d;
};

#endif // WIDGET_H
