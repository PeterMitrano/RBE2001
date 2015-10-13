#include "BackOffReactor.h"

#include "BackOffTube.h"
#include "TurnToNextLine.h"
#include "PathPlanner.h"
#include "DriveThroughIntersection.h"

BackOffReactor::BackOffReactor(int reactorNumber){
  this->reactorNumber = reactorNumber;
  addSequential(new BackOffTube(-60,-60));
  //sketchy bullshit because turning right by the rod is really fucking hard
  addSequential(new TurnToNextLine());
}

void BackOffReactor::initialize(){
  if (reactorNumber == 1){
    Robot::getInstance()->direction = PathPlanner::EAST;
  }
  else if (reactorNumber == 2){
    Robot::getInstance()->direction = PathPlanner::WEST;
  }
  Robot::getInstance()->setSong(9, false);
}
