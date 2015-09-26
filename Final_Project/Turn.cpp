#include "Turn.h"

Turn::Turn(int direction, int timeout) : Command("turn") {
  this->direction = direction;
  this->timeout = timeout;
}

void Turn::initialize(){
  setTimeout(timeout);
  if (direction = 1){
    Robot::getInstance()->rotateRight();
  }
  else {
    Robot::getInstance()->rotateLeft();
  }
}

void Turn::execute(){

}

bool Turn::isFinished(){
  return isTimedOut();
}

void Turn::end(){
  Robot::getInstance()->stopDriving();
}
