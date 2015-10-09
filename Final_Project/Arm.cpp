#include "Arm.h"
#include "Robot.h"

Arm::Arm() : encoder(encAPin, encBPin), gripper() {
  derivative = -1;
  setpoint = 500;
}

void Arm::setup() {
  pinMode(motorFwdPin, OUTPUT);
  pinMode(motorRevPin, OUTPUT);
  pinMode(limPin, INPUT_PULLUP);

  gripper.setup();
}

void Arm::control(){
  unsigned long t = millis();
  unsigned long dt = t - lastControlTime;
  if (dt > CONTROL_TIME){
    long pos = position();
    long error = setpoint - pos;

    integral += error;
    integral = integral < MAX_INTEGRAL ? integral : MAX_INTEGRAL;
    integral = integral > -MAX_INTEGRAL ? integral : -MAX_INTEGRAL;
    derivative = error - lastError;

    int val = kP * error + kI * integral + kD * derivative;

    drive(val);
    lastError = error;
    lastControlTime = t;
  }
}

void Arm::down(){
  setpoint = DOWN_POSITION;
}

void Arm::up(){
  setpoint = UP_POSITION;
}

void Arm::stop(){
  drive(0);
}

bool Arm::atPosition(){
  int diff = abs(position() - setpoint);
  return diff < tolerance;
}

int Arm::_position(){
  return encoder.read();
}

int Arm::position(){
  return analogRead(potPin);
}

bool Arm::atLim(){
  return !digitalRead(limPin);
}

void Arm::rawDown(){
  drive(-60);
}

void Arm::resetEncoder(){
  encoder.write(0);
}

void Arm::drive(int power) {
  if (power > 100) power = 100;
  if (power < -100) power = -100;

  if (power == 0) {
    analogWrite(motorFwdPin, 0);
    analogWrite(motorRevPin, 0);
  }
  else if (power > 0) {
    int fwdAdjusted = map(power, 0, 100, 0, 255);
    analogWrite(motorRevPin, 0);
    analogWrite(motorFwdPin, fwdAdjusted);
  }
  else if (power < 0) {
    int revAdjusted = map(power, -100, 0, 255, 0);
    analogWrite(motorFwdPin, 0);
    analogWrite(motorRevPin, revAdjusted);
  }
  else {
    analogWrite(motorFwdPin, 0);
    analogWrite(motorRevPin, 0);
  }
}
