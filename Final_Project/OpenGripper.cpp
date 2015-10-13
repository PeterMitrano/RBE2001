#include "OpenGripper.h"

OpenGripper::OpenGripper() : Command("open gripper") {}

void OpenGripper::initialize(){
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
