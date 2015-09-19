#include "Robot.h"

int Robot::TEAM_NUMBER = 1;

State Robot::SETUP("setup"),
      Robot::PAUSED("paused"),
      Robot::CALIBRATING("calibrating");

State Robot::state("null");

void Robot::setup() {
  leftWheel.attach(leftWheelPin);
  rightWheel.attach(rightWheelPin);

  pinMode(limitPin, INPUT_PULLUP);

  lineSensor.setup();
  arm.setup();

  Robot::state = Robot::SETUP;

  //setup kill switch
  attachInterrupt(pausePin, pause, RISING);
}

void Robot::pause() {
  Robot::state = Robot::PAUSED;
}

void Robot::printState() {
  Serial.print("robot state: ");
  Serial.println(Robot::state.toString());
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

bool Robot::driveUntilLine(unsigned long timeout) {

  int t0 = state.initValue("t0",millis()); //safe to call repeatedly
  bool infinite = state.initValue("infinite", timeout == 0 );

  bool done = ((!infinite && (millis() - t0 < timeout)) || !lineSensor.atIntersection());

  if (done){
    followLine();
  }

  return (infinite || (millis() - t0 < timeout));
}

void Robot::driveUntilLine() {
  driveUntilLine(0);
}

bool Robot::driveUntilReactorTube(unsigned long timeout) {
  //grab millis() and timeout once and persiste their values in t0 and infinite 
  int t0 = state.persist(millis());
  bool infinite = state.persist(timeout == 0);

  bool done = ((!infinite && (millis() - t0 < timeout)) || !digitalRead(reactor_tube_limit_pin)) {

  if (done){
    followLine();
  }

  return (infinite || (millis() - t0 < timeout));
}

void Robot::followLine() {
  int leftPower = (int)(lineSensor.avgLeftIntensity() * travelSpeed);
  int rightPower = lineSensor.avgRightIntensity() * travelSpeed;
  drive(leftPower, rightPower);
}

void turnAround(){
  if (lineSensor.leftSideOnLine()){
    rotateRight();
  }
  else if (!lineSensor.leftSideOnLine()){
    rotateRight()
  }
}

bool Robot::doneTravelling() {
  return !digitalRead(limitPin);
}

void Robot::rotateRightUntilLine() {
  if (!lineSensor.onLine()) {
    rotateRight();
  }
}

void Robot::rotateLeftUntilLine() {
  if (!lineSensor.onLine()) {
    rotateLeft();
  }
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

/* state machine functions */
bool Robot::is(State s) {
  return Robot::state == s;
}

bool Robot::isNot(State s) {
  return Robot::state != s;
}

bool Robot::isDone(State s) {
  return Robot::state.isAfter(s);
}

bool Robot::isNotDone(State s) {
  return Robot::state.isBefore(s);
}
