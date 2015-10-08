#include "TurnUntilLine.h"

TurnUntilLine::TurnUntilLine(int direction) : Command("turn unti line"){
  this->direction = direction;
}

void TurnUntilLine::initialize(){
  Robot::getInstance()->setSong(2,false);
}

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
    return Robot::getInstance()->lineSensor.onLine();
  }
  else {
    return Robot::getInstance()->lineSensor.onLine();
  }
}

void TurnUntilLine::end(){
  Robot::getInstance()->stopDriving();
}
