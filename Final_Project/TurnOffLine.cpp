#include "TurnOffLine.h"
#include "PathPlanner.h"

TurnOffLine::TurnOffLine(int direction) : Command("turn off line"){
  this->direction = direction;
}

void TurnOffLine::initialize(){
  setTimeout(400);
  Robot::getInstance()->setSong(1,false);
}

void TurnOffLine::execute(){
  if (direction == PathPlanner::CCW){
    Robot::getInstance()->rotateCCW();
  }
  else if (direction == PathPlanner::CW) {
    Robot::getInstance()->rotateCW();
  }
}

bool TurnOffLine::isFinished(){
  return isTimedOut();
}

void TurnOffLine::end(){
  Robot::getInstance()->stopDriving();
}
