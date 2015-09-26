#pragma once

#include "Robot.h"
#include "Command.h"

class Turn : public Command {
  public:
    Turn(int direction,int timeout);
    void initialize();
    void execute();
    bool isFinished();
    void end();
  private:
    int timeout,direction;
};
