#pragma once

#include "Command.h"

class NavigateToReactor: public Command {
  public:
    NavigateToReactor(int reactorNumber);
    void initialize();
    void execute();
    bool isFinished();
    void end();
};
