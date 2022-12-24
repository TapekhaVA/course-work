//
// Created by corvussharp on 21.09.22.
//

#ifndef UNTITLED48_CELLVIEW_H
#define UNTITLED48_CELLVIEW_H
class EventFieldChange;
#include "Cell.h"
#include "../Events/EventsPerson/EventDmg.h"
#include "../Events/EventsPerson/EventHp.h"
#include "../Events/EventsPerson/EventPerson.h"
#include "../Events/EventsPerson/EventXp.h"
#include "../Events/EventsField/EventChangeField.h"
#include "../Events/EventsField/EventWin.h"
#include "../Events/EventsPerson/EventTrap.h"
class CellView{
public:
    explicit CellView(const Cell& sym);
     std::string get_cell()const;
private:
    std::string sym_cell;
};



#endif //UNTITLED48_CELLVIEW_H
