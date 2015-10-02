#include "NavigateToReactor.h"
#include "DriveUntilIntersection.h"
#include "PathPlanner.h"
#include "Robot.h"

NavigateToReactor::NavigateToReactor(int reactorNumber) : Command("nav to Reactor"){
  this->reactorNumber = reactorNumber;
  //row is 1 for both reactors, and defualt col to 0
  //which is reactor 1
  //direction 3 is west
  destDirection = 3, destRow = 1, destCol = 0;
}

void NavigateToReactor::initialize(){
  //length 2 array, row column

  int currentRow = Robot::getInstance()->row;
  int currentCol = Robot::getInstance()->col;
  int currentDirection = Robot::getInstance()->direction;

  if (reactorNumber == 2){
    destCol = 4;
    destDirection = 1;
  }

  CommandGroup *path = new CommandGroup();
  //this function will add things to path
  PathPlanner::plan(currentRow, currentCol, destDirection, destRow, destCol,path);

  Serial.print("start at = ");
  Serial.print(currentRow);
  Serial.print(",");
  Serial.println(currentCol);

  Serial.print("end at = ");
  Serial.print(destRow);
  Serial.print(",");
  Serial.println(destCol);

  for (int i=0;i<path->commands.size();i++){
    Serial.print("  ");
    Serial.println(path->commands.get(i)._command->name);
  }
  Serial.println("...]");
  path->start(); //tell scheduler to run this group of commands
}

void NavigateToReactor::execute(){
}

bool NavigateToReactor::isFinished(){
  //all we want is to start the path CommandGroup
  return true;
}

void NavigateToReactor::end(){
  Robot::getInstance()->row = 1;
  Robot::getInstance()->col = destCol;
}
