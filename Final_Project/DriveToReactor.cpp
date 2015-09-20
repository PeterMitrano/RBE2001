#include "DriveToReactor.h"

DriveToReactor::DriveToReactor(){}

void DriveToReactor::Initialize(){}

void DriveToReactor::Execute(){
  Robot::getInstance()->followLine();
}

bool DriveToReactor::IsFinished(){
  return Robot::getInstance()->atIntersecion();
}

void DriveToReactor::End(){
  Robot::getInstance()->stopDriving();
}

