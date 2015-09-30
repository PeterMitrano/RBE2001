#include "Arm.h"

Arm::Arm() : encoder(encAPin, encBPin), gripper() {}

void Arm::setup() {
  pinMode(motorFwdPin, OUTPUT);
  pinMode(motorRevPin, OUTPUT);
  pinMode(limPin, INPUT_PULLUP);

  gripper.setup();
}

void Arm::stop(){
  drive(0);
}

void Arm::up(){
  setPosition(UP_POSITION);
}

void Arm::down(){
  setPosition(DOWN_POSITION);
}

void Arm::rawDown(){
  drive(-60);
}

void Arm::setPosition(int setpoint) {
  int error = setpoint - position();
  integral += error;
  int val = kP * error + kI * integral;
  drive(val);
}

int Arm::position(){
  return encoder.read();
}

void Arm::resetEncoder(){
  encoder.write(0);
}

bool Arm::atLim(){
  return !digitalRead(limPin);
}

void Arm::drive(int power) {
    if (power == 0) {
      analogWrite(motorFwdPin, 0);
      analogWrite(motorRevPin, 0);
    }
    else if (!atLim()){
      if (power > 0) {
        int fwdAdjusted = map(power, 0, 100, 0, 255);
        analogWrite(motorRevPin, 0);
        analogWrite(motorFwdPin, fwdAdjusted);
      }
      else if (power < 0) {
        int revAdjusted = map(power, -100, 0, 255, 0);
        analogWrite(motorFwdPin, 0);
        analogWrite(motorRevPin, revAdjusted);
      }
    }
}
