#include "DriveOverIntersection.h"

DriveOverIntersection::DriveOverIntersection() : Command("drive over intersection"){}

void DriveOverIntersection::initialize(){}

void DriveOverIntersection::execute(){
  //drive forward until the outer line snensors read white
	 Robot::getInstance()->driveFwd();
}

bool DriveOverIntersection::isFinished(){
  return !(Robot::getInstance()->lineSensor.atIntersection());
}

void DriveOverIntersection::end(){
  Robot::getInstance()->stopDriving();
}

