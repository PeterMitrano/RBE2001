#include "GetRodFromReactor.h"
#include "DriveToReactor.h"
#include "OpenGripper.h"
#include "LowerArm.h"

GetRodFromReactor::GetRodFromReactor() : CommandGroup("get rod from reactor") {
  addSequential(new DriveToReactor());

  addParallel(new OpenGripper());
  addSequential(new LowerArm());

  //AddSequential(new CloseGripper());
  //AddSequential(new RaiseArm());
}
