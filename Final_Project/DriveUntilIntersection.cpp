#include "DriveUntilIntersection.h"

DriveUntilIntersection::DriveUntilIntersection() : Command("drive until intersection"){

}

void DriveUntilIntersection::initialize(){
}

void DriveUntilIntersection::execute(){
  Robot::getInstance()->followLine();
}

bool DriveUntilIntersection::isFinished(){
  bool done = Robot::getInstance()->lineSensor->atIntersection();
  //return done;
  return false;
}

void DriveUntilIntersection::end(){
  Robot::getInstance()->stopDriving();
}
