#pragma once

#include "Robot.h"
#include "CommandGroup.h"

class DriveThroughIntersection: public CommandGroup {
  public:
    DriveThroughIntersection();
    void end();
};
