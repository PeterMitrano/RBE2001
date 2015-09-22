#pragma once

#include "Robot.h"
#include "Command.h"

class OpenGripper: public Command {
  public:
    OpenGripper();
    void initialize();
    void execute();
    bool isFinished();
    void end();
};

