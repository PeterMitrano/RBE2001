#include "NavigateToReactor.h"
#include "Robot.h"
#include "PathPlanner.h"

NavigateToReactor::NavigatToReactor(int reactorNumber : Command("nav to reactor"){
  this->reactorNumber = reactorNumber;
}

void NavigateToReactor::initialize(){
  //length 2 array, row column
  int *position = Robot::getInstance()->fieldPosition();
  int currentRow = position[0];
  int currentCol = position[1];

  //row is 1 for both reactors, and defualt col to 0
  //which is reactor 1
  int destRow = 1, destCol = 0;

  if (reactorNumber == 2){
    destCol = 4;
  }

  CommandGroup path = PathPlanner::generatePathBetween(currentRow,currentCol,destRow,destCol);
  path->start(); //tell scheduler to run this group of commands
}

void NavigateToReactor::execute(){
}

bool NavigateToReactor::isFinished(){
  //all we want is to start the path CommandGroup
  return true;
}

void NavigateToReactor::end(){
}
