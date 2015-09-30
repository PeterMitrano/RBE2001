#include "Drive.h"

Drive::Drive() : Command("drive"){}

void Drive::initialize(){}

void Drive::execute(){
  Robot::getInstance()->driveFwd();
}

bool Drive::isFinished(){
  return false;
}

void Drive::end(){}
