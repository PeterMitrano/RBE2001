#pragma once

#include "CommandGroup.h"
#include "Robot.h"

class TurnToNextLine : public CommandGroup {
  public:
    TurnToNextLine(int direction);
    TurnToNextLine();
    void end();
  private:
    int direction;
};
