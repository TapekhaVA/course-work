//
// Created by corvussharp on 06.10.22.
//

#ifndef UNTITLED48_EVENTHP_H
#define UNTITLED48_EVENTHP_H
#include "EventPerson.h"
#include "../Persons/Person.h"


class EventHp: public EventPerson{
public:
    void doing(Person& person) override;
};
#endif //UNTITLED48_EVENTHP_H
