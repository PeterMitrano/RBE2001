#include "StoreRodInReactor.h"
#include "RaiseArm.h"
#include "OpenGripper.h"
#include "DriveThroughIntersection.h"
#include "DriveUntilReactorTube.h"
#include "TurnToNextLine.h"
#include "LowerArm.h"
#include "CloseGripper.h"

StoreRodInReactor::StoreRodInReactor(const int reactorNumber) : CommandGroup("store rod in reactor") {
  //addSequential(new NavigateToReactor(reactorNumber));
  addSequential(new TurnToNextLine());
  addSequential(new DriveThroughIntersection());
  addSequential(new TurnToNextLine());
  addSequential(new DriveThroughIntersection());
  addSequential(new DriveUntilReactorTube());
  addSequential(new LowerArm());
  addSequential(new OpenGripper());
  addSequential(new RaiseArm());
  addSequential(new CloseGripper());
}
