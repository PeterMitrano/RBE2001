#pragma once

#include "Robot.h"
#include "Command.h"

class ScootPastIntersection : public Command {
  public:
    ScootPastIntersection();
    void initialize();
    void execute();
    bool isFinished();
    void end();
  private:
    /** \brief time to line follow in ms */
    const int scootTime = 200;
};
