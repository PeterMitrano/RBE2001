#pragma once

#include "Command.h"
#include "Robot.h"

class NavigateToOpenStorage: public Command {
  public:
    NavigateToOpenStorage();
    void initialize();
    void execute();
    bool isFinished();
    void end();
  private:
    int tubeNumber;
    bool plannedSuccessfully;
};
