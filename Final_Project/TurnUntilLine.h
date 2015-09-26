#pragma once

#include "Command.h"
#include "Robot.h"

class TurnUntilLine : public Command {
  public:
    TurnUntilLine(int direction);
    void initialize();
    void execute();
    bool isFinished();
    void end();
  private:
    int direction;
};
