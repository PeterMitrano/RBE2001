#pragma once

#include "Robot.h"
#include "Command.h"

class BackOffTube : public Command {
  public:
    BackOffTube();
    BackOffTube(int leftSpeed, int rightSpeed);
    void initialize();
    void execute();
    bool isFinished();
    void end();
  private:
    int rPower,lPower;
    const int backOffTime = 600;
};
