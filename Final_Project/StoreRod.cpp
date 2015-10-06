#include "StoreRod.h"
#include "RaiseArm.h"
#include "NavigateToOpenStorage.h"
#include "OpenGripper.h"
#include "BackOffTube.h"
#include "DriveThroughIntersection.h"
#include "TurnOffLine.h"
#include "TurnUntilLine.h"
#include "DriveUntilReactorTube.h"
#include "TurnToNextLine.h"
#include "ScootPastIntersection.h"

StoreRod::StoreRod() : CommandGroup("store rod") {
  addSequential(new BackOffTube());
  addSequential(new NavigateToOpenStorage());
//  addSequential(new TurnToNextLine());
//  addSequential(new TurnToNextLine());
//  addSequential(new DriveThroughIntersection());
//  addSequential(new DriveThroughIntersection());
//  addSequential(new TurnToNextLine());
//  addSequential(new DriveUntilReactorTube());
//  addSequential(new OpenGripper());
//  addSequential(new BackOffTube());
}
