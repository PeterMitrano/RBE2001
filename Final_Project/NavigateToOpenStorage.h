#pragma once

#include "Command.h"

class NavigateToOpenStorage: public Command {
  public:
    NavigateToOpenStorage();
    void initialize();
    void execute();
    bool isFinished();
    void end();
  private:
    int reactorNumber, destDirection, destRow, destCol;
};
