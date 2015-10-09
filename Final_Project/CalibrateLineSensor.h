#pragma once

#include "Command.h"
#include "Robot.h"

class CalibrateLineSensor : public Command {
  public:
    CalibrateLineSensor();
    void initialize();
    void execute();
    bool isFinished();
    void end();
  private:
    const static int CALIBRATE_TIME = 3000;
};
