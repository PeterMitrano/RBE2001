#pragma once

#include "Robot.h"
#include "Command.h"

class DriveOverIntersection : public Command {
  public:
    DriveOverIntersection();
    void initialize();
    void execute();
    bool isFinished();
    void end();
};
