#include "TimerWidget.h"

TimerWidget::TimerWidget(int defaultMinutes, QWidget* parent)
    : QWidget(parent), defaultMinutes(defaultMinutes), timer(new QTimer(this)), remainingTime(0,0,0) {
    timer->setInterval(1000);
    connect(timer, &QTimer::timeout, this, &TimerWidget::updateTimer);
    setTimeInternal(defaultMinutes);
}

void TimerWidget::start() {
    if(remainingTime!=QTime(0,0,0) && !timer->isActive())
        timer->start();
}

void TimerWidget::stop() {
    if(timer->isActive())
        timer->stop();
}

void TimerWidget::reset() {
    stop();
    setTimeInternal(defaultMinutes);
}

void TimerWidget::setTime(int minutes) {
    if(minutes<0)
        minutes=0;

    stop();
    setTimeInternal(minutes);
}

QTime TimerWidget::getRemainingTime() const {
    return remainingTime;
}

void TimerWidget::updateTimer() {
    if(remainingTime==QTime(0,0,0)) {
        stop();
        emit timeOut();
        return;
    }
}

void TimerWidget::setTimeInternal(int totalMinutes) {
    if(totalMinutes<0)
        totalMinutes = 0;

    int h = totalMinutes/60;
    int m = totalMinutes%60;

    if(h>23) {
        h = 23;
        m = 59;
    }

    remainingTime.setHMS(h, m, 0);

    emit timeUpdated(formatTime(remainingTime));
}

QString TimerWidget::formatTime(const QTime& t) {
    return t.hour() > 0 ? t.toString("hh:mm:ss") : t.toString("mm:ss");
}
