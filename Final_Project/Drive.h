#pragma once

#include "Robot.h"
#include "Command.h"

class Drive : public Command{
  public:
    Drive();
    void initialize();
    void execute();
    bool isFinished();
    void end();
};
