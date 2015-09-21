#pragma once

#include "Robot.h"
#include "Command.h"

class OpenGripper: public Command {
  public:
    void initialize();
    bool isFinished();
};

