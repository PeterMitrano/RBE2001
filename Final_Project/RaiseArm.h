#pragma once

#include "Robot.h"
#include "Command.h"

class RaiseArm : public Command {
  public:
    RaiseArm();
    void initialize();
    void execute();
    bool isFinished();
    void end();
};
