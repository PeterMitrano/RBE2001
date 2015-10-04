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
  Serial.println(linePosition);
}

bool LineSensor::atIntersection(){
  Serial.println(sum);
  return sum > INTERSECTION_THRESHOLD;
}

bool LineSensor::onLine(){
  return abs(linePosition) < ON_THRESHOLD;
}

bool LineSensor::offLine(){
  return abs(linePosition) > OFF_THRESHOLD;
}
