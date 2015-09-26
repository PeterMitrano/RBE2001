#pragma once

#include "Command.h"
#include "Robot.h"

class Calibrate : public Command {
  public:
    Calibrate();
    void initialize();
    void execute();
    bool isFinished();
    void end();
  private:
    int minVal, maxVal;
};
