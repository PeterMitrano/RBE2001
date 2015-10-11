#include "StoreRodInReactor.h"
#include "RaiseArm.h"
#include "OpenGripper.h"
#include "LowerArm.h"
#include "CloseGripper.h"
#include "PathPlanner.h"

StoreRodInReactor::StoreRodInReactor(const int reactorNumber) : CommandGroup("store rod in reactor") {
  int destDirection = 3, destRow = 1, destCol = 0;

  if (reactorNumber == 2){
    destCol = 5;
    destDirection = 1;
  }

  Robot::getInstance()->debugPrint2(destCol);
  Serial.print("going to ");
  Serial.println(destCol);

  PathPlanner *planner = new PathPlanner();
  CommandGroup *pathToStorage = planner->plan(destRow, destCol, destDirection);

  addSequential(new RaiseArm());
  addSequential(pathToStorage);
  addSequential(new LowerArm());
  addSequential(new OpenGripper());
  addSequential(new RaiseArm());
  addSequential(new CloseGripper());
}
