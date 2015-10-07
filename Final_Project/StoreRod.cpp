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
}

void StoreRod::end(){
  Robot::getInstance()->radiating = false;
}
