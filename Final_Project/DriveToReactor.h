#pragma once

#include "Command.h"

class DriveToReactor: Command {
  public:
    DriveToReactor();
    void Initialize();
    void Execute();
    void IsFinished();
    void End();
};
