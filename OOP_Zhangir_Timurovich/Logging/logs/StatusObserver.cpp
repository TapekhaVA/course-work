//
// Created by roman on 26.10.2022.
//

#include "StatusObserver.h"

void StatusObserver::update(Message &msg) {
    return;
}

StatusObserver::StatusObserver(Subject *model) {
    model->attach(this);
}