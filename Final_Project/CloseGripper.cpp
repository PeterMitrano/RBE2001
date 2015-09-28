#include "CloseGripper.h"

CloseGripper::CloseGripper() : Command("close gripper"){}

void CloseGripper::initialize(){
  setTimeout(1000);
  Robot::getInstance()->closeGripper();
}

void CloseGripper::execute(){
}

bool CloseGripper::isFinished(){
  return isTimedOut();
}

void CloseGripper::end(){
}
