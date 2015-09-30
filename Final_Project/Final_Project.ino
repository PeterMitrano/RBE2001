#include <Servo.h> //dummy include because arduino IDE is shit
#include <BluetoothMaster.h>
#include <ReactorProtocol.h>

#include "Robot.h"
#include "Scheduler.h"

#include "GetDemRods.h"
#include "BlinkLED.h"

void setup() {
  Serial.begin(9600);

  Robot::getInstance()->setup();

  //add first command
  GetDemRods *cmd = new GetDemRods();
  cmd->start();

  BlinkLED *blink = new BlinkLED();
  blink->start();
}

void loop() {
  //required for any line stuff to work
  Robot::getInstance()->lineSensor.cache();
  Scheduler::getInstance()->run();
}
