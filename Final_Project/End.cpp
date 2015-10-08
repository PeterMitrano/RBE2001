#include "End.h"

End::End() : Command("END!!!"){}

void End::initialize(){
  Robot::getInstance()->pauseSong();
}

void End::execute(){}

bool End::isFinished(){
  return true;
}

void End::end(){
  Robot::getInstance()->debugPrint("ROUTINE COMPLETE.");
}
