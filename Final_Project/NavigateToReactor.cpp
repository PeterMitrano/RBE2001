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

  if (reactorNumber == 2){
    destCol = 4;
    destDirection = 1;
  }

  CommandGroup *path = new CommandGroup();
  //this function will add things to path
  PathPlanner *planner = new PathPlanner(path);
  planner->plan(destRow, destCol, destDirection);

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
