#include "Gripper.h"

#include "Robot.h"
#include <Arduino.h>
#include "CloseGripper.h"

void Gripper::setup(){
  motor.attach(motorPin,1000,2000);
}

void Gripper::cls(int force = CloseGripper::SOFT){
  motor.write(force);
}

void Gripper::opn(){
  motor.write(0);
}
