#include "OpenGripper.h"

OpenGripper::OpenGripper() : Command("open gripper") {}

void OpenGripper::initialize(){
  setTimeout(1000);
}

void OpenGripper::execute(){
  Robot::getInstance()->arm.gripper.opn();
}

bool OpenGripper::isFinished(){
  return isTimedOut();
}

void OpenGripper::end(){
  Robot::getInstance()->setSong(8, false);
}
