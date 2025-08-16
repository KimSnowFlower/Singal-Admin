#ifndef SIMPLEFACILITY_H
#define SIMPLEFACILITY_H

#include "Facility.h"
#include "TimerWidget.h"
#include <QPointer>

class SimpleFacility : public Facility {
    Q_OBJECT
private:
    QPointer<TimerWidget> m_timer;

public:
    SimpleFacility(const QString& name, int defaultMinutes, QObject* parent=nullptr)
        : Facility(name, defaultMinutes, parent), m_timer(new TimerWidget(defaultMinutes)) {
        // TimerWidget → Facility 시그널 중계
        connect(m_timer, &TimerWidget::timeUpdated, this, &Facility::timeUpdated);
        connect(m_timer, &TimerWidget::timeOut,     this, &Facility::timeOut);
    }

    void startTimer() override { if(m_available) m_timer->start(); }
    void stopTimer()  override { m_timer->stop(); }
    void resetTimer() override { m_timer->reset(); }
    void setManualTime(int minutes) override {
        if (minutes<=0 || minutes>(23*60+59)) return; // QTime 한계
        m_timer->setTime(minutes);
        if (m_available) m_timer->start();
    }

    // 필요시 외부 라벨/버튼 없이도 사용할 수 있도록 TimerWidget 노출(선택)
    TimerWidget* timerWidget() const { return m_timer; }
};

#endif // SIMPLEFACILITY_H
