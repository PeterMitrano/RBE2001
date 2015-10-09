#include "PathPlanner.h"

#include "DriveThroughIntersection.h"
#include "DriveUntilReactorTube.h"
#include "TurnToNextLine.h"
#include "TurnUntilLine.h"
#include "TurnOffLine.h"
#include "Robot.h"

PathPlanner::PathPlanner(){
  this->path = new CommandGroup();
  this->row = Robot::getInstance()->row;
  this->col = Robot::getInstance()->col;
  this->direction = Robot::getInstance()->direction;
}

CommandGroup *PathPlanner::plan(int destRow, int destCol, int destDirection){
  int dist;

  Serial.print("starting at ");
  Serial.print(row);
  Serial.print(",");
  Serial.print(col);
  Serial.print(" facing ");
  Serial.println(direction);


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
      //planToFace(destDirection);
    }

    //now that we're on the line, navigate to our goal
    //first turn and face the right direction
    if (destCol > col){
      planToFace(EAST);
    }
    else if (destCol < col){
      planToFace(WEST);
    }

    //now drive through all the columns
    dist = abs(destCol - col);
    for (int i=0;i<dist;i++){
      path->addSequential(new DriveThroughIntersection());
    }

    //turn to face right direction for rows
    if (destRow > row){
      planToFace(SOUTH);
    }
    else if (destRow < row){
      planToFace(NORTH);
    }

    //now drive through all the rows
    path->addSequential(new DriveUntilReactorTube());
  }
  else if (destDirection != direction){
    planToFace(direction);
  }

  for (int i=0;i<path->commands.size();i++){
    Serial.print("  ");
    Serial.println(path->commands.get(i)->name);
  }
  Serial.println("...]");

  return path;
}

void PathPlanner::planToFace(int destDirection){
  Serial.print("   turn to face");
  Serial.println(destDirection);
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
      path->addSequential(new TurnToNextLine());
    }
  }
}
