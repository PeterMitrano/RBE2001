#pragma once

#include "Robot.h"
#include "Command.h"

class CloseGripper: public Command {
  public:
    void initialize();
    bool isFinished();
};

