#include "Command.h"

#include "Scheduler.h"

Command::Command() : initialized(false) {}

Command::Command(String name) : initialized(false), name(name), startTime(millis()) {}

bool Command::cycle() {
//  Serial.print("command: ");
//  Serial.println(name);
  bool finished = false;

  if (!initialized) {
    initialize();
    _initialize();
    initialized = true;
  }
  else if (isFinished()) {
    finished = true;
    end();
    _end();
  }
  else {
    execute();
    _execute();
  }


  return finished;
}

void Command::setTimeout(unsigned long timeout) {
  this->timeout = timeout;
}

unsigned long Command::getTime() {
  return millis() - startTime;
}

bool Command::isTimedOut() {
  return getTime() > timeout;
}

bool Command::isRunning() {
  return running;
}

void Command::_initialize() {
  running = true;
  startTime = millis();
}

void Command::_execute() {}

void Command::_end() {
  running = false;
}

void Command::start() {
  Scheduler::getInstance()->addCommand(this);
}