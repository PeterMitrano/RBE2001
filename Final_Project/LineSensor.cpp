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

bool LineSensor::onLine(){
  Serial.print("on? =");
  Serial.println(linePosition);
  return linePosition > ON_THRESHOLD;
}

bool LineSensor::offLine(){
  Serial.print("off? =");
  Serial.println(linePosition);
  return linePosition < OFF_THRESHOLD;
}
