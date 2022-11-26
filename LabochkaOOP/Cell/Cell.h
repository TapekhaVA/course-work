//
// Created by corvussharp on 21.09.22.
//
class Person;
#ifndef UNTITLED48_CELL_H
#define UNTITLED48_CELL_H
#include "../Events/EventsPerson//EventPerson.h"

#include "../Events/EventsField//EventField.h"
#include "../LOG/Logs/Subject.h"
class Cell:public Subject{
public:
     ~Cell();
    explicit Cell();

    void update(void* obj);

    void set_person_in(bool loc);
    bool get_person_in() const;

    bool get_passab() const;
    void set_passab(bool pass);



    Event* get_event() const;

    void set_event(Event* event);
private:
    bool passability;
    bool person_in;
    Event* event;
    bool player_loc;
};


#endif //UNTITLED48_CELL_H
