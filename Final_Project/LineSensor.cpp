#include "LineSensor.h"
#include <Arduino.h>

void LineSensor::setup(){
  for (int i=LineSensor::PIN_0;i<8;i++){
    pinMode(i,INPUT);
  }
  digitalWrite(LEDPIN,HIGH);
}

void LineSensor::setMinMax(int minVal, int maxVal){
  this->min_intensity = minVal;
  this->max_intensity = maxVal;
}

int LineSensor::calibratingValue(){
  int val = analogRead(LineSensor::PIN_0);
  val += analogRead(LineSensor::PIN_0+1);
  val += analogRead(LineSensor::PIN_0+2);
  return val/3;
}

int LineSensor::avgSet(int offset){
  int sum=0;
  for (int j=0,i=LineSensor::PIN_0 + offset;j<3;i++,j++){
    int raw = analogRead(i);
    sum += raw;
  }
  int avg = sum/3;
  // long because this value could be greater than the largest int (2^15-1)
  long fullDiff = 200 * (avg - min_intensity);
  long scaledDiff = fullDiff / (max_intensity - min_intensity);
  //should be safe to cast to int now
  int normalizedAvg = (int)scaledDiff - 100;
  return normalizedAvg;
}

int LineSensor::avgLeftIntensity(){
  int leftAvg = avgSet(5); //avg of 5,6,7
  return leftAvg;
}

int LineSensor::avgRightIntensity(){
  int rightAvg = avgSet(0); //avg of 0,1,2
  return rightAvg;
}

bool LineSensor::atIntersection(){
 return rightSideOnLine() && leftSideOnLine();
}

bool LineSensor::onLine(){
  return rightSideOnLine() || leftSideOnLine();
}

bool LineSensor::rightSideOnLine(){
  return avgRightIntensity() < THRESHOLD;
}

bool LineSensor::leftSideOnLine(){
  return avgLeftIntensity() < THRESHOLD;
}

