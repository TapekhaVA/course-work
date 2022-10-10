#ifndef LABS_NEWLEVEL_H
#define LABS_NEWLEVEL_H

class Field;

#include "EventField.h"

class NewLevel : public EventField {
public:
    void execute(Field& field) final;
    ~NewLevel() override = default;
};


#endif
