#include "Calibrate.h"

Calibrate::Calibrate() : Command("calibrating"){
  minVal = 10000;
  maxVal = 0;
}

void Calibrate::initialize(){
  setTimeout(Robot::CALIBRATE_TIME);
}

void Calibrate::execute(){
  Robot::getInstance()->rotateLeft();
  int val = Robot::getInstance()->lineSensor.calibratingValue();
  if (val < minVal) minVal = val;
  if (val > maxVal) maxVal = val;
}

bool Calibrate::isFinished(){
  return isTimedOut();
}

void Calibrate::end(){
  Robot::getInstance()->lineSensor.setMinMax(minVal, maxVal);
  Robot::getInstance()->stopDriving();
}
