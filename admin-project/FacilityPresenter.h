#ifndef FACILITYPRESENTER_H
#define FACILITYPRESENTER_H

#include <QObject>
#include "Facility.h"
#include "IFacilityView.h"

class FacilityPresenter : public QObject {
    Q_OBJECT
private:
    Facility* m;
    IFacilityView* v;

public:
    FacilityPresenter(Facility* model, IFacilityView* view, QObject* parent=nullptr)
        : QObject(parent), m(model), v(view) {
        // 모델 → 뷰
        if (v->timeLabel()) {
            connect(m, &Facility::timeUpdated, v->timeLabel(), &QLabel::setText);
        }
        connect(m, &Facility::availableChanged, this, [this](bool avail){
            if (v->startBtn()) v->startBtn()->setEnabled(avail);
            if (v->manualStartBtn()) v->manualStartBtn()->setEnabled(avail);
        });

        // 뷰 → 모델 (존재하는 컨트롤만 연결)
        if (v->startBtn())  connect(v->startBtn(),  &QPushButton::clicked, m, &Facility::startTimer);
        if (v->stopBtn())   connect(v->stopBtn(),   &QPushButton::clicked, m, &Facility::stopTimer);
        if (v->resetBtn())  connect(v->resetBtn(),  &QPushButton::clicked, m, &Facility::resetTimer);
        if (v->manualStartBtn() && v->manualInput()){
            connect(v->manualStartBtn(), &QPushButton::clicked, this, [this]{
                bool ok=false; int minutes = v->manualInput()->text().toInt(&ok);
                if (ok && minutes>0) m->setManualTime(minutes);
            });
        }
        if (v->availableBtn())
            connect(v->availableBtn(),   &QPushButton::clicked, this, [this]{ m->setAvailable();   });
        if (v->unavailableBtn())
            connect(v->unavailableBtn(), &QPushButton::clicked, this, [this]{ m->setUnavailable(); });
    }
};

#endif // FACILITYPRESENTER_H
