#pragma once

#include "Command.h"
#include "Robot.h"

class BlinkLED: public Command {
  public:
    void initialize();
    void execute();
    bool isFinished();
  private:
    int state;
};
