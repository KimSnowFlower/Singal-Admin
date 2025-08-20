#ifndef SIMEPLEFACILITYVIEWADAPTER_H
#define SIMEPLEFACILITYVIEWADAPTER_H

#include "IFacilityView.h"

class SimpleFacilityViewAdapter : public IFacilityView {
private:
    QLabel* t; QPushButton* s; QPushButton* p; QPushButton* r;
    QLineEdit* mi; QPushButton* ms; QPushButton* a; QPushButton* u;

public:
    SimpleFacilityViewAdapter(QLabel* time,
                              QPushButton* start, QPushButton* stop, QPushButton* reset,
                              QLineEdit* manualInput, QPushButton* manualStart,
                              QPushButton* avail, QPushButton* unavail)
        : t(time), s(start), p(stop), r(reset),
        mi(manualInput), ms(manualStart), a(avail), u(unavail) {}

    QLabel* timeLabel() override { return t; }
    QPushButton* startBtn() override { return s; }
    QPushButton* stopBtn() override { return p; }
    QPushButton* resetBtn() override { return r; }
    QLineEdit*   manualInput() override { return mi; }
    QPushButton* manualStartBtn() override { return ms; }
    QPushButton* availableBtn() override { return a; }
    QPushButton* unavailableBtn() override { return u; }
};

#endif // SIMEPLEFACILITYVIEWADAPTER_H
