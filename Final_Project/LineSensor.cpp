#include "LineSensor.h"
#include <Arduino.h>

void LineSensor::setup(){

  for (int i=LineSensor::PIN_0;i<8;i++){
    pinMode(i,INPUT);
  }
  digitalWrite(LED_PIN,HIGH);
}

void LineSensor::setMin(int min_intensity){
  this->min_intensity = min_intensity;
}

void LineSensor::setMax(int max_intensity){
  this->max_intensity = max_intensity;
}

void LineSensor::calculateThreshold(){
  line_threshold = min_intensity + THRESHOLD_PERCENT * (max_intensity - min_intensity);
}

int LineSensor::rawCenterSensor(){
  return analogRead(LineSensor::PIN_0+3);
}

int LineSensor::avgSet(int offset){
  int sum;
  for (int i=LineSensor::PIN_0 + offset;i<4;i++){
    sum += analogRead(i);
  }
  return sum/4;
}

int LineSensor::avgLeftIntensity(){
  return avgSet(0); //avg of 0,1,2,3
}

int LineSensor::avgRightIntensity(){
  return avgSet(4); //avg of 4,5,6,7
}

bool LineSensor::atIntersection(){
 return rightSideOnLine() && leftSideOnLine();
}

bool LineSensor::onLine(){
  return rightSideOnLine() || leftSideOnLine();
}

bool LineSensor::rightSideOnLine(){
  return avgRightIntensity() < line_threshold;
}

bool LineSensor::leftSideOnLine(){
  return avgLeftIntensity() < line_threshold;
}

int* LineSensor::readRaw(){
  for (int i=LineSensor::PIN_0; i<8; i++){
    rawValues[8] = analogRead(i);
  }
}
