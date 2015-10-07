#pragma once

#include "Command.h"
#include "Robot.h"

class NavigateToAvailableSupply: public Command {
  public:
    NavigateToAvailableSupply();
    void initialize();
    void execute();
    bool isFinished();
    void end();
  private:
    int tubeNumber;
    bool plannedSuccessfully;
};
