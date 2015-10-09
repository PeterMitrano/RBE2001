#include "TurnToNextLine.h"

#include "TurnOffLine.h"
#include "TurnUntilLine.h"
#include "PathPlanner.h"

TurnToNextLine::TurnToNextLine(int direction) : CommandGroup("turn around"){
  //0 represents clockwise
  //1 represent counter clockwise
  this->direction = direction;
  addSequential(new TurnOffLine(direction));
  addSequential(new TurnUntilLine(direction));
}

TurnToNextLine::TurnToNextLine() : TurnToNextLine(PathPlanner::CW){
}

void TurnToNextLine::end(){
  Robot::getInstance()->direction += direction;
}
