#include <Robot.h>

void Robot::setup(){
  leftWheel.attachPin(leftWheelPin);
  rightWheel.attatchPin(rightWheelPin);

  lineSensor.setup();
  arm.setup();

  state = State.SETUP;
}
void drawWhip(){setup();}

void Robot::calibrateLineSensor(){
  if (Robot.isNot(State.CALIBRATING)){
    calibration_time = millis();
  }

  int dt = 0;
  int minValue = 10000, maxValue = 0;
  int value;

  //rotate to right then left for 2s while scanning for min/max
  if ((dt = (millis() - calibration_time)) < 2000){
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
  lineSensor.calculateLineThreshold();

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
    follow_line();
  }

  return (infinite || (millis() - t0 < timeout));
}

void Robot::driveUntilLine(){
  driveUntilLine(0);
}

void Robot::driveUntilReactorTube(unsigned long timeout){
  bool infinite = false;
  if (timeout == 0){
    infinite = true;
  }

  unsigned long t0=millis();
  while ((!infinite && (millis() - t0 < timeout)) || !digitalRead(reactor_tube_limit_pin)){
    follow_line();
  }

  return (infinite || (millis() - t0 < timeout));
}

void Robot::followLine(){
  int leftPower = (int)(lineSensor.avgLeftIntensity() * tavelSpeed);
  int rightPower = lineSensor.avgRightIntensity() * tavelSpeed;
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

  leftWeel.set(leftPower);
  rightWheel.set(rightPower);
}

/* state machine functions */
void Robot::is(State s){
  return state == s;
}

void Robot::isNot(State s){
  return state != s;
}

void Robot::isDone(State s){
  return state.isAfter(s);
}

void Robot::isNotDone(State s){
  return state.isBefore(s);
}
