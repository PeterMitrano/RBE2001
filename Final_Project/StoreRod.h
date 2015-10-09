#pragma once

#include "Robot.h"
#include "CommandGroup.h"

class StoreRod: public CommandGroup {
  public:
    StoreRod();
    void initialize();
    void end();
};
