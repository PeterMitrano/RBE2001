#include "BackOffReactor.h"

#include "BackOffTube.h"
#include "TurnToNextLine.h"
#include "PathPlanner.h"
#include "DriveThroughIntersection.h"

BackOffReactor::BackOffReactor(int reactorNumber){
  this->reactorNumber = reactorNumber;
  addSequential(new BackOffTube(-60,-60));
  addSequential(new TurnToNextLine());
}

void BackOffReactor::initialize(){
  if (reactorNumber == 1){
    Robot::getInstance()->direction = PathPlanner::EAST;
  }
  else if (reactorNumber == 2){
    Robot::getInstance()->direction = PathPlanner::WEST;
  }

  // look in tracks.txt for what songs are what
  Robot::getInstance()->setSong(8, false);
}
