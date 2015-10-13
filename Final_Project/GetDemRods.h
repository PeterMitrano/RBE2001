#pragma once

/** \brief Overall program command.
 * Composed of nine commands which together complete the whole task
 */

#include "Robot.h"
#include "CommandGroup.h"

class GetDemRods: public CommandGroup {
  public:
    GetDemRods();
};
