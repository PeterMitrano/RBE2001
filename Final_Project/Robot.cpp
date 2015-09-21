#include "Robot.h"

Robot::Robot(){}

Robot *Robot::getInstance(){
  static Robot robot;
  return &robot;
}

void Robot::setup() {
  gripperMotor.attach(3);
  gripperMotor.write(20);
  pinMode(4,INPUT_PULLUP);
  delay(1000);
}

void Robot::closeGripper(){
  gripperMotor.write(180);
}
