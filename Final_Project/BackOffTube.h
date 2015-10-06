#pragma once

#include "Robot.h"
#include "Command.h"

class BackOffTube : public Command {
  public:
    BackOffTube();
    void initialize();
    void execute();
    bool isFinished();
    void end();
  private:
    const int backOffTime =600;
};
