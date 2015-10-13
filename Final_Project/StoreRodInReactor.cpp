#include "StoreRodInReactor.h"
#include "RaiseArm.h"
#include "OpenGripper.h"
#include "LowerArm.h"
#include "CloseGripper.h"
#include "PathPlanner.h"
#include "BackOffReactor.h"

StoreRodInReactor::StoreRodInReactor(const int reactorNumber) : CommandGroup("store rod in reactor") {
  this->reactorNumber = reactorNumber;
}

void StoreRodInReactor::initialize(){
  int destDirection = PathPlanner::WEST, destRow = 1, destCol = 0;

  if (reactorNumber == 2){
    destCol = 5;
    destDirection = PathPlanner::EAST;
  }

  PathPlanner *planner = new PathPlanner();

  CommandGroup *pathToStorage = planner->plan(destRow, destCol, destDirection);

  addSequential(new RaiseArm());
  addSequential(pathToStorage);
  addSequential(new LowerArm());
  addSequential(new OpenGripper());
  addSequential(new RaiseArm());
  addSequential(new BackOffReactor(reactorNumber));
}

void StoreRodInReactor::end(){
  Robot::getInstance()->radiating = false;
}
