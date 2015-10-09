#include "BackOffTube.h"

BackOffTube::BackOffTube() : BackOffTube(-40, -40) {}

BackOffTube::BackOffTube(int lPower, int rPower) : Command("back off tube") {
  this->rPower = rPower;
  this->lPower = lPower;
}

void BackOffTube::initialize(){
  setTimeout(backOffTime);
}

void BackOffTube::execute(){
  Robot::getInstance()->backUp(rPower,lPower);
}

bool BackOffTube::isFinished(){
  return isTimedOut();
}

void BackOffTube::end(){
  Robot::getInstance()->stopDriving();
  if(Robot::getInstance()->row==1){
 	 Robot::getInstance()->decrementPosition();
 	}
}
