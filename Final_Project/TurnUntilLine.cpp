#include "TurnUntilLine.h"
#include "PathPlanner.h"

TurnUntilLine::TurnUntilLine(int direction) : Command("turn unti line"){
  this->direction = direction;
}

void TurnUntilLine::initialize(){
  Robot::getInstance()->setSong(2,false);
}

void TurnUntilLine::execute(){
  if (direction == PathPlanner::CCW){
    Robot::getInstance()->rotateCCW();
  }
  else if (direction == PathPlanner::CW){
    Robot::getInstance()->rotateCW();
  }
}

bool TurnUntilLine::isFinished(){
  if (direction == PathPlanner::CCW){
    return Robot::getInstance()->lineSensor.onLine();
  }
  else if (direction == PathPlanner::CW){
    return Robot::getInstance()->lineSensor.onLine();
  }
}

void TurnUntilLine::end(){
  Robot::getInstance()->stopDriving();
}
