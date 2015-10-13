#include "CloseGripper.h"

CloseGripper::CloseGripper() : CloseGripper(CloseGripper::SOFT) {}

CloseGripper::CloseGripper(int force) : Command("close gripper") {
  this->force = force;
}

void CloseGripper::initialize(){
  setTimeout(400);
  Robot::getInstance()->arm.gripper.cls(force);
}


void CloseGripper::execute(){
}


bool CloseGripper::isFinished(){
  return isTimedOut();
}


void CloseGripper::end(){
}
