#pragma once

#include "Robot.h"
#include "CommandGroup.h"

class GetRodFromReactor: public CommandGroup {
  public:
    GetRodFromReactor(const int reactorNumber);
    /** \brief since this routime is dependant on bluetooth messages, and must be determined on execution, not on declaration, we defer the adding of commands to the initialize method.
     * This way, we can safely call NavigateToReactor, which checks bluetooth at excution time, and it will add commands to the group sequentially. */
    void initialize();
    void end();
  private:
    int reactorNumber,
        destCol,
        destRow,
        destDirection;
};
