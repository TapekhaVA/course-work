//
// Created by roman on 07.11.2022.
//

#pragma once

#include <vector>
#include "../Info/Enums.h"
#include "ControlConfig/ControlConfig.h"
#include "../Logging/Subject.h"

class CommandReader {
public:

    virtual ~CommandReader() = default;

    virtual MOVES read_move(LogOutInfo *info) = 0;

protected:
    int width{};
    int height{};
    std::vector <OUTPUT> outputs;
    std::vector <LEVEL> levels;
    ControlConfig *control_config;
};


