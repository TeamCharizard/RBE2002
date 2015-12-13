#pragma once
/** \brief
* just ends the program, does nothing
*/
#include "../systems/Robot.hpp"
#include "Command.h"

class End : public Command {
  public:
    End();
    void initialize();
    void execute();
    bool isFinished();
    void end();
};
