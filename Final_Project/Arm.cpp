#include "Arm.h"

void Arm::setup() {
  motor.attach(motorPin);

  gripper->setup();
}

void Arm::stop(){
  motor.write(0);
}

void Arm::up(){
  setPosition(UP_POSITION);
}

void Arm::down(){
  setPosition(DOWN_POSITION);
}

void Arm::setPosition(int setpoint) {
  int error = setpoint - position();
  integral += error;
  int val = kP * error + kI * integral;
  motor.write(val);
}

int Arm::position(){
  return -1;
}
