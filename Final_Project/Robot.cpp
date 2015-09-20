#include "Robot.h"

Robot *Robot::getInstance(){
  static Robot robot;
  return robot;
}

void Robot::setup() {
  leftWheel.attach(leftWheelPin);
  rightWheel.attach(rightWheelPin);

  pinMode(limitPin, INPUT_PULLUP);

  lineSensor.setup();
  arm.setup();


  //setup kill switch
  attachInterrupt(pausePin, pause, RISING);
}

void Robot::calibrateLineSensor() {
  if (isNot(Robot::CALIBRATING)) {
    calibrationTime = millis();
  }

  int dt = 0;
  int minValue = 10000, maxValue = 0;
  int value;

  //rotate to right then left for 2s while scanning for min/max
  if ((dt = (millis() - calibrationTime)) < 2000) {
    //grab the center sensor to calibrate
    value = lineSensor.rawCenterSensor();


    if (dt < 1000) {
      rotateLeft(); //fixed power rotate
    }
    else {
      rotateRight(); //fixed power rotate
    }

    if (value < minValue) {
      minValue = value;
    }

    if (value > maxValue) {
      maxValue = value;
    }
  }

  //set the line sensor parameters
  lineSensor.setMin(minValue);
  lineSensor.setMax(maxValue);
  lineSensor.calculateThreshold();

  //find the line again
  rotateRightUntilLine();
}

void Robot::stopDriving(){
  drive(0,0);
}

void Robot::followLine() {
  int leftPower = (int)(lineSensor.avgLeftIntensity() * travelSpeed);
  int rightPower = lineSensor.avgRightIntensity() * travelSpeed;
  drive(leftPower, rightPower);
}

bool Robot::doneTravelling() {
  return !digitalRead(limitPin);
}

void Robot::rotateLeft() {
  drive(-rotateSpeed, rotateSpeed);
}

void Robot::rotateRight() {
  drive(rotateSpeed, -rotateSpeed);
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


  int leftPowerScaled = map(leftPower, -100, 100, 180, 0);
  int rightPowerScaled = map(rightPower, -100, 100, 0, 180);

  leftWheel.write(leftPowerScaled);
  rightWheel.write(rightPowerScaled);
}

bool Robot::atIntersection(){
  return lineSensor->atIntersection();
}

bool Robot::atFuelRod(){
  return digitalRead(reactorTubeLimitPin);
}

void Robot::lowerArm(){
  arm.down();
}

void Robot::raiseArm(){
  arm.up();
}

void Robot::closeGripper(){
  arm.closeGripper();
}

void Robot::openGripper(){
  arm.openGripper();
}
