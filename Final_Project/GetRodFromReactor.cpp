#include "GetRodFromReactor.h"
#include "NavigateToReactor.h"
#include "OpenGripper.h"
#include "CloseGripper.h"
#include "LowerArm.h"
#include "RaiseArm.h"
#include "DriveThroughIntersection.h"
#include "DriveUntilReactorTube.h"
#include "TurnToNextLine.h"
#include "TurnOffLine.h"
#include "TurnUntilLine.h"

GetRodFromReactor::GetRodFromReactor(const int reactorNumber) : CommandGroup("get rod from reactor") {
  addSequential(new NavigateToReactor(reactorNumber));
  addParallel(new OpenGripper());
  addSequential(new LowerArm());
  addSequential(new CloseGripper());
  addSequential(new RaiseArm());

  // addSequential(new BackOffTube());
  // addSequential(new TurnAround());
}

void GetRodFromReactor::end(){
  Robot::getInstance()->radiating = true;
}
