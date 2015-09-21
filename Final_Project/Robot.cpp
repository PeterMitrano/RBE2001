#include "Robot.h"

Robot::Robot(){}

Robot *Robot::getInstance(){
  static Robot robot;
  return &robot;
}

void Robot::setup() {
  gripperMotor.attach(3);
}

void Robot::closeGripper(){
  gripperMotor.write(180);
}
