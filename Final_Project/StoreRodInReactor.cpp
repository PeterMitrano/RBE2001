#include "StoreRodInReactor.h"
#include "RaiseArm.h"
#include "NavigateToReactor.h"
#include "OpenGripper.h"
#include "LowerArm.h"
#include "CloseGripper.h"

StoreRodInReactor::StoreRodInReactor(const int reactorNumber) : CommandGroup("store rod in reactor") {
  addSequential(new RaiseArm());
  addSequential(new NavigateToReactor(reactorNumber));
  addSequential(new LowerArm());
  addSequential(new OpenGripper());
  addSequential(new RaiseArm());
  addSequential(new CloseGripper());
}
