#include "Gripper.h"
#include <Arduino.h>

void Gripper::setup(){
  motor.attach(motorPin);
  pinMode(rodSensorPin,INPUT_PULLUP);
}

bool Gripper::grabRod(){
  cls();
  return hasRod();
}

bool Gripper::releaseRod(){
  opn();
  return !hasRod();
}

void Gripper::cls(){
  motor.write(0);
}

void Gripper::opn(){
  motor.write(180);
}

bool Gripper::hasRod(){
  return digitalRead(rodSensorPin);
}
