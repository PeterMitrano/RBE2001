#include "TurnToEdge.h"
#include "PathPlanner.h"

TurnToEdge::TurnToEdge(int whichEdge, int turnDirection){
  this->whichEdge = whichEdge;
  this->turnDirection = turnDirection;
}

void TurnToEdge::initialize(){
}

void TurnToEdge::execute(){
  if (turnDirection == PathPlanner::CCW){
    return Robot::getInstance()->rotateCCW();
  }
  else if (turnDirection == PathPlanner::CW){
    return Robot::getInstance()->rotateCW();
  }
}

bool TurnToEdge::isFinished(){
  if (whichEdge == LineSensor::LEFT_EDGE){
    return Robot::getInstance()->lineSensor.lineFarLeft();
  }
  else if (whichEdge == LineSensor::RIGHT_EDGE){
    return Robot::getInstance()->lineSensor.lineFarRight();
  }
}

void TurnToEdge::end(){
  Robot::getInstance()->stopDriving();
}
