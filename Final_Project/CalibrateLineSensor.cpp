#include "CalibrateLineSensor.h"

CalibrateLineSensor::CalibrateLineSensor(){}

void CalibrateLineSensor::initialize(){
  setTimeout(CALIBRATE_TIME);
}

void CalibrateLineSensor::execute(){
  Robot::getInstance()->rotateLeft();
  Robot::getInstance()->lineSensor.calibrateLineSensors();
}

bool CalibrateLineSensor::isFinished(){
  return isTimedOut();
}

void CalibrateLineSensor::end(){
  Robot::getInstance()->stopDriving();
}
