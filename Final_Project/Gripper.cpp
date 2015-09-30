#include "Gripper.h"

#include "Robot.h"
#include <Arduino.h>

void Gripper::setup(){
  motor.attach(motorPin,1000,2000);
}

void Gripper::cls(){
  motor.write(170);
  Robot::getInstance()->btClient.gripperStatus = 1;
}

void Gripper::opn(){
  Robot::getInstance()->btClient.gripperStatus = 2;
  motor.write(10);
}
