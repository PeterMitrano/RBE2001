#include "Robot.h"

Robot *Robot::instance = NULL;

Robot::Robot(){
  direction = 2;
  row = 1;
  col = 1;
}

Robot *Robot::getInstance(){
  if (instance == NULL){
    instance = new Robot();
    instance->btClient = new BTClient();
    instance->arm = new Arm();
    instance->lineSensor = new LineSensor();
  }
  return instance;
}

void Robot::setup() {

  radiating = true;
  paused = false;

  pinMode(reactorTubeLimitPin, INPUT_PULLUP);
  pinMode(LED_PIN0, OUTPUT);
  pinMode(LED_PIN1, OUTPUT);

  lineSensor->setup();
  arm->setup();
}

void Robot::stopDriving(){
  drive(0,0);
}

void Robot::followLine() {
  int leftPower = -(lineSensor->avgLeftIntensity() * travelSpeed) / 100;
  int rightPower = -(lineSensor->avgRightIntensity() * travelSpeed) / 100;
  drive(leftPower, rightPower);
}

void Robot::rotateLeft() {
  drive(rotateSpeed, -rotateSpeed);
}

void Robot::rotateRight() {
  drive(-rotateSpeed, rotateSpeed);
}


void Robot::drive(int leftPower, int rightPower) {
  if (leftPower > 100) {
    leftPower = 100;
  }

  if (leftPower < -100) {
    leftPower = -100;
  }

  if (rightPower > 100) {
    rightPower = 100;
  }

  if (rightPower < -100) {
    rightPower = -100;
  }

  int leftPowerScaled = 90 - leftPower * 0.9;
  int rightPowerScaled = 90 + rightPower * 0.9;

  if (!paused){
    leftWheel.write(leftPowerScaled);
    rightWheel.write(rightPowerScaled);
  }
  else {
    leftWheel.write(90);
    rightWheel.write(90);
  }
}

bool Robot::atFuelRod(){
  return digitalRead(reactorTubeLimitPin);
}
