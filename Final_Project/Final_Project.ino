#include <Servo.h> //dummy include because arduino IDE is shit
#include <BluetoothMaster.h>
#include <ReactorProtocol.h>

#include "Robot.h"
#include "Scheduler.h"
#include "Util.h"

#include "GetDemRods.h"
#include "BlinkLED.h"

void setup() {
  Serial.begin(9600);

  Robot::getInstance()->setup();

  //servos must be attached here
  Robot::getInstance()->leftWheel.attach(Robot::leftWheelPin);
  Robot::getInstance()->rightWheel.attach(Robot::rightWheelPin);

  //add first command
  GetDemRods *cmd = new GetDemRods();
  cmd->start();
  //add continuous (infinite) commands
  BlinkLED *blink = new BlinkLED();
  // blink->start();
}

void loop() {
  Scheduler::getInstance()->run();
//  Robot::getInstance()->btClient->readMessage();

}
