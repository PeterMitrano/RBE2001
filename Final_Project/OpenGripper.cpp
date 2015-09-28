#include "OpenGripper.h"

OpenGripper::OpenGripper() : Command("open gripper"){}

void OpenGripper::initialize(){
  setTimeout(2000);
  Robot::getInstance()->openGripper();
}

void OpenGripper::execute(){}

bool OpenGripper::isFinished(){
  return isTimedOut();
}

void OpenGripper::end(){}
