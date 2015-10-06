#include "TurnOffLine.h"

TurnOffLine::TurnOffLine(int direction) : Command("turn off line"){
  this->direction = direction;
}

void TurnOffLine::initialize(){
  Robot::getInstance()->setSong(23,true);
}

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
    return Robot::getInstance()->lineSensor.offLine();
  }
  else {
    return Robot::getInstance()->lineSensor.offLine();
  }
}

void TurnOffLine::end(){
  Robot::getInstance()->stopDriving();
}
