#pragma once

#include "Robot.h"
#include "Command.h"

class CloseGripper: public Command {
  public:
    CloseGripper(int force);
    CloseGripper();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    const static int HARD = 180,
          SOFT = 165;
  private:
    int force;
};

