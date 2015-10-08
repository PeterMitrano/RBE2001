#include "Scheduler.h"

Scheduler *Scheduler::instance = NULL;

Scheduler::Scheduler() {}

Scheduler *Scheduler::getInstance() {
  if (instance == NULL){
    instance = new Scheduler();
  }
  return instance;
}

void Scheduler::addCommand(Command *command) {
  if (!commands.contains(command)) {
    commands.add(command);
  }
}

void Scheduler::run() {
  //loop through commands and either init, execute, or end
  for (int i = 0; i < commands.size(); i++) {
    Command *command = commands.get(i);
    bool finished = command->cycle();
    if (finished) {
     commands.remove(i);
    }
  }
}

void Scheduler::print(){
  for (int i = 0; i < commands.size(); i++) {
    Command *command = commands.get(i);
    Serial.print("...");
    Serial.println(command->name);
    command->print();
  }
}
