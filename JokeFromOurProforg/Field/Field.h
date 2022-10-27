#ifndef SURVIVAL_FIELD_H
#define SURVIVAL_FIELD_H

#include "Field/Cell.h"
#include "Logging/Subject.h"
#include "Enums.h"

#include <vector>
#include <cmath>

struct Position {
    int xCoord, yCoord;

    Position(int xCoord, int yCoord) : xCoord(xCoord), yCoord(yCoord) {}
};

class Field : public Subject {
public:
    explicit Field(int w = EnumClass::STANDARD_SIZE, int h = EnumClass::STANDARD_SIZE);
    Field(const Field& obj);
    Field(Field&& obj);

    Field& operator =(Field const& other);

    int GetWidth() const { return mWidth; }
    int GetHeight() const { return mHeight; }
    void SetPlayerPositionX(int x);
    void SetPlayerPositionY(int y);
    int GetPlayerPositionX() const { return mPlayerPosition.xCoord; }
    int GetPlayerPositionY() const { return mPlayerPosition.yCoord; }
    Cell& GetCell(int idy, int idx) const;

    void SetEventManager(Manager* manager);
    void TriggerCells();

    ~Field();

private:

    void CreateMessage(EnumClass::Log type, int* pos1, int* pos2);

    Cell** mField;
    int mWidth, mHeight;
    Position mPlayerPosition;
};

#endif //SURVIVAL_FIELD_H