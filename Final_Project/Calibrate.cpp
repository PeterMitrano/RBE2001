#include "Calibrate.h"

Calibrate::Calibrate() : Command("calibrating"){
  minVal = 10000;
  maxVal = 0;
}

void Calibrate::initialize(){
  setTimeout(2000);
  Robot::getInstance()->rotateLeft();
}

void Calibrate::execute(){
  int val = Robot::getInstance()->lineSensor->calibratingValue();
  if (val < minVal) minVal = val;
  if (val > maxVal) maxVal = val;
}

bool Calibrate::isFinished(){
  return isTimedOut();
}

void Calibrate::end(){
  Robot::getInstance()->lineSensor->setMinMax(minVal, maxVal);
  Robot::getInstance()->stopDriving();
}
