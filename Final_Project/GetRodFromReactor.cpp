#include "GetRodFromReactor.h"
#include "NavigateToReactor.h"
#include "OpenGripper.h"
#include "CloseGripper.h"
#include "LowerArm.h"
#include "RaiseArm.h"
#include "DriveUntilIntersection.h"
#include "DriveUntilReactorTube.h"
#include "DriveOverIntersection.h"
#include "TurnAround.h"

GetRodFromReactor::GetRodFromReactor(const int reactorNumber) : CommandGroup("get rod from reactor") {
  addSequential(new NavigateToReactor(reactorNumber));
/*  addSequential(new DriveUntilIntersection());
  addSequential(new DriveOverIntersection());
  addSequential(new DriveUntilReactorTube());

  addParallel(new OpenGripper());
  addSequential(new LowerArm());
  addSequential(new CloseGripper());
  addSequential(new RaiseArm());
  */
}
