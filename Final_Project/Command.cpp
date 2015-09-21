#include "Command.h"

#include "Scheduler.h"

bool Command::run(){
  if (!initialized){
    initialize();
    initialized = true;
  }
  else if (isFinished()){
    end();
  }
  else {
    execute();
  }

  return isFinished();
}

void Command::setTimeout(unsigned long timeout){
  this->timeout = timeout;
}

unsigned long Command::getTime(){
  return millis() - startTime;
}

bool Command::isTimedOut(){
  return getTime() > timeout;
}

void Command::initialize(){
  startTime = millis();
}

void Command::execute(){
}

bool Command::isFinished(){
  return false; //unless specified, all commands are infinite
}

void Command::start(){
  Scheduler::getInstance()->addCommand(this);
}
