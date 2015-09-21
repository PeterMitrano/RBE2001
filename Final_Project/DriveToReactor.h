#pragma once

#include "Robot.h"
#include "Command.h"

class DriveToReactor: public Command {
  public:
    DriveToReactor();
    void initialize();
    void execute();
    bool isFinished();
    void end();
};
