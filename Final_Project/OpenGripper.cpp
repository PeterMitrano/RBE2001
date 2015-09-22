#include "OpenGripper.h"

OpenGripper::OpenGripper() : Command("open gripper") {}

void OpenGripper::initialize(){
  Robot::getInstance()->arm->gripper->opn();
}

void OpenGripper::execute(){}

bool OpenGripper::isFinished(){
  //since servo will get it to where it needs to go, only run once
  return true;
}

void OpenGripper::end(){}
