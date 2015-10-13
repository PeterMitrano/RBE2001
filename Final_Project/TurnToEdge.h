#pragma once

/** \brief turn to the edge of the line
 * possible combinations:
 *  turn CW until the left side of the line
 *  turn CW until the right side of the line
 *  turn CCW until the left side of the line
 *  turn CCW until the right side of the line
 */

#include "Robot.h"
#include "Command.h"

class TurnToEdge : public Command {
  public:
    TurnToEdge(int whichEdge, int turnDirection);
    void execute();
    void initialize();
    bool isFinished();
    void end();
  private:
    int whichEdge, turnDirection;
};
