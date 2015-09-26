#include "TurnToFace.h"

TurnToFace::TurnToFace(int destDirection){
  this->destDirection = destDirection;
}

void TurnToFace::initialize(){
  int currentDirection = Robot::getInstance()->direction;
  timesToTurn = currentDirection - destDirection;
  //if turning N to W, 3 - 0 = turn 3 times;
}

void TurnToFace::execute(){
}

bool TurnToFace::isFinished(){
}

void TurnToFace::end(){
  Robot::getInstance()->stopDriving();
}
