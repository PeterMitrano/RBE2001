#include "PathPlanner.h"

#include "DriveUntilIntersection.h"
#include "TurnAround.h"
#include "TurnToFace.h"

void PathPlanner::plan(int currentRow, int currentCol,int destDirection, int destRow, int destCol, CommandGroup *path){
  int dist;

  if (currentCol != destCol || currentRow!=destRow){
    //first navigate to center line
    if (currentRow != 1){
      //this must mean you're facing the supply/storage tubes
      path->addSequential(new TurnAround(1));
      path->addSequential(new DriveUntilIntersection());
    }
    else {
      //this must mean you're facing a reactor tube
      path->addSequential(new TurnAround(1));
    }

    //note that we're in row 1 on the line
    currentRow = 1;

    //now that we're on the line, navigate to our goal
    //first turn and face the right direction
    if (destCol > currentCol){
      path->addSequential(new TurnToFace(1));
    }
    else if (destCol < currentCol){
      path->addSequential(new TurnToFace(3));
    }

    //now drive through all the columns
    dist = abs(destCol - currentCol);
    for (int i=0;i<dist;i++){
      path->addSequential(new DriveUntilIntersection());
    }

    //turn to face right direction for rows
    if (destRow > currentRow){
      path->addSequential(new TurnToFace(2));
    }
    else if (destRow < currentRow){
      path->addSequential(new TurnToFace(0));
    }

    //now drive through all the rows
    dist = abs(destRow - currentRow);
    for (int i=0;i<dist;i++){
      path->addSequential(new DriveUntilIntersection());
    }
  }
}

