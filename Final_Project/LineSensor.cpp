#include "LineSensor.h"
#include "Robot.h"
#include <Arduino.h>

LineSensor::LineSensor(){
  for (int i=0;i<8;i++){
    limits[i][0] = 1000;
    limits[i][1] = -1000;
  }
}

void LineSensor::setup(){
 digitalWrite(LEDPIN,HIGH);
}

void LineSensor::cache(){
  sum = 0;
  int wsum = 0;
  for (int j = 0, i = PIN_0; i < PIN_0 + 8; i++, j++){
    //number 3 is broken, so ignore it and it's complement
    if (i != 3){

     //scale the value to -100<x<100
     int scaled = scale(analogRead(i), i);
     sum += scaled;
     wsum += scaled*(i-4);
    }
  }
  linePosition = wsum /((float) sum);
}

int LineSensor::scale(int sensorValue, int sensorPosition){
  int min = limits[sensorPosition][0];
  int max = limits[sensorPosition][1];

  return map(sensorValue, min, max, -100, 100);
}

void LineSensor::calibrateLineSensors(){
  //read the raw values
  for (int i = PIN_0; i < PIN_0 + 8; i++){
    int raw = analogRead(i);
    limits[i][0] = raw < limits[i][0] ? raw : limits[i][0];
    limits[i][1] = raw > limits[i][1] ? raw : limits[i][1];
  }
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
