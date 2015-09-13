#include <Gripper.h>

void Gripper::setup(){
  motor.attachPin(motorPin);
}

bool grabRod(){
  close();
  return hasRod();
}

bool releaseRod(){
  open();
  return !hasRod();
}

void Gripper::close(){
  motor.set(0);
}

void Gripper::open(){
  motor.set(180);
}

bool hasRod(){
  return !digitalRead(rodSensorPin);
}
