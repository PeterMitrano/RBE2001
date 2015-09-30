#pragma once

#include "Robot.h"
#include "Command.h"

class DriveUntilReactorTube : public Command {
  public:
    DriveUntilReactorTube();
    void initialize();
    void execute();
    bool isFinished();
    void end();
};
