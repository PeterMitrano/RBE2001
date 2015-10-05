#include "Robot.h"
#include <stdlib.h>
#include <Wire.h>

Robot *Robot::instance = NULL;
bool Robot::timeToBlinkAndSend = false;

Robot::Robot(){
  direction = 3;
  row = 1;
  col = 5;
}

Robot *Robot::getInstance(){
  if (instance == NULL){
    instance = new Robot();
  }
  return instance;
}

void Robot::setup(){
  paused = false;

  Wire.begin();

  leftWheel.attach(leftWheelPin,1000,2000);
  rightWheel.attach(rightWheelPin,1000,2000);

  pinMode(reactorTubeLimitPin, INPUT_PULLUP);
  pinMode(LED_PIN0, OUTPUT);
  pinMode(LED_PIN1, OUTPUT);

  lineSensor.setup();
  arm.setup();
  btClient.setup();

  Timer1.initialize(1000l * BLINK_AND_SEND_PERIOD);
  Timer1.attachInterrupt(&Robot::blinkAndSendInterrupt);
}

void Robot::blinkAndSendInterrupt(){
  timeToBlinkAndSend = true;
}

void Robot::blinkLEDs(){
  if (timeToBlinkAndSend){
    ledState = !ledState;
  }

  if (radiating){
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
  drive(travelSpeed,travelSpeed);
}


void Robot::driveBwd(){
  drive(-travelSpeed,-travelSpeed);

void Robot::followLine() {
  // linePosition is from about -2.5 to 2.5, with 0 being considered "on the line"
  // when linePosition is 0, left Power and Right power should be half travel_speed
  // when linePosition is -2.5, or far left, it should be full reverse travel_speed on right and full on left
  // when the linePosition is 2.5 or far right, it should be full reverse travel_speed on the left and full on right
  int leftPower = travelSpeed + lineSensor.linePosition * -adjustSpeed;
  int rightPower = travelSpeed + lineSensor.linePosition * adjustSpeed;
  Serial.print(leftPower);
  Serial.print(" ");
  Serial.println(rightPower);
  drive(leftPower, rightPower);
}

void Robot::rotateLeft() {
  drive(-rotateSpeed, rotateSpeed);
}

void Robot::rotateRight() {
  drive(rotateSpeed, -rotateSpeed);
}


void Robot::drive(int leftPower, int rightPower) {
  int leftPowerScaled = map(leftPower,-100,100,180,0);
  int rightPowerScaled = map(rightPower,-100,100,0,180);

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


void Robot::setSong(int trackNumber, bool repeat){
  songData = trackNumber;
  if (repeat){
    //highest order bit denotes repeat
    songData |= (1 << 7);
  }
}

void Robot::playSong(){
  if (timeToBlinkAndSend) {
    Wire.beginTransmission(::SLAVE_ID);
    Wire.write(songData);
    Wire.endTransmission();
  }
}

void Robot::pauseSong(){
  if (timeToBlinkAndSend) {
    Wire.beginTransmission(::SLAVE_ID);
    Wire.write(-1);
    Wire.endTransmission();
  }
}

void Robot::resetTimerFlags(){
  timeToBlinkAndSend = false;
}
