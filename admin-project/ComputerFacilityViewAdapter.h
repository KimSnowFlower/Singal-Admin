#ifndef COMPUTERFACILITYVIEWADAPTER_H
#define COMPUTERFACILITYVIEWADAPTER_H

#include "IFacilityView.h"

class ComputerFacilityViewAdapter : public IFacilityView {
private:
    QLabel* t; QPushButton* r; QPushButton* a; QPushButton* u;

public:
    ComputerFacilityViewAdapter(QLabel* time,
                                QPushButton* reset,
                                QPushButton* avail, QPushButton* unavail)
        : t(time), r(reset), a(avail), u(unavail) {}

    QLabel* timeLabel() override { return t; }
    QPushButton* resetBtn() override { return r; }
    QPushButton* availableBtn() override { return a; }
    QPushButton* unavailableBtn() override { return u; }
};

#endif // COMPUTERFACILITYVIEWADAPTER_H
