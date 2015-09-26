#include "DriveUntilIntersection.h"

DriveUntilIntersection::DriveUntilIntersection() : Command("drive until intersection"){

}

void DriveUntilIntersection::initialize(){
}

void DriveUntilIntersection::execute(){
  Robot::getInstance()->followLine();
}

bool DriveUntilIntersection::isFinished(){
  return false;
//  Robot::getInstance()->lineSensor->atIntersection();
}

void DriveUntilIntersection::end(){
  Robot::getInstance()->stopDriving();
}
