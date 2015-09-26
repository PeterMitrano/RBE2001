#pragma once

#include "Robot.h"
#include "Command.h"

class TurnToFace : public Command {
  public:
    TurnToFace(int destDirection);
    void initialize();
    void execute();
    bool isFinished();
    void end();
  private:
    int destDirection,timesToTurn,timesTurned;
};
