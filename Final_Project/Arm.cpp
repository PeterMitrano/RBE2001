#include "Arm.h"
#include "Robot.h"

Arm::Arm() : gripper() {
  derivative = -1;
  setpoint = 500;
}

void Arm::setup() {
  pinMode(motorFwdPin, OUTPUT);
  pinMode(motorRevPin, OUTPUT);

  gripper.setup();
}

void Arm::control(){
  unsigned long t = millis();
  unsigned long dt = t - lastControlTime;

  // since loop can vary in execution time, we wait for CONTROL_TIME to update PID
  // this could easily be replaced by dividing by loop time for integral and derivative, but this was easier
  if (dt > CONTROL_TIME){
    long pos = position();
    long error = setpoint - pos;

    if ((error > 0 && lastError < 0) || (error < 0 && lastError > 0)){
      integral = 0;
    }

    integral += error;

    //integral cap
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
  return diff < TOLERANCE;
}

int Arm::position(){
  return analogRead(potPin);
}

void Arm::drive(int power) {
  // limit the power
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
}
