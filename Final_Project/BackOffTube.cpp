#include "BackOffTube.h"

BackOffTube::BackOffTube() : Command("back off tube") {}

void BackOffTube::initialize(){
  setTimeout(backOffTime);
}

void BackOffTube::execute(){
  Robot::getInstance()->backUp();
}

bool BackOffTube::isFinished(){
  return isTimedOut();
}

void BackOffTube::end(){
  Robot::getInstance()->stopDriving();
}
