#include "NavigateToOpenStorage.h"
#include "PathPlanner.h"
#include "OpenGripper.h"
#include "BackOffTube.h"

NavigateToOpenStorage::NavigateToOpenStorage() : Command("nav to storage"){}

void NavigateToOpenStorage::initialize(){
  //figure out which one we want to navigate to
  tubeNumber = Robot::getInstance()->btClient.openStorageTube();
  plannedSuccessfully = false;
}

void NavigateToOpenStorage::execute(){
  if (tubeNumber >= 1 && tubeNumber <= 4){
    plannedSuccessfully = true;
    CommandGroup *path = new CommandGroup();
    //this function will add things to path
    PathPlanner *planner = new PathPlanner(path);
    planner->plan(2, tubeNumber, 2);

    for (int i=0;i<path->commands.size();i++){
      Serial.print("  ");
      Serial.println(path->commands.get(i)._command->name);
    }
    Serial.println("...]");
    path->addSequential(new OpenGripper());
    path->addSequential(new BackOffTube());
    path->start();
  }
  else {
    tubeNumber = Robot::getInstance()->btClient.openStorageTube();
  }
}

bool NavigateToOpenStorage::isFinished(){
  return plannedSuccessfully;
}

void NavigateToOpenStorage::end(){
  Robot::getInstance()->setSong(10,false);
}
