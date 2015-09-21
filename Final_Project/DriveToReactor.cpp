#include "DriveToReactor.h"

DriveToReactor::DriveToReactor(){}

void DriveToReactor::initialize(){}

void DriveToReactor::execute(){
  Robot::getInstance()->followLine();
}

bool DriveToReactor::isFinished(){
  return Robot::getInstance()->lineSensor->atIntersection();
}

void DriveToReactor::end(){
  Robot::getInstance()->stopDriving();
}

