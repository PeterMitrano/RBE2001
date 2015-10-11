#pragma once
/** \brief
* puts the rod into the reactor specified 
*/
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
