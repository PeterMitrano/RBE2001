#include "StoreRodInReactor.h"
#include "RaiseArm.h"
#include "OpenGripper.h"
#include "LowerArm.h"
#include "CloseGripper.h"
#include "PathPlanner.h"
#include "BackOffTube.h"

StoreRodInReactor::StoreRodInReactor(const int reactorNumber) : CommandGroup("store rod in reactor") {
  this->reactorNumber = reactorNumber;
  Robot::getInstance()->setSong(9,false);
}

void StoreRodInReactor::initialize(){
  int destDirection = PathPlanner::WEST, destRow = 1, destCol = 0;

  if (reactorNumber == 2){
    destCol = 5;
    destDirection = PathPlanner::EAST;
  }

  Robot::getInstance()->debugPrint2(destCol);
  PathPlanner *planner = new PathPlanner();

  CommandGroup *pathToStorage = planner->plan(destRow, destCol, destDirection);

  addSequential(new RaiseArm());
  addSequential(pathToStorage);
  addSequential(new LowerArm());
  addSequential(new OpenGripper());
  addSequential(new RaiseArm());
  addSequential(new BackOffTube(-46,-28));
}

void StoreRodInReactor::end(){
  Robot::getInstance()->radiating = false;
}
