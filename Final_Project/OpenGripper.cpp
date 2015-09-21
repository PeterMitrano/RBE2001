#include "OpenGripper.h"

void OpenGripper::initialize(){
  Robot::getInstance()->arm->gripper->opn();
}

bool OpenGripper::isFinished(){
  //since servo will get it to where it needs to go, only run once
  return true;
}
