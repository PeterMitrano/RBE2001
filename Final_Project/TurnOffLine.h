#pragma once

#include "Command.h"
#include "Robot.h"

class TurnOffLine : public Command {
  public:
    TurnOffLine(int direction);
    void initialize();
    virtual void execute();
    bool isFinished();
    virtual void end();
  private:
    int direction;
};
