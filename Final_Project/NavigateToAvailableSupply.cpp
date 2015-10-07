#include "NavigateToAvailableSupply.h"
#include "PathPlanner.h"

NavigateToAvailableSupply::NavigateToAvailableSupply() : Command("nav to storage"){}

void NavigateToAvailableSupply::initialize(){
  //figure out which one we want to navigate to
  tubeNumber = Robot::getInstance()->btClient.openStorageTube();
  Serial.print("tube number =				 ");
  Serial.println(tubeNumber);
}

void NavigateToAvailableSupply::execute(){
  if (tubeNumber >= 1 && tubeNumber <= 4){
    plannedSuccessfully = true;
    CommandGroup *path = new CommandGroup();
    //this function will add things to path
    PathPlanner *planner = new PathPlanner(path);
    planner->plan(0, tubeNumber, 0);

    for (int i=0;i<path->commands.size();i++){
      Serial.print("  ");
      Serial.println(path->commands.get(i)._command->name);
    }
    Serial.println("...]");
    path->start();
  }
  else {
    tubeNumber = Robot::getInstance()->btClient.openStorageTube();
  }
}

bool NavigateToAvailableSupply::isFinished(){
  return plannedSuccessfully;
}

void NavigateToAvailableSupply::end(){
  Robot::getInstance()->setSong(10,false);
}
