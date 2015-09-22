#include "CloseGripper.h"

CloseGripper::CloseGripper() : Command("close gripper"){}

void CloseGripper::initialize(){
  setTimeout(3000);
}

void CloseGripper::execute(){
  Robot::getInstance()->closeGripper();
}

bool CloseGripper::isFinished(){
  return isTimedOut();
}

void CloseGripper::end(){  
}
