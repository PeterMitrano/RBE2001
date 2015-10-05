#include "PathPlanner.h"

#include "DriveUntilIntersection.h"
#include "TurnAround.h"
#include "TurnUntilLine.h"
#include "TurnOffLine.h"
#include "Robot.h"

PathPlanner::PathPlanner(int row, int col, int currentDirection, CommandGroup *path){
  this->path = path;
  this->row = row;
  this->col = col;
  this->direction = currentDirection;
}

void PathPlanner::plan(int destRow, int destCol, int destDirection){
  int dist;

  if (col != destCol || row!=destRow){
    //first navigate to center line
    if (row != 1){
      //this must mean you're at the supply/storage tubes
      path->addSequential(new TurnAround());
      path->addSequential(new DriveThroughIntersection());
    }
    else {
      //this must mean you're facing a reactor tube
      path->addSequential(new TurnAround());
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
      path->addSequential(new DriveUntilIntersection());
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
      path->addSequential(new DriveUntilIntersection());
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
      path->addSequential(new TurnAround());
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
  }
}
