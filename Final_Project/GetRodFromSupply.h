#pragma once

#include "Robot.h"
#include "CommandGroup.h"

class GetRodFromSupply: public CommandGroup {
  public:
    GetRodFromSupply();
    void initialize();
    void execute();
    void end();
  private:
    int reactorNumber;
};
