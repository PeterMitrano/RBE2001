#include "Gripper.h"

#include <Arduino.h>

void Gripper::setup(){
  motor.attach(motorPin,1000,2000);
}

void Gripper::cls(){
  motor.write(170);
}

void Gripper::opn(){
  motor.write(10);
}
