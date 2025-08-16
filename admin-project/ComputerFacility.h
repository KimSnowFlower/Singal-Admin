#ifndef COMPUTERFACILITY_H
#define COMPUTERFACILITY_H

#include "Facility.h"
#include "TimerWidget.h"
#include <QPointer>

class ComputerFacility : public Facility {
    Q_OBJECT
private:
    QPointer<TimerWidget> m_timer;

public:
    // PC는 남은시간 표시만 하고 start/stop 없이 reset(=표시 리셋)만 한다고 가정
    ComputerFacility(const QString& name, int defaultMinutes, QObject* parent=nullptr)
        : Facility(name, defaultMinutes, parent), m_timer(new TimerWidget(defaultMinutes)) {
        connect(m_timer, &TimerWidget::timeUpdated, this, &Facility::timeUpdated);
        connect(m_timer, &TimerWidget::timeOut,     this, &Facility::timeOut);
        m_timer->reset(); // 초기 표시
    }

    void startTimer() override { /* 사용 안함 (아무것도 안하기) */ }
    void stopTimer()  override { /* 사용 안함 */ }
    void resetTimer() override { m_timer->reset(); }

    TimerWidget* timerWidget() const { return m_timer; }
};

#endif // COMPUTERFACILITY_H
