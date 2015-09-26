#pragma once

#include "Command.h"
#include "Robot.h"

class BlinkLED: public Command {
  public:
    BlinkLED();
    void initialize();
    void execute();
    void end();
    bool isFinished();
  private:
    int state;
};
