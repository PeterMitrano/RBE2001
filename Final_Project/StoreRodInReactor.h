#pragma once

#include "Robot.h"
#include "CommandGroup.h"

class StoreRodInReactor: public CommandGroup {
  public:
    StoreRodInReactor(const int reactorNumber);
    void initialize();
    void end();
  private:
    int reactorNumber;
};
