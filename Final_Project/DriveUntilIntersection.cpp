#include "DriveUntilIntersection.h"

DriveUntilIntersection::DriveUntilIntersection() : Command("drive until intersection"){

}

void DriveUntilIntersection::initialize(){
  Robot::getInstance()->setSong(3,true);
}

void DriveUntilIntersection::execute(){
  Robot::getInstance()->followLine();
}

bool DriveUntilIntersection::isFinished(){
  return Robot::getInstance()->lineSensor.atIntersection();
}

void DriveUntilIntersection::end(){
  Robot::getInstance()->stopDriving();
}
