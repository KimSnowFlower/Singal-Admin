#ifndef IFACILITYVIEW_H
#define IFACILITYVIEW_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class IFacilityView {
public:
    virtual ~IFacilityView() = default;

    // 표시
    virtual QLabel* timeLabel() = 0;

    // 제어 (해당 ui가 없는 경우 nullptr 반환)
    virtual QPushButton* startBtn()       { return nullptr; }
    virtual QPushButton* stopBtn()        { return nullptr; }
    virtual QPushButton* resetBtn()       { return nullptr; }
    virtual QLineEdit* manualInput()      { return nullptr; }
    virtual QPushButton* manualStartBtn() { return nullptr; }
    virtual QPushButton* availableBtn()   { return nullptr; }
    virtual QPushButton* unavailableBtn() { return nullptr; }
};

#endif // IFACILITYVIEW_H
