#include "BackOffTube.h"

BackOffTube::BackOffTube() : BackOffTube(-30,-50) {}

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
}
