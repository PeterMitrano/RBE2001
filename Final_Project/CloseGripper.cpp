#include "CloseGripper.h"

CloseGripper::CloseGripper() : Command("				close gripper") {}

void CloseGripper::initialize(){
  setTimeout(400);
  Robot::getInstance()->arm.gripper.cls();
}


void CloseGripper::execute(){
}


bool CloseGripper::isFinished(){
  return isTimedOut();
}


void CloseGripper::end(){
}
