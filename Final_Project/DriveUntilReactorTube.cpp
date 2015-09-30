#include "DriveUntilReactorTube.h"

DriveUntilReactorTube::DriveUntilReactorTube() : Command("drive until reactor tube"){}

void DriveUntilReactorTube::initialize(){

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
