#include "End.h"

End::End() : Command("END!!!"){}

void End::initialize(){
  Robot::getInstance()->setSong(6, true);
}

void End::execute(){}

bool End::isFinished(){
  return true;
}

void End::end(){
  Robot::getInstance()->debugPrint("COMPLETE.");
}
