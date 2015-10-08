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
  int destDirection = 3, destRow = 1, destCol = 0;

  if (reactorNumber == 2){
    destCol = 5;
    destDirection = 1;
  }


  CommandGroup *pathToReactor = new CommandGroup();
  PathPlanner *planner = new PathPlanner(pathToReactor);
  planner->plan(destRow, destCol, destDirection);

  for (int i=0;i<pathToReactor->commands.size();i++){
    Serial.print("  ");
    Serial.println(pathToReactor->commands.get(i)._command->name);
  }
  Serial.println("...]");

  addSequential(pathToReactor);
  addSequential(new LowerArm());
  addSequential(new CloseGripper());
  addSequential(new RaiseArm());
  addSequential(new BackOffTube());
}

void GetRodFromReactor::end(){
  Robot::getInstance()->radiating = true;
}
