#include "TurnToNextLine.h"

#include "TurnToEdge.h"
#include "PathPlanner.h"
#include "TurnUntilLine.h"

TurnToNextLine::TurnToNextLine(int direction) : CommandGroup("turn to next line"){
  if (direction == PathPlanner::CW){
    addSequential(new TurnToEdge(LineSensor::LEFT_EDGE, PathPlanner::CW));
    addSequential(new TurnToEdge(LineSensor::RIGHT_EDGE, PathPlanner::CW));
    addSequential(new TurnUntilLine(PathPlanner::CW));
  }
  else if (direction == PathPlanner::CCW){
    addSequential(new TurnToEdge(LineSensor::RIGHT_EDGE, PathPlanner::CCW));
    addSequential(new TurnToEdge(LineSensor::LEFT_EDGE, PathPlanner::CCW));
    addSequential(new TurnUntilLine(PathPlanner::CCW));
  }
}

TurnToNextLine::TurnToNextLine() : TurnToNextLine(PathPlanner::CW){
}

void TurnToNextLine::end(){
}
