#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>

class TimerWidget : public QWidget {
    Q_OBJECT
private:
    int defaultMinutes;
    QTimer* timer;
    QTime remainingTime;

    void setTimeInternal(int totalMinutes);
    QString formatTime(const QTime& time);
private slots:
    void updateTimer();

public:
    explicit TimerWidget(int defaultMinutes, QWidget* parent=nullptr);

    void start();
    void stop();
    void reset();
    void setTime(int minutes);
    QTime getRemainingTime() const;

signals:
    void timeUpdated(const QString& formatted);
    void timeOut();
};

#endif // TIMERWIDGET_H
