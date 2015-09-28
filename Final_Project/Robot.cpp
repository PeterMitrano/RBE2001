#include "Robot.h"

Robot *Robot::instance = NULL;

Robot::Robot(){}

Robot *Robot::getInstance(){
  if (instance == NULL){
    instance = new Robot();
  }
  return instance;
}

void Robot::setup() {
  gripperMotor.attach(3);
  gripperMotor.write(20);
  pinMode(4,INPUT_PULLUP);
  delay(1000);
}

void Robot::openGripper(){
  gripperMotor.write(10);
}
void Robot::closeGripper(){
  gripperMotor.write(170);
}
