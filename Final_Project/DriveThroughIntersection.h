#pragma once
/** \brief
* drives over an intersection and increments the position of the robot
*/
#include "Robot.h"
#include "CommandGroup.h"

class DriveThroughIntersection: public CommandGroup {
  public:
    DriveThroughIntersection();
    void end();
};
