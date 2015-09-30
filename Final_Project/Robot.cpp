#include "Robot.h"
#include <stdlib.h>

Robot *Robot::instance = NULL;

Robot::Robot(){
  direction = 2;
  row = 1;
  col = 1;
}

Robot *Robot::getInstance(){
  if (instance == NULL){
    instance = new Robot();
  }
  return instance;
}

void Robot::setup(){
  radiating = true;
  paused = false;

  leftWheel.attach(leftWheelPin,1000,2000);
  rightWheel.attach(rightWheelPin,1000,2000);

  pinMode(reactorTubeLimitPin, INPUT_PULLUP);
  pinMode(LED_PIN0, OUTPUT);
  pinMode(LED_PIN1, OUTPUT);

  lineSensor.setup();
  arm.setup();
}

void Robot::blinkLEDs(){
  //getTime is in millis since start of command
  if ((millis() / 200) % 2 == 0){
    ledState = HIGH;
  }
  else {
    ledState = LOW;
  }

  if (Robot::getInstance()->radiating){
    digitalWrite(Robot::LED_PIN1,ledState);
    digitalWrite(Robot::LED_PIN0,ledState);
  }
  else {
    digitalWrite(Robot::LED_PIN0,LOW);
    digitalWrite(Robot::LED_PIN1,LOW);
  }
}

void Robot::stopDriving(){
  drive(0,0);
}

void Robot::driveFwd(){
  rightWheel.write(120);
  leftWheel.write(120);
}

void Robot::followLine() {
  int leftPower = (lineSensor.avgLeftIntensity() * travelSpeed) / 100;
  int rightPower = (lineSensor.avgRightIntensity() * travelSpeed) / 100;
  drive(leftPower, rightPower);
}

void Robot::rotateLeft() {
  drive(rotateSpeed, -rotateSpeed);
}

void Robot::rotateRight() {
  drive(-rotateSpeed, rotateSpeed);
}


void Robot::drive(int leftPower, int rightPower) {
  int leftPowerScaled = map(leftPower,-100,100,0,180);
  int rightPowerScaled = map(rightPower,-100,100,180,0);

  if (!paused){
    leftWheel.write(leftPowerScaled);
    rightWheel.write(rightPowerScaled);
  }
  else {
    leftWheel.write(90);
    rightWheel.write(90);
  }
}

bool Robot::atReactorTube(){
  return !digitalRead(reactorTubeLimitPin);
}
