#include "CloseGripper.h"

CloseGripper::CloseGripper() : Command("close gripper") {}

void CloseGripper::initialize(){
  setTimeout(1000);
  Robot::getInstance()->setSong(17,false);
}


void CloseGripper::execute(){
  Robot::getInstance()->arm.gripper.cls();
}


bool CloseGripper::isFinished(){
  return isTimedOut();
}


void CloseGripper::end(){
}
