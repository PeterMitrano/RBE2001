#include "GetRodFromReactor.h"
#include "OpenGripper.h"
#include "CloseGripper.h"
#include "LowerArm.h"
#include "RaiseArm.h"
#include "DriveThroughIntersection.h"
#include "BackOffTube.h"
#include "DriveUntilReactorTube.h"
#include "TurnToNextLine.h"
#include "PathPlanner.h"

GetRodFromReactor::GetRodFromReactor(const int reactorNumber) : CommandGroup("get rod from reactor") {
  this->reactorNumber = reactorNumber;
}

void GetRodFromReactor::initialize(){
  //figure out where we're going
  destDirection = 3, destRow = 1, destCol = 0;

  if (reactorNumber == 2){
    destCol = 5;
    destDirection = 1;
  }

  PathPlanner *planner = new PathPlanner();
  CommandGroup *pathToReactor = planner->plan(destRow, destCol, destDirection);

  addSequential(pathToReactor);
  addSequential(new LowerArm());
  addSequential(new CloseGripper(CloseGripper::SOFT));
  addSequential(new RaiseArm());
  addSequential(new BackOffTube(-46,-28));
}

void GetRodFromReactor::end(){
  Robot::getInstance()->radiating = true;
}
