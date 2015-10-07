#include "PathPlanner.h"

#include "DriveThroughIntersection.h"
#include "DriveUntilReactorTube.h"
#include "TurnToNextLine.h"
#include "TurnUntilLine.h"
#include "TurnOffLine.h"
#include "Robot.h"

PathPlanner::PathPlanner(CommandGroup *path){
  this->path = path;
  this->row = Robot::getInstance()->row;
  this->col = Robot::getInstance()->col;
  this->direction = Robot::getInstance()->direction;
}

void PathPlanner::plan(int destRow, int destCol, int destDirection){
  int dist;

  if (col != destCol || row!=destRow){
    //first navigate to center line
    if (row != 1){
      //this must mean you're at the supply/storage tubes
      path->addSequential(new TurnToNextLine());
      path->addSequential(new DriveThroughIntersection());
    }
    else {
      //this must mean you're facing a reactor tube
      //or waiting in front of reactor tube
      planToFace(destDirection);
    }

    //note that we're in row 1 on the line
    row = 1;

    //now that we're on the line, navigate to our goal
    //first turn and face the right direction
    if (destCol > col){
      planToFace(1);
    }
    else if (destCol < col){
      planToFace(3);
    }

    //now drive through all the columns
    dist = abs(destCol - col);
    for (int i=0;i<dist;i++){
      path->addSequential(new DriveThroughIntersection());
    }

    //turn to face right direction for rows
    if (destRow > row){
      planToFace(2);
    }
    else if (destRow < row){
      planToFace(0);
    }

    //now drive through all the rows
    dist = abs(destRow - row);
    for (int i=0;i<dist;i++){
      path->addSequential(new DriveUntilReactorTube());
    }
  }
  else if (destDirection != direction){
    planToFace(direction);
  }
}

void PathPlanner::planToFace(int destDirection){
  // turning is dependant on location
  // some places (in from of storage/supply) don't have intersections
  if (row != 1){
    //at storage/supply, you can only by facing 0 or 2
    if (direction != destDirection){
      path->addSequential(new TurnToNextLine());
    }
  }
  else {
    int diff = destDirection - direction;
    int turnDirection = diff / abs(diff); //-1 for negative diff, 1 for positive diff

    //this is awful and hacky and I hate it
    if (abs(diff) == 3){
      diff = diff / -3;
    }
    for (int i=0;i<abs(diff);i++){
      path->addSequential(new TurnOffLine(turnDirection));
      path->addSequential(new TurnUntilLine(turnDirection));
    }
    direction = destDirection;
  }
}
