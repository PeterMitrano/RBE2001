#pragma once

#include "Robot.h"
#include "CommandGroup.h"

class GetRodFromReactor: public CommandGroup {
  public:
    GetRodFromReactor(const int reactorNumber);
};
