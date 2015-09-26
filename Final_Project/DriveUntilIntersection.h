#pragma once

#include "Robot.h"
#include "Command.h"

class DriveUntilIntersection: public Command {
  public:
    DriveUntilIntersection();
    void initialize();
    void execute();
    bool isFinished();
    void end();
};
