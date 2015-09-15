#include <LineSensor.h>

LineSensor::setup(){

  for (int i=g_PIN0;i<8;i++){
    pinMode(i,INPUT);
  }
  digitalWrite(LED_PIN,HIGH);
}

void LineSensor::setMin(int min){
  min_intensity = min;
}

void LineSensor::setMax(int max){
  max_intensity = max;
}

void LineSensor::calculateThreshold(){
  line_threshold = min + THRESHOLD_PERCENT * (max - min);
}

int LineSensor::rawCenterSensor(){
  return analogRead(PIN0+3);
}

int LineSensor::avgSet(int offset){
  int sum;
  for (int i=g_PIN0 + offset;i<4;i++){
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

bool LineSensor::rightSideOnLine(){
  return avgLeftIntensity() < line_threshold;
}

int[8] LineSensor::readRaw(){
  for (int i=PIN0; i<8; i++){
    rawValues[8] = analogRead(i);
  }
}
