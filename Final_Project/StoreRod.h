#pragma once

/** \brief navigate to storage, insert rod, and back up */

#include "Robot.h"
#include "CommandGroup.h"

class StoreRod: public CommandGroup {
  public:
    StoreRod();
    void initialize();
    void end();
};
