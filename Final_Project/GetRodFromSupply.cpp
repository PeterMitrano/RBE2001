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

  if (destCol < 2 || destCol > 5){
    destCol = 2;
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

void GetRodFromSupply::execute(){
  //if bluetooth says we've failed to remove the rod, try again
  if (Robot::getInstance()->btClient.noRodAt(destCol)
}

void GetRodFromSupply::end(){
  Robot::getInstance()->radiating = true;
}

