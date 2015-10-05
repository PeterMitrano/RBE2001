#include "NavigateToOpenStorage.h"

NavigateToOpenStorage::NavigateToOpenStorage() : Command("nav to storage"){}

void NavigateToOpenStorage::initialize(){
  //figure out which one we want to navigate to
  int tubeNumber = Robot::getInstance()->btClient.openStorageTube();
}

void NavigateToOpenStorage::execute(){

}

bool NavigateToOpenStorage::isFinished(){

}

void NavigateToOpenStorage::end(){

}
