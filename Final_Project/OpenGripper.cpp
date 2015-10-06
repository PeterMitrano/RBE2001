#include "OpenGripper.h"

OpenGripper::OpenGripper() : Command("open gripper") {}

void OpenGripper::initialize(){
  Robot::getInstance()->setSong(8, false);
  setTimeout(1000);
}

void OpenGripper::execute(){
  Robot::getInstance()->arm.gripper.opn();
}

bool OpenGripper::isFinished(){
  return isTimedOut();
}

void OpenGripper::end(){
}
