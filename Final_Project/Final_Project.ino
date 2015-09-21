#include <Servo.h> //dummy include because arduino IDE is shit
#include <BluetoothMaster.h>
#include <ReactorProtocol.h>

#include "Robot.h"
#include "Scheduler.h"
#include "Util.h"

void setup() {
  Serial.begin(9600);
  Robot::getInstance()->setup();

  GetDemRods *gdr = new GetDemRods();
  gdr->start();
}

void loop() {
  Scheduler::getInstance()->run();
}
