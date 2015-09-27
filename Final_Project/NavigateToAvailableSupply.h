#pragma once

#include "Command.h"

class NavigateToAvailableSupply: public Command {
  public:
    NavigateToAvailableSupply();
    void initialize();
    void execute();
    bool isFinished();
    void end();
  private:
    int reactorNumber, destDirection, destRow, destCol;
};
