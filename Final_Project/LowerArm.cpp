#include "LowerArm.h"

LowerArm::LowerArm() : Command("lower arm") {}

void LowerArm::initialize(){
  Robot::getInstance()->arm.down();
}

void LowerArm::execute(){
}

bool LowerArm::isFinished(){
  return Robot::getInstance()->arm.atPosition();
}

void LowerArm::end(){
}
