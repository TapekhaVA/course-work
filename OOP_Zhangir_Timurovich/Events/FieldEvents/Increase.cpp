#include "Increase.h"

Increase::Increase(Field *field, Player *player) {
    this->player = player;
    this->field = field;
}


bool Increase::execute() {
    if (field) {
        field->add_height(5);
        field->add_width(5);
        notify();
        return true;
    }
    return false;
}

