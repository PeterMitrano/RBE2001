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
   	const long waitTime = -1;
    int startTime = -1;
};
