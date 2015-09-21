#pragma once

#include "Robot.h"
#include "Command.h"

class CloseGripper: public Command {
  public:
    CloseGripper();
    void initialize();
    void execute();
    void end();
    bool isFinished();
};

