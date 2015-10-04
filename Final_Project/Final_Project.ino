#include <Servo.h> //dummy include because arduino IDE is shit
#include <Encoder.h>
#include <BluetoothMaster.h>
#include <ReactorProtocol.h>

#include "Robot.h"
#include "Scheduler.h"

#include "GetDemRods.h"

Robot *steve = Robot::getInstance();

void setup() {
  Serial.begin(9600);

  steve->setup();

  // here we start the parent commands which should run throughout the life of the program
  GetDemRods *cmd = new GetDemRods();
  cmd->start();
}

void loop() {
  // Scheduler is in charge of running all the commands, so it must always be called
  Scheduler::getInstance()->run();

  // we also a few special functions, like cache and controlArm, which must run continuously, outside of all commands
  // while these could be done with commands, it's easier to just functions
  steve->playSong();
  steve->btClient.readMessage();
  steve->btClient.sendHeartbeat();
  steve->lineSensor.cache();
  steve->blinkLEDs();
  steve->arm.control();
  steve->resetTimerFlags();
}
