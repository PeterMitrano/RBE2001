#include "Arm.h"

Arm::Arm() : encoder(encAPin, encBPin), gripper() {}

void Arm::setup() {
  pinMode(motorFwdPin, OUTPUT);
  pinMode(motorRevPin, OUTPUT);
  pinMode(limPin, INPUT_PULLUP);

  gripper.setup();
}

void Arm::control(){
  if (calibrated){
    unsigned long t = millis();
    unsigned long dt = t - oldTime;
    if (dt > 50l){
      long pos = position();
      long error = setpoint - pos;

      integral += error;
      int val = kP * error + kI * integral;

      drive(val);
      lastError = error;
      oldTime = t;
    }
  }
}

void Arm::stop(){
  drive(0);
}

void Arm::up(){
  setpoint = UP_POSITION;
}

void Arm::down(){
  setpoint = DOWN_POSITION;
}

void Arm::rawDown(){
  drive(-60);
}

bool Arm::atPosition(){
  int diff = abs(position() - setpoint);
  return diff < tolerance;
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
  if (power > 100) power = 100;
  if (power < -100) power = -100;


  if (power == 0) {
    analogWrite(motorFwdPin, 0);
    analogWrite(motorRevPin, 0);
  }
  else if (power > 0) {
    int fwdAdjusted = map(power, 0, 100, 0, 200);
    analogWrite(motorRevPin, 0);
    analogWrite(motorFwdPin, fwdAdjusted);
  }
  else if (power < 0) {
    if (!atLim()){
      int revAdjusted = map(power, -100, 0, 200, 0);
      analogWrite(motorFwdPin, 0);
      analogWrite(motorRevPin, revAdjusted);
    }
    else {
      analogWrite(motorFwdPin, 0);
      analogWrite(motorRevPin, 0);
    }
  }
}
