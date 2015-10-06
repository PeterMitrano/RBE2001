#pragma once

#include "Robot.h"
#include "Command.h"

class End : public Command {
  public:
    End();
    void initialize();
    void execute();
    bool isFinished();
    void end();
};
