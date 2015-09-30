#include "TurnOffLine.h"

TurnOffLine::TurnOffLine(int direction) : Command("turn off line"){
  this->direction = direction;
}

void TurnOffLine::initialize(){}

void TurnOffLine::execute(){
  if (direction == 1){
    Robot::getInstance()->rotateLeft();
  }
  else {
    Robot::getInstance()->rotateRight();
  }
}

bool TurnOffLine::isFinished(){
  if (direction == 1){
    return Robot::getInstance()->lineSensor.leftSideOffLine();
  }
  else {
    return Robot::getInstance()->lineSensor.rightSideOffLine();
  }
}

void TurnOffLine::end(){
  Robot::getInstance()->stopDriving();
}
