#pragma once

/** \brief navigate to supply, get rod, and back up */

#include "Robot.h"
#include "CommandGroup.h"

class GetRodFromSupply: public CommandGroup {
  public:
    GetRodFromSupply();
    void initialize();
    void end();
  private:
    int reactorNumber;
};
