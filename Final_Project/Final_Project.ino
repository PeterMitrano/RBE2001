#include <Servo.h> //dummy include because arduino IDE is shit

#include "Robot.h"
#include "Scheduler.h"
#include "Util.h"

void setup() {
  Serial.begin(9600);
  Robot::getInstance()->setup();

  GrabRod *cmd = new GrabRod();
  cmd->start();
}

void loop() {
  Scheduler::getInstance()->run();
}
