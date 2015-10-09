#include "Robot.h"
#include "PathPlanner.h"
#include <stdlib.h>
#include <Wire.h>

Robot *Robot::instance = NULL;
bool Robot::timeToBlinkAndSend = false;

Robot::Robot() : lcd(40,41,42,43,44,45) {
  direction = PathPlanner::WEST;
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
  paused = false;

  Wire.begin();
  lcd.begin(16,2);

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
}

void Robot::followLine() {
  int leftPower = travelSpeed + lineSensor.adjustmentPower();
  int rightPower = travelSpeed - lineSensor.adjustmentPower();
  drive(leftPower, rightPower);
}

void Robot::backUp(int lPower, int rPower){
  drive(lPower,rPower);
}

void Robot::rotateCW() {
  drive(rotateSpeed, -rotateSpeed);
}

void Robot::rotateCCW() {
  drive(-rotateSpeed, rotateSpeed);
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
  songData = 0x00;
}

void Robot::resetTimerFlags(){
  timeToBlinkAndSend = false;
}

void Robot::debugPrint(int i){
  lcd.setCursor(0,0);
  char str[17];
  sprintf(str,"%-6i",i);
  lcd.print(str);
}

void Robot::debugPrint(char *s){
  lcd.setCursor(0,0);
  char str[17];
  sprintf(str,"%-6s",s);
  lcd.print(str);
}

void Robot::debugPrint2(int i){
  lcd.setCursor(0,1);
  char str[17];
  sprintf(str,"%-6i",i);
  lcd.print(str);
}

void Robot::debugPrint2(char *s){
  lcd.setCursor(0,1);
  char str[17];
  sprintf(str,"%-6s",s);
  lcd.print(str);
}

void Robot::incrementPosition(){
  switch(direction){
    case PathPlanner::NORTH:
      Robot::getInstance()->row++;
      break;
    case PathPlanner::EAST:
      Robot::getInstance()->col++;
      break;
    case PathPlanner::SOUTH:
      Robot::getInstance()->row--;
      break;
    case PathPlanner::WEST:
      Robot::getInstance()->col--;
      break;
  }
}

void Robot::decrementPosition(){
  switch(direction){
    case PathPlanner::NORTH:
      Robot::getInstance()->row--;
      break;
    case PathPlanner::EAST:
      Robot::getInstance()->col--;
      break;
    case PathPlanner::SOUTH:
      Robot::getInstance()->row++;
      break;
    case PathPlanner::WEST:
      Robot::getInstance()->col++;
      break;
  }
}
