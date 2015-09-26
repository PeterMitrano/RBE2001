#include "TurnUntilLine.h"

TurnUntilLine::TurnUntilLine(int direction) : Command("turn unti line"){
  this->direction = direction;
}

void TurnUntilLine::initialize(){}

void TurnUntilLine::execute(){
  if (direction == 1){
    Robot::getInstance()->rotateLeft();
  }
  else {
    Robot::getInstance()->rotateRight();
  }
}

bool TurnUntilLine::isFinished(){
  if (direction == 1){
    return Robot::getInstance()->lineSensor->leftSideOnLine();
  }
  else {
    return Robot::getInstance()->lineSensor->rightSideOnLine();
  }
}

void TurnUntilLine::end(){
  Robot::getInstance()->stopDriving();
}
