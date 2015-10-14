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

  PathPlanner *planner = new PathPlanner();
  CommandGroup *pathToStorage = planner->plan(destRow, destCol, destDirection);

  addParallel(new RaiseArm());
  addParallel(new OpenGripper());
  addSequential(pathToStorage);
	addSequential(new CloseGripper(CloseGripper::HARD));
	addSequential(new BackOffTube(-23,-23));
	addSequential(new OpenGripper());
  addSequential(new DriveUntilReactorTube());
	addSequential(new CloseGripper(CloseGripper::HARD));
	addSequential(new BackOffTube(-35,-35));
}

void GetRodFromSupply::end(){
  Robot::getInstance()->radiating = true;
  Robot::getInstance()->highRadiating = true;
}

