#include "GetRodFromSupply.h"
#include "RaiseArm.h"
#include "CloseGripper.h"
#include "OpenGripper.h"
#include "BackOffTube.h"
#include "DriveUntilReactorTube.h"
#include "PathPlanner.h"

GetRodFromSupply::GetRodFromSupply() : CommandGroup("get rod from supply"){}

void GetRodFromSupply::initialize(){
	 int destDirection = 0, destRow = 0, destCol;

  destCol = Robot::getInstance()->btClient.availableSupplyTube();

  if (destCol < 1 || destCol > 4){
    destCol = 1;
  }

  Robot::getInstance()->debugPrint2(destCol);
  Serial.print("going to ");
  Serial.println(destCol);

  PathPlanner *planner = new PathPlanner();
  CommandGroup *pathToStorage = planner->plan(destRow, destCol, destDirection);

  addSequential(new RaiseArm());
  addSequential(new OpenGripper());
  addSequential(pathToStorage);
	addSequential(new CloseGripper());
	addSequential(new BackOffTube(-24,-16));
	addSequential(new OpenGripper());
  addSequential(new DriveUntilReactorTube());
	addSequential(new CloseGripper());
	addSequential(new BackOffTube());

}

void GetRodFromSupply::end(){
  Robot::getInstance()->radiating = true;
}

