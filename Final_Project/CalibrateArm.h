#pragma once

#include "Robot.h"
#include "Command.h"

class CalibrateArm : public Command {
  public:
    CalibrateArm();
    void initialize();
    void execute();
    bool isFinished();
    void end();
};
