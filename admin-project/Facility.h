#ifndef FACILITY_H
#define FACILITY_H

#include <QObject>
#include <QString>

class Facility : public QObject {
    Q_OBJECT
protected:
    QString m_name;
    int m_defaultMinutes = 0;
    bool m_available = true;    // 기본적으로 시설은 사용 가능 상태
public:
    // 생성자
    explicit Facility(const QString& name, int defaultMinutes, QObject* parent=nullptr)
        : QObject(parent), m_name(name), m_defaultMinutes(defaultMinutes) {}
    // 소멸자
    virtual ~Facility() = default;

    // 타이머 관련 (자식 구현)
    virtual void startTimer() = 0;
    virtual void stopTimer() = 0;
    virtual void resetTimer() = 0;
    virtual void setManualTime(int minutes) { Q_UNUSED(minutes); }

    // 시설 이용 가능 불가능
    virtual void setAvailable()   { if (!m_available) { m_available = true;  emit availableChanged(true);  } }
    virtual void setUnavailable() { if (m_available)  { m_available = false; emit availableChanged(false); } }

    QString getName() const { return m_name; }
    int getDefaultMinutes() const { return m_defaultMinutes; }
    bool getIsAvailable() const { return m_available; }

signals:
    // 시간은 MM:SS 혹은 HH:MM:SS 형식으로 출력
    void timeUpdated(const QString& formatted);

    // 00:00 도달 시 호출
    void timeout();

    // 시설 상태 변경 알림
    void availableChanged(bool available);

};

#endif // FACILITY_H
