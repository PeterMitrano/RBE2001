#include "StoreRod.h"
#include "RaiseArm.h"
#include "OpenGripper.h"
#include "BackOffTube.h"
#include "PathPlanner.h"

StoreRod::StoreRod() : CommandGroup("store rod") {
}

void StoreRod::initialize(){
  //these are fixed, except destCol which should be bluetooth
  int destDirection = 2, destRow = 2, destCol;

  destCol = Robot::getInstance()->btClient.openStorageTube();

  if (destCol < 2 || destCol > 5){
    destCol = 2;
  }

  Robot::getInstance()->debugPrint2(destCol);
  Serial.print("going to ");
  Serial.println(destCol);

  PathPlanner *planner = new PathPlanner();
  CommandGroup *pathToStorage = planner->plan(destRow, destCol, destDirection);

  addSequential(new RaiseArm());
  addSequential(pathToStorage);
  addSequential(new OpenGripper());
  addSequential(new BackOffTube(-30,-40));
}

void StoreRod::end(){
  Robot::getInstance()->radiating = false;
}
