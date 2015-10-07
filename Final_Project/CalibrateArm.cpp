#include "CalibrateArm.h"

CalibrateArm::CalibrateArm() : Command("calibrate arm"){}

void CalibrateArm::initialize(){
  Robot::getInstance()->setSong(16,true);
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
  Robot::getInstance()->arm.calibrated = true;
}
