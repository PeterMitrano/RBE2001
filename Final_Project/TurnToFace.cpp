#include "TurnToFace.h"

#include "CommandGroup.h"
#include "Turn.h"

// THIS NEEDS TO BE FIXED
// curently blindly turns

TurnToFace::TurnToFace(int destDirection) : Command("turn to face") {
  this->destDirection = destDirection;
}

void TurnToFace::initialize(){
  int currentDirection = Robot::getInstance()->direction;
  timesToTurn = currentDirection - destDirection;
  CommandGroup *turn = new CommandGroup();
  for (int i=0;i<timesToTurn;i++){
    turn->addSequential(new Turn(1,1200));
  }
  //if turning N to W, 3 - 0 = turn 3 times;
}

void TurnToFace::execute(){
}

bool TurnToFace::isFinished(){
}

void TurnToFace::end(){
  Robot::getInstance()->stopDriving();
}
