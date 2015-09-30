#include "LineSensor.h"
#include <Arduino.h>

void LineSensor::setup(){
 digitalWrite(LEDPIN,HIGH);
}

void LineSensor::setMinMax(int minVal, int maxVal){
  this->min_intensity = minVal - PADDING;
  this->max_intensity = maxVal + PADDING;
}

int LineSensor::calibratingValue(){
  int val = analogRead(LineSensor::PIN_0);
  val += analogRead(LineSensor::PIN_0+1);
  val += analogRead(LineSensor::PIN_0+2);
  return val/3;
}

void LineSensor::cache(){
  for (int i=PIN_0;i<PIN_0 + 8;i++){
    int raw = analogRead(i);
    int tmp = raw_vals[i];
    int tmp2 = raw_vals[2*i];
    raw_vals[i] = raw;
    raw_vals[2*i] = tmp;
    raw_vals[3*i] = tmp2;
  }
}

int LineSensor::avgSet(int offset){
  int sum=0;
  for (int j=0,p=LineSensor::PIN_0 + offset;j<3;p++,j++){
    sum += raw_vals[p];
  }
  int avg = sum/3;
  return scale(avg);
}

int LineSensor::scale(int avg) {
  // long because this value could be greater than the largest int (2^15-1)
  long fullDiff = 200l * (avg - min_intensity); //200l means 200, as a long type
  long scaledDiff = fullDiff / (max_intensity - min_intensity);
  //should be safe to cast to int now
  return (int)scaledDiff - 100;
}

int LineSensor::avgLeftIntensity(){
  //int leftAvg = avgSet(5); //avg of 5,6,7
  int avg = (raw_vals[6] + raw_vals[7])/2;
  int leftAvg = scale(avg);
  return leftAvg;
}

int LineSensor::avgRightIntensity(){
  //int rightAvg = avgSet(0); //avg of 0,1,2
  int avg = (raw_vals[1] + raw_vals[2])/2;
  int rightAvg = scale(avg);
  return rightAvg;
}

bool LineSensor::atIntersection(){
 return rightSideOnLine() && leftSideOnLine();
}

bool LineSensor::onLine(){
  return rightSideOnLine() || leftSideOnLine();
}

bool LineSensor::rightSideOnLine(){
  return avgRightIntensity() > ON_THRESHOLD;
}

bool LineSensor::leftSideOnLine(){
  return avgLeftIntensity() > ON_THRESHOLD;
}

bool LineSensor::rightSideOffLine(){
  return avgRightIntensity() < OFF_THRESHOLD;
}

bool LineSensor::leftSideOffLine(){
  return avgLeftIntensity() < OFF_THRESHOLD;
}
