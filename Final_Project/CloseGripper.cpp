#include "CloseGripper.h"

CloseGripper::CloseGripper() : Command("close gripper") {}

void CloseGripper::initialize(){
  setTimeout(1000);
}


void CloseGripper::execute(){
  Robot::getInstance()->arm.gripper.cls();
}


bool CloseGripper::isFinished(){
  return isTimedOut();
}


void CloseGripper::end(){}
