#include "RaiseArm.h"

RaiseArm::RaiseArm() : Command("raise arm") {}

void RaiseArm::initialize(){
  Robot::getInstance()->arm.up();
}

void RaiseArm::execute(){
}
bool RaiseArm::isFinished(){
  return Robot::getInstance()->arm.atPosition();
}

void RaiseArm::end(){
  Robot::getInstance()->arm.stop();
}
