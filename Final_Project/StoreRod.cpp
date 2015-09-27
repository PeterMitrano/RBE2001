#include "StoreRod.h"
#include "RaiseArm.h"
#include "NavigateToOpenStorage.h"
#include "OpenGripper.h"
#include "BackOffTube.h"

StoreRod::StoreRod() : CommandGroup("store rod") {
  addSequential(new RaiseArm());
  addSequential(new NavigateToOpenStorage());
  addSequential(new OpenGripper());
  addSequential(new BackOffTube());
}
