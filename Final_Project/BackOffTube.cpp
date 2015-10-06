#include "BackOffTube.h"

BackOffTube::BackOffTube() : Command("back off tube") {}

void BackOffTube::initialize(){
  setTimeout(1000);
  Robot::getInstance()->setSong(15,true);
}

void BackOffTube::execute(){
  Robot::getInstance()->backUp();
}

bool BackOffTube::isFinished(){
  return isTimedOut();
}

void BackOffTube::end(){}
