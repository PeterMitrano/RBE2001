#pragma once

#include "Robot.h"
#include "Command.h"

class LowerArm: public Command {
  public:
    LowerArm();
    void initialize();
    void execute();
    bool isFinished();
    void end();
  private:
    const int setpoint = -1;
    const int tolerance = -1;
};
