//
// Created by roman on 26.10.2022.
//

#ifndef MAIN_CPP_CONSOLEOUT_H
#define MAIN_CPP_CONSOLEOUT_H

#include "Output.h"
#include <string>
#include <iostream>


class ConsoleOut : public Output {
public:
    void print(Message& message) override;

    ConsoleOut() = default;
};


#endif //MAIN_CPP_CONSOLEOUT_H
