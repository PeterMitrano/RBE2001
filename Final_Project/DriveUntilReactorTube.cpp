#include "DriveUntilReactorTube.h"

DriveUntilReactorTube::DriveUntilReactorTube() : Command("drive until reactor tube"){}

void DriveUntilReactorTube::initialize(){
  Robot::getInstance()->setSong(4, false);
}

void DriveUntilReactorTube::execute(){
  Robot::getInstance()->followLine();
}

bool DriveUntilReactorTube::isFinished(){
  return Robot::getInstance()->atReactorTube();
}

void DriveUntilReactorTube::end(){
  Robot::getInstance()->stopDriving();
}
