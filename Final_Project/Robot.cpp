#include "Robot.h"

void Robot::setup(){
  leftWheel.attach(leftWheelPin);
  rightWheel.attach(rightWheelPin);

  lineSensor.setup();
  arm.setup();

  state = Robot::SETUP;
}

void Robot::calibrateLineSensor(){
  if (isNot(Robot::CALIBRATING)){
    calibrationTime = millis();
  }

  int dt = 0;
  int minValue = 10000, maxValue = 0;
  int value;

  //rotate to right then left for 2s while scanning for min/max
  if ((dt = (millis() - calibrationTime)) < 2000){
    //grab the center sensor to calibrate
    value = lineSensor.rawCenterSensor();


    if (dt < 1000){
      rotateLeft(); //fixed power rotate
    }
    else {
      rotateRight(); //fixed power rotate
    }

    if (value < minValue){
      minValue = value;
    }

    if (value > maxValue){
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

bool Robot::driveUntilLine(unsigned long timeout){
  bool infinite = false;
  if (timeout == 0){
    infinite = true;
  }

  unsigned long t0 = millis();

  while ((!infinite && (millis() - t0 < timeout)) || !lineSensor.atIntersection()){
    followLine();
  }

  return (infinite || (millis() - t0 < timeout));
}

void Robot::driveUntilLine(){
  driveUntilLine(0);
}

bool Robot::driveUntilReactorTube(unsigned long timeout){
  bool infinite = false;
  if (timeout == 0){
    infinite = true;
  }

  unsigned long t0=millis();
  while ((!infinite && (millis() - t0 < timeout)) || !digitalRead(reactor_tube_limit_pin)){
    followLine();
  }

  return (infinite || (millis() - t0 < timeout));
}

void Robot::followLine(){
  int leftPower = (int)(lineSensor.avgLeftIntensity() * travelSpeed);
  int rightPower = lineSensor.avgRightIntensity() * travelSpeed;
  drive(leftPower,rightPower);
}

void Robot::rotateRightUntilLine(){
  while (!lineSensor.onLine()){
    rotateRight();
  }
}

void Robot::rotateLeftUntilLine(){
  while (!lineSensor.onLine()){
    rotateLeft();
  }
}

void Robot::rotateLeft(){
  drive(-rotateSpeed,rotateSpeed);
}

void Robot::rotateRight(){
  drive(rotateSpeed,-rotateSpeed);
}


void Robot::drive(int leftPower, int rightPower){
  if (leftPower > 1){
    leftPower = 1;
  }

  if (leftPower < -1){
    leftPower = -1;
  }

  if (rightPower > 1){
    rightPower = 1;
  }

  if (rightPower < -1){
    rightPower = -1;
  }

 int leftPowerScaled = map(leftPower,-1,1,0,180);
 int rightPowerScaled = map(rightPower,-1,1,0,180);

  leftWheel.write(leftPower);
  rightWheel.write(rightPower);
}

/* state machine functions */
bool Robot::is(State s){
  return state == s;
}

bool Robot::isNot(State s){
  return state != s;
}

bool Robot::isDone(State s){
  return state.isAfter(s);
}

bool Robot::isNotDone(State s){
  return state.isBefore(s);
}
