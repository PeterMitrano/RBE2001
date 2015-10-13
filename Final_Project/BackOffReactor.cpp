#include "BackOffReactor.h"

#include "BackOffTube.h"
#include "TurnToNextLine.h"
#include "PathPlanner.h"

BackOffReactor::BackOffReactor(int reactorNumber){
  addSequential(new BackOffTube(-50,-50));
  //sketchy bullshit because turning right by the rod is really fucking hard
  addSequential(new TurnToNextLine());
  if (reactorNumber == 1){
    Robot::getInstance()->col++;
    Robot::getInstance()->direction = PathPlanner::EAST;
  }
  else if (reactorNumber == 2){
    Robot::getInstance()->col--;
    Robot::getInstance()->direction = PathPlanner::WEST;
  }
}

void BackOffReactor::initialize(){
  Robot::getInstance()->setSong(9, false);
}
