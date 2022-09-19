#include "Cell.h"

Cell::Cell() : obj(STANDARD), player_location(false){}

Cell& Cell::operator=(const Cell &other) {
    if (this != &other)
        Cell(other).swap(*this);

    return *this;
}

Cell::Cell(Cell &&other) {
    this->swap(other);
}

Cell &Cell::operator=(Cell &&other) {
    if (this != &other)
        this->swap(other);
    return *this;
}

Cell::OBJECT Cell::get_obj() const {
    return obj;
}

void Cell::set_obj(Cell::OBJECT obj) {
    this->obj = obj;
}


void Cell::swap(Cell &other) {
    std::swap(obj, other.obj);
}

void Cell::update() {
    if (check_player())
        event->execute();
}

void Cell::set_event(Event* event) {
    this->event = event;
}

void Cell::set_player_location(bool location) {
    player_location = location;
}

bool Cell::check_player() const {
    return player_location;
}
