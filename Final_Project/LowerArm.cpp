#include "LowerArm.h"

void LowerArm::execute(){
  Robot::getInstance()->arm->down(); //uses a PI controller
}

bool LowerArm::isFinished(){
  abs(Robot::getInstance()->arm->position() - setpoint) < tolerance;
}

void LowerArm::end(){
  Robot::getInstance()->arm->stop();
}