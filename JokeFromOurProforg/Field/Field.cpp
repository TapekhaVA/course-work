#include "Field/Field.h"

Field::Field(int width, int height) : mPlayerPosition(height / 2, width / 2), mWidth(width), mHeight(height) {
    mField = new Cell*[mWidth];
    for (int idy = 0; idy < mWidth; idy++)
        mField[idy] = new Cell[mHeight];
    mField[mWidth / 2 + 1][mHeight / 2].SetWall(true);
}

Field& Field::operator=(Field const& other) {
    if (this == &other)
        return *this;
    for (int idx = 0; idx < mWidth; idx++)
        delete[] mField[idx];
    delete[] mField;
    mWidth = other.mWidth;
    mHeight = other.mHeight;
    mField = new Cell*[mWidth];
    for (int idy = 0; idy < mWidth; idy++) {
        mField[idy] = new Cell[mHeight];
        for (int idx = 0; idx < mHeight; idx++)
            mField[idy][idx] = other.mField[idy][idx];
    }
    mPlayerPosition.xCoord = other.mPlayerPosition.xCoord;
    mPlayerPosition.yCoord = other.mPlayerPosition.yCoord;
    return *this;
}

Field::Field(const Field& obj) : Field(obj.mWidth, obj.mHeight) {
    for (int yIdx = 0; yIdx < mWidth; yIdx++)
        for (int xIdx = 0; xIdx < mHeight; xIdx++)
            mField[yIdx][xIdx] = obj.mField[yIdx][xIdx];
    mPlayerPosition.xCoord = obj.mPlayerPosition.xCoord;
    mPlayerPosition.yCoord = obj.mPlayerPosition.yCoord;
}

Field::Field(Field&& obj) : Field(obj.mWidth, obj.mHeight) {
    for (int yIdx = 0; yIdx < mWidth; yIdx++) {
        for (int xIdx = 0; xIdx < mHeight; xIdx++)
            mField[yIdx][xIdx] = obj.mField[yIdx][xIdx];
    }
    mPlayerPosition.xCoord = obj.mPlayerPosition.xCoord;
    mPlayerPosition.yCoord = obj.mPlayerPosition.yCoord;
    obj.~Field();
}

Cell& Field::GetCell(int idy, int idx) const {
    if (idx >= 0 && idx < mHeight && idy >= 0 && idy < mWidth)
        return mField[idy][idx];
}

void Field::SetEventManager(Manager *manager) {
    for (int idy = 0; idy < mWidth; idy++)
        for (int idx = 0; idx < mHeight; idx++)
            mField[idy][idx].SetManager(manager);
}

void Field::TriggerCells() {
    for (int idy = 0; idy < mWidth; idy++) {
        for (int idx = 0; idx < mHeight; idx++) {
            if (idy == mPlayerPosition.yCoord && idx == mPlayerPosition.xCoord) {
                if (mField[idy][idx].ActivateEvent())
                    CreateMessage(EnumClass::LOG_TRIGGER_CELL, &idy, &idx);
            }
            if (mField[idy][idx].CheckEvent()) 
                CreateMessage(EnumClass::LOG_TRIGGER_CELL, &idy, &idx);
        }
    }
}

void Field::SetPlayerPositionX(int x) {
    mPlayerPosition.xCoord = x;
    CreateMessage(EnumClass::LOG_MOVE_PLAYER, &mPlayerPosition.yCoord, &mPlayerPosition.xCoord);
}

void Field::SetPlayerPositionY(int y) {
    mPlayerPosition.yCoord = y;
    CreateMessage(EnumClass::LOG_MOVE_PLAYER, &mPlayerPosition.yCoord, &mPlayerPosition.xCoord);
}

void Field::CreateMessage(EnumClass::Log type, int* pos1, int* pos2){
    Message* msg = new Message(type);
    msg->IncreaseData(pos1);
    msg->IncreaseData(pos2);
    Notify(msg);
    delete msg;
}

Field::~Field() {
    for (int idy = 0; idy < mWidth; idy++)
        delete[] mField[idy];
    delete[] mField;
}