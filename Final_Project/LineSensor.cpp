#include "LineSensor.h"
#include <Arduino.h>

void LineSensor::setup(){
 digitalWrite(LEDPIN,HIGH);
}

void LineSensor::cache(){
  sum = 0;
  int wsum = 0;
  for (int i=PIN_0;i<PIN_0 + 8;i++){
    if (i != 3){
     int raw = analogRead(i);
     sum += raw;
     wsum += raw*(i-4);
    }
  }
  linePosition = wsum /((float) sum) + COMPENSATION;
}

bool LineSensor::atIntersection(){
  return sum > INTERSECTION_THRESHOLD;
}

int LineSensor::adjustmentPower(){
  derivative = linePosition - lastLinePosition;
  int val = kP * linePosition + kD * derivative;
  lastLinePosition = linePosition;
  return val;
}

bool LineSensor::onLine(){
  return abs(linePosition) < ON_POS_THRESHOLD &&
    (sum > LOW_SUM_THRESHOLD && sum < HIGH_SUM_THRESHOLD);
}

bool LineSensor::offLine(){
  return abs(linePosition) > OFF_POS_THRESHOLD &&
    (sum > HIGH_SUM_THRESHOLD || sum < LOW_SUM_THRESHOLD);
}
