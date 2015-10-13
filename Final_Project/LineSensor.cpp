#include "LineSensor.h"
#include "Robot.h"
#include <Arduino.h>

unsigned char LineSensor::PINS[] = {A0, A1, A2, A3, A4, A5, A6, A7};

LineSensor::LineSensor() :
  sensor(PINS, NUM_SENSORS, TIMEOUT, LEDPIN){
}

void LineSensor::setup(){
 digitalWrite(LEDPIN,HIGH);
}

void LineSensor::cache(){
  //dividing by half of max line sensor values makes linePosition = 0 when we're centered
  linePosition = sensor.readLine(rawValues) - ((NUM_SENSORS - 1 ) * 1000 / 2);
  sum = 0;
  for (int i=0;i<NUM_SENSORS;i++){
    sum += rawValues[i];
  }
}

void LineSensor::calibrateLineSensors(){
  sensor.calibrate();
}

bool LineSensor::notAtIntersection(){
  return sum < NO_INTERSECTION_THRESHOLD;
}

bool LineSensor::atIntersection(){
  return sum > INTERSECTION_THRESHOLD;
}

bool LineSensor::lineFarLeft(){
  return linePosition > LEFT_THRESHOLD;
}

bool LineSensor::lineFarRight(){
  return linePosition < RIGHT_THRESHOLD;
}

int LineSensor::adjustmentPower(){
  derivative = linePosition - lastLinePosition;
  int val = kP * linePosition + kD * derivative;
  lastLinePosition = linePosition;
  return val;
}

bool LineSensor::onLine(){
  return abs(linePosition) < ON_POS_THRESHOLD;
}
