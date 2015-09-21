#include "CloseGripper.h"

void CloseGripper::initialize(){
  Robot::getInstance()->closeGripper();
}

bool CloseGripper::isFinished(){
  //since servo will get it to where it needs to go, only run once
  return true;
}
