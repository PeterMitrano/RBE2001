#include "Scheduler.h"

Scheduler::Scheduler(){}

Scheduler *Scheduler::getInstance(){
  static Scheduler instance;
  return &instance;
}

void Scheduler::addCommand(Command *command){
  if (!commands.contains(command)){
    commands.add(command);
  }
}

void Scheduler::run(){
  //loop through commands and either init, execute, or end
  for (int i=0;i<commands.size();i++){
    Command *command = commands.get(i);
    bool isFinished = command->run();
    if (isFinished){
      commands.remove(i);
    }
  }
}
