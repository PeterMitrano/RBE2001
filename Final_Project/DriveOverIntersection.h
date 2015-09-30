#pragma once

#include "Robot.h"
#include "Command.h"

class DriveOverIntersection : Command {
  public:
    DriveOverIntersection();
    void initialize();
    void execute();
    bool isFinished();
    void end();
};
