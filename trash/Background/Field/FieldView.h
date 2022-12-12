#ifndef LABS_FIELDVIEW_H
#define LABS_FIELDVIEW_H

#include "Field/Field.h"
#include "Cell/CellView.h"

class FieldView {
public:
    explicit FieldView(Field*);
    void update();

    std::string field_str();
private:
    void print_border() const;

    Field* field;
};

#endif

