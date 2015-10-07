#include "OpenGripper.h"

OpenGripper::OpenGripper() : Command("open gripper") {}

void OpenGripper::initialize(){
  Robot::getInstance()->setSong(8, false);
  setTimeout(400);
  Robot::getInstance()->arm.gripper.opn();
}

void OpenGripper::execute(){
}

bool OpenGripper::isFinished(){
  return isTimedOut();
}

void OpenGripper::end(){
}
