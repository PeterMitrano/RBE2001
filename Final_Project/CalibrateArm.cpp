#include "CalibrateArm.h"

CalibrateArm::CalibrateArm() : Command("calibrate arm"){}

void CalibrateArm::initialize(){
}

void CalibrateArm::execute(){
  Robot::getInstance()->arm.rawDown();
}

bool CalibrateArm::isFinished(){
  return Robot::getInstance()->arm.atLim();
}

void CalibrateArm::end(){
  Robot::getInstance()->arm.stop();
  Robot::getInstance()->arm.resetEncoder();
}
