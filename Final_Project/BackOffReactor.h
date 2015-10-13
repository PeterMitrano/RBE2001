#pragma once

#include "Robot.h"
#include "CommandGroup.h"

class BackOffReactor : public CommandGroup {
  public:
    BackOffReactor(int reactorNumber);
    void initialize();
  private:
    int reactorNumber;
};
